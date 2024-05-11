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

extern "C" {
    raytracer::ITexture *factory(raytracer::Object &object)
    {
        std::cout << "Creating solid color texture" << std::endl;
        return new raytracer::SolidColor();
    }
    std::string getName()
    {
        return "SolidColor";
    }
}
