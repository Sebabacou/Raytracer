/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include <primitives/primitive.hpp>
#include <materials/defaultMaterial.hpp>
#include <parser/Object.hpp>
#include <memory>

namespace raytracer {

    class Sphere : public IPrimitive {
        public:
            Sphere(rtx::vec3 center, float radius, std::shared_ptr<IMaterial> mat) : _position(center), _radius(radius), _mat(mat) {};
            ~Sphere() {};

            rtx::vec3 _position;
            float _radius;
            std::shared_ptr<IMaterial> _mat;

            bool hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const override;

            void setName(const std::string &name) override { _name = name; }
            std::string getName() const override { return _name; }
        private:
            std::string _name;
    };
}

#endif /* !SPHERE_HPP_ */
