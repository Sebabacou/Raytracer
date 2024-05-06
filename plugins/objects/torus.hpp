/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** torus
*/

#ifndef RAYTRACER_TORUS_HPP
#define RAYTRACER_TORUS_HPP

#include <rtx.hpp>
#include <complex>
#include <array>

namespace raytracer {
    class Torus : public IObject {
        public:
            Torus(rtx::vec3 center, float tubeRadius, float torusRadius, std::shared_ptr<IMaterial> mat) : _position(center), _tubeRadius(tubeRadius), _torusRadius(torusRadius), _mat(mat) {};
            ~Torus() {};

            rtx::vec3 _position;
            float _tubeRadius;
            float _torusRadius;
            std::shared_ptr<IMaterial> _mat;

            bool hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const override;
            std::array<std::complex<float>, 4> solveQuartic(float a, float b, float c, float d, float e) const;
        };

        std::ostream &operator<<(std::ostream &os, const Torus &t);

}


#endif //RAYTRACER_TORUS_HPP
