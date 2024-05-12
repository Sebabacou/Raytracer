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
            PointLight() : _position(rtx::vec3(0, 0, 0)), _color(rtx::vec3(0, 0, 0)) {};
            PointLight(rtx::vec3 position, rtx::vec3 color)
                : _position(position), _color(color) {};
            ~PointLight() = default;

            bool directLight(World &world, HitData &data, rtx::color &color) override;

            void setName(const std::string &name) override { _name = name; }
            std::string getName() const override { return _name; }

        private:
            rtx::vec3 _position;
            rtx::vec3 _color;
            std::string _name;
    };
}

#endif /* !POINTLIGHT_HPP_ */
