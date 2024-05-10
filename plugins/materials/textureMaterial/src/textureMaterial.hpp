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
#include <memory>

namespace raytracer {
    class TextureMaterial : public IMaterial {
        public:
            // TextureMaterial(const rtx::vec3 &a) : _albedo(std::make_shared<SolidColor>(a)) {}
            TextureMaterial(std::shared_ptr<ITexture> a) : _albedo(a) {}
            bool scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const override;

        private:
            std::shared_ptr<ITexture> _albedo;
    };
}

#endif /* !LAMBERTIAN_HPP_ */
