/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** metal.cpp
*/

#include "metal.hpp"

namespace raytracer {

    Metal::Metal(const rtx::vec3 &a) : albedo(a) {}

    bool Metal::scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const
    {
        rtx::vec3 reflected = r._direction.reflect(data.normal);
        scattered = rtx::ray(data.p, reflected);
        attenuation = albedo;
        return true;
    }

}

extern "C" {
    raytracer::IMaterial *factory()
    {
        return new raytracer::Metal(rtx::vec3(0.8, 0.6, 0.2));
    }
    std::string getName()
    {
        return "Metal";
    }
}