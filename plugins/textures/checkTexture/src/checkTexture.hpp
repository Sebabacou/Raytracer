/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** checkTexture
*/

#ifndef CHECKTEXTURE_HPP_
#define CHECKTEXTURE_HPP_

#include <textures/texture.hpp>
#include <rtx.hpp>

namespace raytracer {
    class CheckTexture : public ITexture {
      public:
        CheckTexture(rtx::color white, rtx::color black, float size)
          : _size(size), _black(black), _white(white) {}
        ~CheckTexture() = default;

        rtx::color value(float u, float v, const rtx::point3 &p) const override;

      private:
        float _size;
        rtx::color _black;
        rtx::color _white;
    };
}    // namespace raytracer

#endif /* !CHECKTEXTURE_HPP_ */
