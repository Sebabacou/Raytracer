/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** hitData
*/

#ifndef HITDATA_HPP_
#define HITDATA_HPP_

#include <rtx.hpp>
#include <memory>

namespace raytracer {

    class IMaterial;

    class HitData {
        public:
            rtx::point3 p;
            rtx::vec3 normal;
            float t;
            bool outside;
            std::shared_ptr<IMaterial> mat;
            float u;
            float v;
    };
}

#endif /* !HITDATA_HPP_ */
