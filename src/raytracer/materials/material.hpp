/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** mat
*/

#ifndef MAT_HPP_
#define MAT_HPP_

#include <rtx.hpp>

namespace raytracer {

    class HitData;

    class IMaterial {
        public:
            IMaterial() = default;
            ~IMaterial() = default;
            virtual bool scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const = 0;

    };
}

#endif /* !MAT_HPP_ */
