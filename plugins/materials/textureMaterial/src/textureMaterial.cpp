/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** textureMaterial
*/

#include "textureMaterial.hpp"

namespace raytracer {
    bool TextureMaterial::scatter(const rtx::ray &/* r */, HitData &data, rtx::vec3 &attenuation, rtx::ray &scattered) const
    {
        rtx::vec3 scatterDir = data.normal + rtx::vec3::correctRandom();

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
        std::shared_ptr<raytracer::ITexture> albedo = std::make_shared<raytracer::DefaultTexture>();

        try {
            std::string textureName = object.getParam("texture");
            for (auto &texture : textures) {
                if (texture->getName() == textureName) {
                    albedo = texture;
                    break;
                }
            }
        } catch (const std::exception &e) {}

        return new raytracer::TextureMaterial(albedo);
    }

    std::string getName()
    {
        return "TextureMaterial";
    }
}