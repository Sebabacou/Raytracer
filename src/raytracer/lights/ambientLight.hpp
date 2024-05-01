/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ambientLight
*/

#ifndef AMBIENTLIGHT_HPP_
#define AMBIENTLIGHT_HPP_

#include <rtx.hpp>
#include <lights/light.hpp>

namespace raytracer {

    class AmbientLight : public ILight {
        public:
            AmbientLight(rtx::vec3 color)
                : _color(color) {};
            ~AmbientLight() = default;

            bool directLight(World &world, HitData &data, rtx::color &color) override;

        private:
            rtx::vec3 _color;
    };
}

#endif /* !AMBIENTLIGHT_HPP_ */
