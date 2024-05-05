/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** ray
*/

#include <ray/ray.hpp>

namespace rtx {

    std::ostream &operator<<(std::ostream &os, const ray &r)
    {
        os << "ray(" << r._origin << ", " << r._direction << ")";
        return os;
    }
}