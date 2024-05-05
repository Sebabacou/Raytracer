/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** solidColor
*/

#ifndef SOLIDCOLOR_HPP_
#define SOLIDCOLOR_HPP_

#include "texture.hpp"

namespace raytracer {
    class SolidColor : public ITexture {
      public:
        SolidColor() = default;
        SolidColor(const rtx::color &color) : _color(color) {}
        ~SolidColor() = default;

        rtx::color value(float u, float v, const rtx::point3 &p) const override { return _color; }

      private:
        rtx::color _color;
    };
}    // namespace raytracer

#endif /* !SOLIDCOLOR_HPP_ */
