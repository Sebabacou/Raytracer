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

        void setName(const std::string &name) override { _name = name; }
            std::string getName() const override { return _name; }
      private:
        float _size = 0.5f;
        rtx::color _color;
        std::string _name;
    };
}

#endif /* !SOLIDCOLOR_HPP_ */
