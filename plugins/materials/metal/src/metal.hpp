/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** metal
*/

#ifndef METAL_HPP_
#define METAL_HPP_

#include <materials/material.hpp>

namespace raytracer {

    class Metal : public IMaterial {
        public:
            Metal(const rtx::vec3 &a);
            bool scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const override;

            rtx::vec3 albedo;
    };
}

#endif /* !METAL_HPP_ */
