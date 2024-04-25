/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include <vec3/vec3.hpp>

namespace rtx {

    class ray {
        public:
            ray(point3 origin, vec3 direction) : _origin(origin), _direction(direction) {};
            ray(const ray &r) : _origin(r._origin), _direction(r._direction) {};
            ray() : _origin(vec3::Null), _direction(vec3::Null) {};
            ~ray() {};

            point3 at(float t) const {
                return _origin + t * _direction;
            }

            ray &operator=(const ray &r) {
                _origin = r._origin;
                _direction = r._direction;
                return *this;
            }

            point3 _origin;
            vec3 _direction;
    };

    std::ostream &operator<<(std::ostream &os, const ray &r);
}

#endif /* !RAY_HPP_ */
