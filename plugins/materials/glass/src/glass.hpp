/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** dielectric
*/

#ifndef DIELECTRIC_HPP_
#define DIELECTRIC_HPP_

#include <materials/material.hpp>

namespace raytracer {
    class Glass : public IMaterial {
        public:
            Glass(double ri);
            ~Glass() = default;
            bool scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const override;

            double _refIdx;
    };
}


#endif /* !DIELECTRIC_HPP_ */
