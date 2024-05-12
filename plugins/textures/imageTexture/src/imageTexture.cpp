/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** checkTexture
*/

#include "imageTexture.hpp"

namespace raytracer {
    rtx::color ImageTexture::value(float u, float v, const rtx::point3 &/* p */) const
    {
        if (!_loaded)
            return rtx::color(0, 0, 0);
        u = rtx::range(0.0f, 1.0f).clamp(u);
        v = 1.0f - rtx::range(0.0f, 1.0f).clamp(v);
        auto i = u * _image.getSize().x;
        auto j = v * _image.getSize().y;
        i = rtx::range(0.0f, _image.getSize().x - 1).clamp(i);
        j = rtx::range(0.0f, _image.getSize().y - 1).clamp(j);
        auto color = _image.getPixel(i, j);

        float colors = 1 / 255.0f;
        return rtx::color(color.r * colors, color.g * colors, color.b * colors);
    }
}

extern "C" {
    raytracer::ITexture *factory(raytracer::Object &object)
    {
        std::cout << "Creating image texture" << std::endl;
        std::string path;

        try {
            path = object.getParam("path");
        } catch (const std::exception &e) {}

        return new raytracer::ImageTexture(path);
    }
    std::string getName()
    {
        return "ImageTexture";
    }
}
