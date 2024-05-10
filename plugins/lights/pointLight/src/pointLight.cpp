/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** pointLight
*/

#include "pointLight.hpp"

namespace raytracer {

    bool PointLight::directLight(World &world, HitData &data, rtx::color &color)
    {
        // rtx::vec3 lightDir = _position - data.hitPoint;
        // float distance = lightDir.length();
        // lightDir = lightDir.normalize();
        // Ray shadowRay(data.hitPoint + lightDir * 0.001f, lightDir);
        // HitData shadowHit;
        // if (world.hit(shadowRay, shadowHit) && shadowHit.distance < distance) {
        //     return false;
        // }
        // float attenuation = 1.0f / (distance * distance);
        // color = _color * attenuation;
        // return true;
    }
}

extern "C" {
    raytracer::ILight *factory(rtx::vec3 position, rtx::vec3 color, float radius)
    {
        return new raytracer::PointLight(position, color, radius);
    }
}
