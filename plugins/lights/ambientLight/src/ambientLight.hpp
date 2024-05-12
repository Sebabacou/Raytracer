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
#include <parser/Object.hpp>

namespace raytracer {

    class AmbientLight : public ILight {
        public:
            AmbientLight(rtx::vec3 color)
                : _color(color) {};
            ~AmbientLight() = default;

            bool directLight(World &world, HitData &data, rtx::color &color) override;

            void setName(const std::string &name) override { _name = name; }
            std::string getName() const override { return _name; }

        private:
            rtx::vec3 _color;
            std::string _name;
    };
}

#endif /* !AMBIENTLIGHT_HPP_ */
