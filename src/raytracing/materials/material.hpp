/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** mat
*/

#ifndef MAT_HPP_
#define MAT_HPP_

#include <rtx.hpp>
#include <hitData.hpp>

namespace raytracer {

    class IMaterial {
        public:
            IMaterial() = default;
            ~IMaterial() = default;

            virtual bool scatter(const rtx::ray &/* r */, HitData &/* data */, rtx::vec3 &/* attenuation */, rtx::ray &/* scattered */) const {
                return false;
            }
            virtual rtx::color emitted(float u, float v, const rtx::point3& p) const {
                (void)u;
                (void)v;
                (void)p;
                return rtx::color(0,0,0);
            }

            virtual void setName(const std::string &name) = 0;
            virtual std::string getName() const = 0;
    };
}

#endif /* !MAT_HPP_ */
