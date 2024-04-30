/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** directionalLight
*/

#include "directionalLight.hpp"

namespace raytracer {
    bool DirectionalLight::directLight(World &world, HitData &data)
    {
        rtx::vec3 lightDir = -_direction;
        rtx::ray shadowRay(data.hitPoint, lightDir);
        HitData shadowData;

        if (world.hit(shadowRay, shadowData) && shadowData.t < rtx::length(lightDir))
            return false;
        data.color += _color;
        return true;
    }
}