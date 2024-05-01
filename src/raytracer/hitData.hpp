/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** hitData
*/

#ifndef HITDATA_HPP_
#define HITDATA_HPP_

#include <rtx.hpp>
#include <mats/mat.hpp>
#include <memory>

namespace raytracer {
    class HitData {
        public:
            rtx::point3 p;
            rtx::vec3 normal;
            double t;
            bool outside;
            std::shared_ptr<Mat> mat;
    };
}

#endif /* !HITDATA_HPP_ */
