/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "object.hpp"
#include <memory>

namespace raytracer {

    class Sphere : public Object {
        public:
            Sphere(rtx::vec3 center, float radius, std::shared_ptr<Mat> mat) : _position(center), _radius(radius), _mat(mat) {};
            ~Sphere() {};

            rtx::vec3 _position;
            float _radius;
            std::shared_ptr<Mat> _mat;

            bool hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const override;
    };

    std::ostream &operator<<(std::ostream &os, const Sphere &s);
}

#endif /* !SPHERE_HPP_ */
