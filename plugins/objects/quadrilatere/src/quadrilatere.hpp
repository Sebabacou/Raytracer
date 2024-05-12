/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** quadrilatere
*/

#ifndef QUADRILATERE_HPP_
#define QUADRILATERE_HPP_

#include <rtx.hpp>
#include <primitives/primitive.hpp>
#include <materials/defaultMaterial.hpp>
#include <parser/Object.hpp>

namespace raytracer {
    class Quadrilatere : public IPrimitive {
        public:
            Quadrilatere() : _position(rtx::point3(0, 0, 0)), _u(rtx::vec3(1, 0, 0)), _v(rtx::vec3(0, 1, 0)), _mat(std::make_shared<DefaultMaterial>()){
                rtx::vec3 _n = _u.cross(_v);
                _normal = _n.normalize();
                _d = _normal.dot(_position);
                _w = _n / _n.dot(_n);
            };
            Quadrilatere(rtx::point3 position, rtx::vec3 u, rtx::vec3 v, std::shared_ptr<IMaterial> mat, bool infinite = false)
                : _position(position), _u(u), _v(v), _mat(mat), _infinite(infinite) {
                    rtx::vec3 _n = _u.cross(_v);
                    _normal = _n.normalize();
                    _d = _normal.dot(_position);
                    _w = _n / _n.dot(_n);
                };
            ~Quadrilatere() {};

            rtx::point3 _position;
            rtx::vec3 _u, _v;
            rtx::vec3 _w;
            std::shared_ptr<IMaterial> _mat;
            rtx::vec3 _normal;
            float _d;
            bool _infinite = false;


            bool hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const;

            void setName(const std::string &name) override { _name = name; }
            std::string getName() const override { return _name; }
        private:
            std::string _name;

    };
}    // namespace raytracer

#endif /* !QUADRILATERE_HPP_ */
