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

namespace raytracer {
    class DefaultMaterial : public IMaterial {
        public:
            DefaultMaterial() : _albedo(std::make_shared<DefaultTexture>()) {}

            bool scatter(const rtx::ray &/* r */, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const
            {
                rtx::vec3 scatterDir = data.normal + rtx::vec3::correctRandom();

                if (scatterDir.isZero())
                    scatterDir = data.normal;
                scattered = rtx::ray(data.p, scatterDir);
                attenuation = _albedo->value(data.u, data.v, data.p);
                return true;
            }

            void setName(const std::string &name) override { _name = name; }
            std::string getName() const override { return _name; }

        private:
            std::shared_ptr<ITexture> _albedo;
            std::string _name;
    };
}

#endif /* !LAMBERTIAN_HPP_ */
