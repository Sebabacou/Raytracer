/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** pointLight
*/

#ifndef POINTLIGHT_HPP_
#define POINTLIGHT_HPP_

#include <rtx.hpp>
#include <lights/light.hpp>

namespace raytracer {

    class PointLight : public ILight {
        public:
            PointLight(rtx::vec3 position, rtx::vec3 color, float radius = 0.0f)
                : _position(position), _color(color) {};
            ~PointLight() = default;

            bool directLight(World &world, HitData &data, rtx::color &color) override;

        private:
            rtx::vec3 _position;
            rtx::vec3 _color;
    };
}

#endif /* !POINTLIGHT_HPP_ */
