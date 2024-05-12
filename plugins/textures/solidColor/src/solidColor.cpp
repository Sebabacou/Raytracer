/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** solidColor
*/

#include "solidColor.hpp"

namespace raytracer {
    rtx::color SolidColor::value(float /* u */, float /* v */, const rtx::point3 &/* p */) const
    {
        return _color;
    }
}

extern "C" {
    raytracer::ITexture *factory(raytracer::Object &object)
    {
        std::cout << "Creating solid color texture" << std::endl;
        rtx::color color;

        try {
            color = rtx::vec3::stov3(object.getParam("color"));
        } catch (const std::exception &e) {}

        return new raytracer::SolidColor(color);
    }
    std::string getName()
    {
        return "SolidColor";
    }
}
