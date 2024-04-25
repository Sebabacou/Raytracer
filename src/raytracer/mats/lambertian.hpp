/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** lambertian
*/

#ifndef LAMBERTIAN_HPP_
#define LAMBERTIAN_HPP_

#include <mats/mat.hpp>

namespace raytracer {
    class Lambertian : public Mat {
        public:
            Lambertian(const rtx::vec3 &a) : _albedo(a) {}
            bool scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const override
            {
                rtx::vec3 scatterDir = data.normal + rtx::vec3::correctRandom();
                float tolerance = 1e-6;
                if (scatterDir.isZero())
                    scatterDir = data.normal;
                scattered = rtx::ray(data.p, scatterDir);
                attenuation = _albedo;
                return true;
            }

        private:
            rtx::vec3 _albedo;
    };
}

#endif /* !LAMBERTIAN_HPP_ */
