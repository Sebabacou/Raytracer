/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <rtx.hpp>
#include <world.hpp>

namespace raytracer {

    class Camera {
        public:
            Camera() :
                _pos(rtx::point3(0, 0, 0)), _lookAt(rtx::point3(0, 0, -1)),
                _ratio(16.0f / 9.0f), _width(800), _fov(90.0f) {
                setup();
            }
            Camera(rtx::point3 pos, rtx::point3 lookAt, int width, float ratio, float fov) :
                _pos(pos), _lookAt(lookAt),
                _ratio(ratio), _width(width), _fov(fov) {
                setup();
            }
            Camera(rtx::point3 pos, rtx::point3 lookAt, int width) :
                _pos(pos), _lookAt(lookAt),
                _ratio(16.0f / 9.0f), _width(width), _fov(90.0f) {
                setup();
            }
            Camera(const Camera &c) {
                _pos = c._pos;
                _lookAt = c._lookAt;
                _ratio = c._ratio;
                _width = c._width;
                _fov = c._fov;
                setup();
            }
            ~Camera() = default;

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

            rtx::pixel pixelAt(int i, int j, World &world);
            rtx::color rayWithAntialiasing(int i, int j, World &world);
            rtx::color rayColor(const rtx::ray &r, World &world, int depth);
            void render(World &world, rtx::screen &image);
            void render(World &world, rtx::screen &image, rtx::range xRange, rtx::range yRange);

        private:
            float _fov = 90.0f;
            float _ratio;
            int _width;
            int _height;
            float _focalLength;
            float _viewportHeight;
            float _viewportWidth;
            rtx::point3 _pos;
            rtx::point3 _lookAt;

            rtx::point3 _viewportOrigin;
            rtx::vec3 _viewportU;
            rtx::vec3 _viewportV;
            rtx::vec3 _pixelU;
            rtx::vec3 _pixelV;

            bool _antialiasing = false;
            int _antialiasingSamples = 15;
            int _maxDepth = 75;

            void reset();
            void setup();
    };

    std::ostream &operator<<(std::ostream &os, Camera &c);
}

#endif /* !CAMERA_HPP_ */
