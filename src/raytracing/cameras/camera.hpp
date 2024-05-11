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
#include <thread>
#include <mutex>
#include <atomic>
#include <ctime>

namespace raytracer {

    class ICamera {
        public:
            ICamera() = default;
            ~ICamera() = default;

            virtual void render(World &world, rtx::screen &image) = 0;
            virtual void render(World &world, rtx::screen &image, rtx::range xRange, rtx::range yRange) = 0;
        protected:
        private:
    };
}

#endif /* !CAMERA_HPP_ */
