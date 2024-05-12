/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** pointLight
*/

#include "pointLight.hpp"

namespace raytracer {

    bool PointLight::directLight(World &/* world */, HitData &/* data */, rtx::color &/* color */)
    {
        return false;
    }
}

extern "C" {
    raytracer::ILight *factory()
    {
        return new raytracer::PointLight();
    }
}
