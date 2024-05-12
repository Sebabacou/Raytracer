/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** checkTexture
*/

#include "checkTexture.hpp"

namespace raytracer {
    rtx::color CheckTexture::value(float /* u */, float /* v */, const rtx::point3 &p) const
    {
        auto sines = sin(_size * p.x) * sin(_size * p.y) * sin(_size * p.z);
        if (sines < 0)
            return _black;
        else
            return _white;
    }
}

extern "C" {
    raytracer::ITexture *factory(raytracer::Object &object)
    {
        std::cout << "Creating check texture" << std::endl;
        rtx::color color1;
        rtx::color color2;
        float size = 0;

        try {
            color1 = rtx::vec3::stov3(object.getParam("color1"));
            color2 = rtx::vec3::stov3(object.getParam("color2"));
        } catch (const std::exception &e) {
            color1 = rtx::color(0.2, 0.2, 0.2);
            color2 = rtx::color(0.2, 0.4, 0.2);
        }
        try {
            size = std::stof(object.getParam("size"));
        } catch (const std::exception &e) {
            size = 1;
        }



        return new raytracer::CheckTexture(color1, color2, size);
    }
    std::string getName()
    {
        return "CheckTexture";
    }
}
