/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** light
*/

#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include <rtx.hpp>
#include <hitData.hpp>

namespace raytracer {

    class World;
    class ILight {
        public:
            ILight() = default;
            ~ILight() = default;

            virtual bool directLight(World &world, HitData &data, rtx::color &color) = 0;
        protected:
        private:
            rtx::vec3 _position;
    };
}

#endif /* !LIGHT_HPP_ */
