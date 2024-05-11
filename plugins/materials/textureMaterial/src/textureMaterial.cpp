/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** textureMaterial
*/

#include "textureMaterial.hpp"

namespace raytracer {
    bool TextureMaterial::scatter(const rtx::ray &r, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const
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
    raytracer::IMaterial *factory(raytracer::Object &object, std::vector<std::shared_ptr<raytracer::ITexture>> textures)
    {
        std::cout << "Creating texture material" << std::endl;
        return new raytracer::TextureMaterial();
    }

    std::string getName()
    {
        return "TextureMaterial";
    }
}