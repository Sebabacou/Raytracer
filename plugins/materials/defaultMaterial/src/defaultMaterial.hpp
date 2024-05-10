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
#include <textures/solidColor.hpp>

namespace raytracer {
    class DefaultMaterial : public IMaterial {
        public:
            DefaultMaterial();

            bool scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const override;

        private:
            std::shared_ptr<ITexture> _albedo;
    };
}

#endif /* !LAMBERTIAN_HPP_ */
