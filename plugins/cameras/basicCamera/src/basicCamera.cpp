/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** camera
*/

#include "basicCamera.hpp"

namespace raytracer {
    void BasicCamera::reset() {
        _pos = rtx::point3(2, 2, 0);
        _lookAt = rtx::point3(0, 0, 0);
        setup();
    }

    void BasicCamera::setup() {
        rtx::point3 _viewportRealOrigin;
        rtx::vec3 xB;
        rtx::vec3 yB;
        rtx::vec3 zB;
        float theta, h;

        _nbThreads = std::thread::hardware_concurrency() * 2;
        _height = int(_width / _ratio);
        _height = (_height < 1) ? 1 : _height;

        _focalLength = (_pos - _lookAt).norm();

        xB = (_pos - _lookAt).normalize();
        yB = (rtx::vec3(0, 1, 0)).cross(xB).normalize();
        zB = xB.cross(yB);

        theta = rtx::degToRad(_fov);
        h = tan(theta / 2);
        _viewportHeight = 2.0f * h * _focalLength;
        _viewportWidth = _ratio * _viewportHeight;

        _viewportU = _viewportWidth * yB;
        _viewportV = _viewportHeight * -zB;
        _pixelU = _viewportU / _width;
        _pixelV = _viewportV / _height;

        _viewportRealOrigin = _pos
            - _viewportU / 2 - _viewportV / 2
            - _focalLength * xB;
        _viewportOrigin = _viewportRealOrigin
            + _pixelU / 2 + _pixelV / 2;
    }

    rtx::color BasicCamera::rayColor(const rtx::ray &r, World &world, int depth)
    {
        HitData data;
        rtx::ray scattered;
        rtx::vec3 attenuation;
        rtx::vec3 emittion;
        rtx::color color(0, 0, 0);
        rtx::color lightColor;
        rtx::color totalLightColor;


        if (depth >= _maxDepth)
            return rtx::color(0, 0, 0);
        if (world.hit(r, data) > 0) {
            emittion = data.mat->emitted(data.u, data.v, data.p);
            if (data.mat->scatter(r, data, attenuation, scattered)) {
                if (rtx::randomFloat(0, 1) < 0.1) {
                    for (auto &light : world.lights()) {
                        if (light->directLight(world, data, lightColor)) {
                            totalLightColor += lightColor;
                        }
                    }
                    return totalLightColor * attenuation;
                }
                color = attenuation * (rayColor(scattered, world, depth + 1));
            }
            return color + emittion;
        }
        return _background;
    }

    rtx::color BasicCamera::rayWithAntialiasing(int i, int j, World &world)
    {
        rtx::color color(0, 0, 0);
        rtx::point3 pixel;
        rtx::ray r;
        float offsetX;
        float offsetY;

        for (int sample = 0; sample < _antialiasingSamples; sample++) {
            offsetX = rtx::randomFloat(0, 1) - 0.5;
            offsetY = rtx::randomFloat(0, 1) - 0.5;
            pixel = _viewportOrigin + (j + offsetX) * _pixelU + (i + offsetY) * _pixelV;
            r = rtx::ray(_pos, pixel - _pos);
            color += rayColor(r, world, 0);
        }
        return color / _antialiasingSamples;
    }

    rtx::pixel BasicCamera::pixelAt(int i, int j, World &world)
    {
        rtx::point3 pixel;
        rtx::ray r;

        if (_antialiasing && !_previewMode)
            return rayWithAntialiasing(i, j, world);
        pixel = _viewportOrigin + j * _pixelU + i * _pixelV;
        r = rtx::ray(_pos, pixel - _pos);
        return rayColor(r, world, 0);

    }

    void BasicCamera::renderThread(World &world, rtx::screen &image, rtx::range xRange, rtx::range yRange)
    {
        for (int i = yRange._min; i < yRange._max; i++) {
            for (int j = xRange._min; j < xRange._max; j++) {
                image[i][j] = pixelAt(i, j, world);
            }
            std::lock_guard<std::mutex> lock(_mutex);
            _progress += xRange._max - xRange._min;
            int pourcent = (int)((float)_progress / (_width * _height) * 100);
            std::cout << "\rRender: ";
            if (pourcent < 10)
                std::cout << " ";
            if (pourcent < 100)
                std::cout << " ";
            std::cout << pourcent + 1 << "%" << std::flush;
        }
    }

    void BasicCamera::render(World &world, rtx::screen &image)
    {
        image.setSize(_width, _height);

        time_t start = time(0);

        if (_nbThreads < 1)
            _nbThreads = 1;
        int root = (int)sqrt(_nbThreads);
        int xRange = _width / root;
        int yRange = _height / root;
        std::vector<std::thread> threads;
        for (int i = 0; i < root; i++) {
            for (int j = 0; j < root; j++) {
                rtx::range xR(j * xRange, (j + 1) * xRange);
                rtx::range yR(i * yRange, (i + 1) * yRange);
                threads.push_back(std::thread(&BasicCamera::renderThread, this, std::ref(world), std::ref(image), xR, yR));
            }
        }
        for (int i = 0; i < (int)threads.size(); i++) {
            threads[i].join();
        }
        std::cout << std::endl;
        std::cout << "Render time: " << time(0) - start << "s" << std::endl;
    }
}

extern "C" {
    raytracer::ICamera *factory(raytracer::Object &object)
    {
        std::cout << "Creating BasicCamera" << std::endl;
        raytracer::BasicCamera *camera = new raytracer::BasicCamera();

        try {
            camera->setPos(rtx::point3::stov3(object.getParam("position")));
        } catch (const std::exception &e) {}
        try {
            camera->setLookAt(rtx::point3::stov3(object.getParam("lookAt")));
        } catch (const std::exception &e) {}
        try {
            camera->setWidth(std::stoi(object.getParam("width")));
        } catch (const std::exception &e) {}
        try {
            camera->setRatio(std::stof(object.getParam("ratio")));
        } catch (const std::exception &e) {}
        try {
            camera->setFov(std::stof(object.getParam("fov")));
        } catch (const std::exception &e) {}
        try {
            camera->setAntialiasing(object.getParam("antialiasing") == "true");
        } catch (const std::exception &e) {}
        try {
            camera->setAntialiasingSamples(std::stoi(object.getParam("antialiasingSamples")));
        } catch (const std::exception &e) {}
        try {
            camera->setMaxDepth(std::stoi(object.getParam("maxDepth")));
        } catch (const std::exception &e) {}
        try {
            camera->setBackground(rtx::vec3::stov3(object.getParam("background")));
        } catch (const std::exception &e) {}

        return camera;
    }
    std::string getName()
    {
        return "BasicCamera";
    }
}