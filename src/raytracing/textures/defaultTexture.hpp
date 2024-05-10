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
    class DefaultTexture : public ITexture {
      public:
        DefaultTexture() {};
        ~DefaultTexture() = default;

        rtx::color value(float u, float v, const rtx::point3 &p) const override {
          auto sines = sin(_size * p.x) * sin(_size * p.y) * sin(_size * p.z);
          if (sines < 0)
              return rtx::color(0, 0, 0);
          else
              return rtx::color(255, 0, 255);
        }

      private:
        float _size = 2;
        rtx::color _color;
    };
}

#endif /* !SOLIDCOLOR_HPP_ */
