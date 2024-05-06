/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** quadrilatere
*/

#ifndef QUADRILATERE_HPP_
#define QUADRILATERE_HPP_

#include "rtx.hpp"
#include "primitive.hpp"

namespace raytracer {
    class Quadrilatere : public Primitive {
        public:
            Quadrilatere(rtx::point3 position, rtx::vec3 u, rtx::vec3 v, std::shared_ptr<IMaterial> mat)
                : _position(position), _u(u), _v(v), _mat(mat) {};
            ~Quadrilatere() {};

            rtx::point3 _position;
            rtx::vec3 _u;
            rtx::vec3 _v;

            std::shared_ptr<IMaterial> _mat;

        bool hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const;
    };
}    // namespace raytracer

#endif /* !QUADRILATERE_HPP_ */
