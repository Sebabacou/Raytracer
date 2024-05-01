/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** directionalLight
*/

#include "directionalLight.hpp"

namespace raytracer {
    bool DirectionalLight::directLight(World &world, HitData &data, rtx::color &color)
    {
        rtx::vec3 lightDir = -_direction;
        rtx::ray shadowRay(data.p, lightDir);
        HitData shadowData;
        rtx::color light;

        if (world.hit(shadowRay, shadowData) > 0)
            return false;
        float intensity = std::max(0.f, data.normal.dot(lightDir));
        color = _color * intensity;
        return true;
    }
}