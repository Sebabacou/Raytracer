/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** camera
*/

#include "camera.hpp"

namespace raytracer {
    void Camera::reset() {
        _pos = rtx::point3(0, 0, 0);
        _lookAt = rtx::point3(0, 0, -1);
        setup();
    }

    void Camera::setup() {
        rtx::point3 _viewportRealOrigin;
        rtx::vec3 xB;
        rtx::vec3 yB;
        rtx::vec3 zB;
        float theta, h;

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

    rtx::color Camera::rayColor(const rtx::ray &r, World &world, int depth)
    {
        HitData data;
        rtx::ray scattered;
        rtx::vec3 attenuation;

        if (depth >= _maxDepth)
            return rtx::color(0, 0, 0);
        if (world.hit(r, data) > 0) {
            // rtx::vec3 randVec = rtx::vec3::correctRandom();
            // // randVec = (data.normal.dot(randVec) < 0) ? -randVec : randVec;
            // rtx::point3 target = data.normal + randVec;

            if (data.mat->scatter(r, data, attenuation, scattered))
                return attenuation * rayColor(scattered, world, depth + 1);
            return rtx::color(0, 0, 0);
        }
        rtx::vec3 unit_direction = r._direction;
        float t = 0.5 * (unit_direction.y + 1.0);
        return (1.0 - t) * rtx::color(1.0, 1.0, 1.0) + t * rtx::color(0.5, 0.7, 1.0);
        // return rtx::color(0, 0, 0);
    }

    rtx::color Camera::rayWithAntialiasing(int i, int j, World &world)
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

    rtx::pixel Camera::pixelAt(int i, int j, World &world)
    {
        rtx::point3 pixel;
        rtx::ray r;

        if (_antialiasing)
            return rayWithAntialiasing(i, j, world);
        pixel = _viewportOrigin + j * _pixelU + i * _pixelV;
        r = rtx::ray(_pos, pixel - _pos);
        return rayColor(r, world, 0);

    }

    void Camera::render(World &world, rtx::screen &image)
    {
        image.setSize(_width, _height);
        rtx::loading loading(_height);

        int numThreads = std::thread::hardware_concurrency() - 2;

        for (int i = 0; i < _height; i++) {
            for (int j = 0; j < _width; j++)
                image[i][j] = pixelAt(i, j, world);
            loading.displayLoading(i);
        }
        std::cout << std::endl;
    }

    void Camera::render(World &world, rtx::screen &image, rtx::range xRange, rtx::range yRange)
    {
        image.setSize(_width, _height);
        rtx::loading loading(yRange._max - yRange._min);

        for (int i = yRange._min; i < yRange._max; i++) {
            for (int j = xRange._min; j < xRange._max; j++)
                image[i][j] = pixelAt(i, j, world);
            loading.displayLoading(i - yRange._min);
        }
        std::cout << std::endl;
    }

    std::ostream &operator<<(std::ostream &os, Camera &c) {
        os << "Camera(origin: " << c.origin()
           << ", viewport_origin: " << c.viewportOrigin() << ", pixel_u: "
           << c.pixelU() << ", pixel_v: " << c.pixelV() << ")";
        return os;
    }
}