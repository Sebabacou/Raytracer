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
    class TextureMaterial : public IMaterial {
        public:
            TextureMaterial() {
                _albedo = std::make_shared<DefaultTexture>();
            }
            TextureMaterial(std::shared_ptr<ITexture> a) : _albedo(a) {}
            bool scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const override;

            void setName(const std::string &name) override { _name = name; }
            std::string getName() const override { return _name; }

        private:
            std::string _name;
            std::shared_ptr<ITexture> _albedo;
    };
}

#endif /* !LAMBERTIAN_HPP_ */
