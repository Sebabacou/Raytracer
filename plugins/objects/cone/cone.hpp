/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** cone
*/

#ifndef CONE_HPP_
#define CONE_HPP_

#include "primitive.hpp"
#include <memory>
#include <cmath>

namespace raytracer {
    class Cone : public Primitive {
        public:
            Cone(rtx::point3 center, float radius, float height, std::shared_ptr<IMaterial> material)
                : _position(center), _radius(radius), _height(height), _mat(material) {};
            ~Cone() = default;

            rtx::point3 _position;
            float _radius;
            float _height;
            std::shared_ptr<IMaterial> _mat;

            bool hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const override;
    };
}

#endif /* !CONE_HPP_ */
