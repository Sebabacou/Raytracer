/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <vec3/vec3.hpp>
#include <range.hpp>

namespace rtx {

    using color = vec3;

    class pixel {
        public:
            pixel(color c) : r(static_cast<int>(255.999 * range(0, 0.999).clamp(c.x))),
                g(static_cast<int>(255.999 * range(0, 0.999).clamp(c.y))),
                b(static_cast<int>(255.999 * range(0, 0.999).clamp(c.z))) {};
            pixel() : r(0), g(0), b(0) {};

            int r;
            int g;
            int b;
    };

}

#endif /* !COLOR_HPP_ */
