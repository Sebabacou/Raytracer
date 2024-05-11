/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** solidColor
*/

#ifndef SOLIDCOLOR_HPP_
#define SOLIDCOLOR_HPP_

#include <textures/texture.hpp>
#include <parser/Object.hpp>

namespace raytracer {
    class SolidColor : public ITexture {
      public:
        SolidColor() : _color(rtx::color(0, 0, 0)) {}
        SolidColor(const rtx::color &color) : _color(color) {}
        ~SolidColor() = default;

        rtx::color value(float u, float v, const rtx::point3 &p) const override;

      private:
        rtx::color _color;
    };
}    // namespace raytracer

#endif /* !SOLIDCOLOR_HPP_ */
