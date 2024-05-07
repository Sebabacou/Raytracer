/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** sphere
*/

#include "sphere.hpp"

namespace raytracer {
    bool Sphere::hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const
    {
        rtx::vec3 oc = _position - r._origin;

        float a = r._direction.dot(r._direction);
        float b = -2.0 * oc.dot(r._direction);
        float c = oc.dot(oc) - _radius * _radius;
        float discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
            return false;
        data.t = (-b - std::sqrt(discriminant)) / (2.0 * a);
        if (rayRange.isInRange(data.t) == false)
            return false;
        data.p = r.at(data.t);
        data.normal = (data.p - _position) / _radius;
        if (data.normal.dot(r._direction) > 0) {
            data.normal = rtx::vec3::Null - data.normal;
            data.outside = false;
        } else {
            data.outside = true;
        }
        data.mat = _mat;
        return true;
    }

    std::ostream &operator<<(std::ostream &os, const Sphere &s)
    {
        os << "Sphere(" << s._position << ", " << s._radius << ")";
        return os;
    }

}