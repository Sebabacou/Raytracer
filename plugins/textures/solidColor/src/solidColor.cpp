/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** solidColor
*/

#include "solidColor.hpp"

namespace raytracer {
    rtx::color SolidColor::value(float u, float v, const rtx::point3 &p) const
    {
        return _color;
    }
}
