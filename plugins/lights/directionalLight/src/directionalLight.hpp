/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** directionalLight
*/

#ifndef DIRECTIONALLIGHT_HPP_
#define DIRECTIONALLIGHT_HPP_

#include <rtx.hpp>
#include <lights/light.hpp>
#include <world.hpp>

namespace raytracer {

    class DirectionalLight : public ILight {
        public:
            DirectionalLight(rtx::vec3 direction, rtx::vec3 color)
                : _direction(direction), _color(color) {};
            ~DirectionalLight() = default;

            bool directLight(World &world, HitData &data, rtx::color &color) override;

        private:
            rtx::vec3 _direction;
            rtx::vec3 _color;
    };
}

#endif /* !DIRECTIONALLIGHT_HPP_ */
