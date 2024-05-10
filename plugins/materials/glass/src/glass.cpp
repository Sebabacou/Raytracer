/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** glass.cpp
*/

#include "glass.hpp"

namespace raytracer {

    Glass::Glass(double ri) : _refIdx(ri) {};


    bool Glass::scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const
    {
        attenuation = rtx::vec3(1.0, 1.0, 1.0);
        double etaiOverEtat = data.outside ? (1.0 / _refIdx) : _refIdx;

        rtx::vec3 dir = r._direction.normalize();

        double cosTheta = std::fmin((dir * -1).dot(data.normal), 1.0);
        double sinTheta = std::sqrt(1.0 - cosTheta * cosTheta);

        bool cannotRefract = etaiOverEtat * sinTheta > 1.0;

        float schlick;
        auto r0 = (1.0 - _refIdx) / (1.0 + _refIdx);
        r0 = r0 * r0;
        schlick = r0 + (1.0 - r0) * std::pow((1.0 - cosTheta), 5.0);

        if (cannotRefract || schlick > rtx::randomFloat()) {
            rtx::vec3 reflected = dir.reflect(data.normal);
            scattered = rtx::ray(data.p, reflected);
            return true;
        }
        rtx::vec3 refracted = dir.refract(data.normal, etaiOverEtat);
        scattered = rtx::ray(data.p, refracted);
        return true;
    }
}

extern "C" {
    raytracer::IMaterial *factory()
    {
        return new raytracer::Glass(1.5);
    }
    std::string getName()
    {
        return "Glass";
    }
}