/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** camera
*/

#ifndef PIXELCAMERACAMERA_HPP_
#define PIXELCAMERA_HPP_

#include <rtx.hpp>
#include <world.hpp>
#include <thread>
#include <mutex>
#include <atomic>
#include <ctime>
#include <cameras/camera.hpp>
#include <parser/Object.hpp>
#include <materials/material.hpp>

namespace raytracer {

    class PixelCamera : public ICamera {
        public:
            PixelCamera() {
                _pos = rtx::point3(0, 0, -5);
                _lookAt = rtx::point3(0, 0, 0);
                _width = 800;
                _ratio = 16.0f / 9.0f;
                _fov = 90.0f;
                _antialiasing = false;
                _antialiasingSamples = 0;
                setup();
            }
            PixelCamera(rtx::point3 pos, rtx::point3 lookAt, int width, float ratio, float fov) :
                _pos(pos), _lookAt(lookAt),
                _width(width), _ratio(ratio), _fov(fov) {
                setup();
            }
            PixelCamera(rtx::point3 pos, rtx::point3 lookAt, int width) :
                _pos(pos), _lookAt(lookAt),
                _width(width), _ratio(16.0f / 9.0f), _fov(90.0f) {
                setup();
            }
            PixelCamera(const PixelCamera &c) {
                _pos = c._pos;
                _lookAt = c._lookAt;
                _ratio = c._ratio;
                _width = c._width;
                _fov = c._fov;
                setup();
            }
            ~PixelCamera() = default;

            rtx::point3 origin() { return _pos; }
            rtx::point3 viewportOrigin() { return _viewportOrigin; }
            rtx::vec3 pixelU() { return _pixelU; }
            rtx::vec3 pixelV() { return _pixelV; }
            int width() { return _width; }
            int height() { return _height; }
            float fov() { return _fov; }

            void setPos(rtx::point3 pos) { _pos = pos; setup(); }
            void setLookAt(rtx::point3 lookAt) { _lookAt = lookAt; setup(); }
            void rotate(rtx::vec3 rotation) {
                _lookAt = _lookAt.rotateAroundPoint(_pos, rotation);
                setup();
            }
            void setWidth(int width) { _width = width; setup(); }
            void setRatio(float ratio) { _ratio = ratio; setup(); }
            void setFov(float fov) { _fov = fov; setup(); }
            void setAntialiasing(bool antialiasing) { _antialiasing = antialiasing; }
            void setAntialiasingSamples(int samples) { _antialiasingSamples = samples; }
            void setMaxDepth(int depth) { _maxDepth = depth; }
            void setBackground(rtx::color color) { _background = color; }
            void filterScale(float scale) { _filterScale = scale; }

            void render(World &world, rtx::screen &image, bool preview = false) override;

            std::atomic<int> _progress = 0;
            std::mutex _mutex;
            time_t _start;

            void setName(const std::string &name) override { _name = name; }
            std::string getName() const override { return _name; }
            void setNbThreads(int nbThreads) override { _nbThreads = nbThreads; }
            int getNbThreads() const override { return _nbThreads; }

        private:
            rtx::pixel pixelAt(int i, int j, World &world);
            rtx::color rayWithAntialiasing(int i, int j, World &world);
            rtx::color rayColor(const rtx::ray &r, World &world, int depth);
            void renderThread(World &world, rtx::screen &image, rtx::range xRange, rtx::range yRange);
            rtx::point3 _pos;
            rtx::point3 _lookAt;
            int _width;
            float _ratio;
            float _fov = 90.0f;
            int _height;
            float _focalLength;
            float _viewportHeight;
            float _viewportWidth;

            rtx::point3 _viewportOrigin;
            rtx::vec3 _viewportU;
            rtx::vec3 _viewportV;
            rtx::vec3 _pixelU;
            rtx::vec3 _pixelV;

            bool _antialiasing = false;
            int _antialiasingSamples = 15;
            int _maxDepth = 75;

            rtx::color _background = rtx::color(0.8, 0.8, 1);

            void reset();
            void setup();

            std::string _name;
            bool _previewMode = false;
            int _nbThreads = std::thread::hardware_concurrency();
            void filter(rtx::screen &image);
            float _filterScale = 4;
    };
}

#endif /* !CAMERA_HPP_ */
