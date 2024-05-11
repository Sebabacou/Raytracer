/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** checkTexture
*/

#include "checkTexture.hpp"

namespace raytracer {
    rtx::color CheckTexture::value(float u, float v, const rtx::point3 &p) const
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
        return new raytracer::CheckTexture();
    }
    std::string getName()
    {
        return "CheckTexture";
    }
}
