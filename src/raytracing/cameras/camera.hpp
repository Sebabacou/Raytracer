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

            virtual void setPreviewMode(bool previewMode) = 0;
            virtual bool getPreviewMode() const = 0;

            virtual void setName(const std::string &name) = 0;
            virtual std::string getName() const = 0;

            virtual void setNbThreads(int nbThreads) = 0;
            virtual int getNbThreads() const = 0;
        protected:
        private:
    };
}

#endif /* !CAMERA_HPP_ */
