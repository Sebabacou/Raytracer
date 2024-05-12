/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ambientLight
*/

#include "ambientLight.hpp"

namespace raytracer {
    bool AmbientLight::directLight(World &/* world */, HitData &/* data */, rtx::color &color)
    {
        color = _color;
        return true;
    }
}
