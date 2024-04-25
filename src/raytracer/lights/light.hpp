/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** light
*/

#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include <rtx.hpp>
#include <world.hpp>
#include <hitData.hpp>

namespace raytracer {
    class Light {
        public:
            Light() = default;
            ~Light() = default;

            virtual bool directLight(World &world, HitData &data) = 0;
    };
}

#endif /* !LIGHT_HPP_ */
