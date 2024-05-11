/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <rtx.hpp>

namespace raytracer {
    class ITexture {
        public:
            ~ITexture() = default;
            virtual rtx::color value(float u, float v, const rtx::vec3 &p) const = 0;
    };
}

#endif /* !TEXTURE_HPP_ */
