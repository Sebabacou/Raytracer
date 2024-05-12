/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** textureMaterial
*/

#include "emissiveMaterial.hpp"

namespace raytracer {
    rtx::color EmissiveMaterial::emitted(float u, float v, const rtx::point3 &p) const
    {
        return _emit;
    }
}

extern "C" {
    raytracer::IMaterial *factory(raytracer::Object &object, std::vector<std::shared_ptr<raytracer::ITexture>> textures)
    {
        std::cout << "Creating emissive material" << std::endl;
        rtx::vec3 emit;
        try {
            emit = rtx::vec3::stov3(object.getParam("emit"));
        } catch (const std::exception &e) {
            emit = rtx::vec3(0, 0, 0);
        }
        return new raytracer::EmissiveMaterial(emit);
    }

    std::string getName()
    {
        return "EmissiveMaterial";
    }
}