/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** lambertian
*/

#ifndef LAMBERTIAN_HPP_
#define LAMBERTIAN_HPP_

#include <materials/material.hpp>
#include <textures/texture.hpp>
#include <textures/defaultTexture.hpp>
#include <parser/Object.hpp>
#include <memory>

namespace raytracer {
    class EmissiveMaterial : public IMaterial {
        public:
            EmissiveMaterial(rtx::color c) : _emit(c) {}

            rtx::color emitted(float u, float v, const rtx::point3 &p) const override;

            void setName(const std::string &name) override { _name = name; }
            std::string getName() const override { return _name; }

        private:
            std::string _name;
            rtx::color _emit;
    };
}

#endif /* !LAMBERTIAN_HPP_ */
