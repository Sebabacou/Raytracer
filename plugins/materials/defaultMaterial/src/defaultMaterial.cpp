/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** defaultMaterial.cpp
*/

#include "defaultMaterial.hpp"

namespace raytracer {

    DefaultMaterial::DefaultMaterial() : _albedo(std::make_shared<DefaultTexture>()) {}

    bool DefaultMaterial::scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const
    {
        rtx::vec3 scatterDir = data.normal + rtx::vec3::correctRandom();
        float tolerance = 1e-6;
        if (scatterDir.isZero())
        scatterDir = data.normal;
        scattered = rtx::ray(data.p, scatterDir);
        attenuation = _albedo->value(data.u, data.v, data.p);
        return true;
    }

}

extern "C" {
    raytracer::IMaterial *factory()
    {
        return new raytracer::DefaultMaterial();
    }
    std::string getName()
    {
        return "DefaultMaterial";
    }
}