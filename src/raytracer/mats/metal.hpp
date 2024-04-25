/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** metal
*/

#ifndef METAL_HPP_
#define METAL_HPP_

#include <mats/mat.hpp>

namespace raytracer {

    class Metal : public Mat {
        public:
            Metal(const rtx::vec3 &a) : albedo(a) {}
            bool scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const override
            {
                rtx::vec3 reflected = r._direction.reflect(data.normal);
                scattered = rtx::ray(data.p, reflected);
                attenuation = albedo;
                return true;
            }

            rtx::vec3 albedo;
    };
}

#endif /* !METAL_HPP_ */
