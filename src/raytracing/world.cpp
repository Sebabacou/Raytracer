/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** world
*/

#include "world.hpp"

namespace raytracer {
    bool World::hit(const rtx::ray &r, HitData &data) const {
        HitData tmpData;
        bool hit = false;
        float closest = std::numeric_limits<float>::max();

        for (auto &obj : _objects) {
            if (obj->hit(r, tmpData, rtx::range(0.001, closest)) && tmpData.t < closest) {
                hit = true;
                closest = tmpData.t;
                data = tmpData;
            }
        }
        return hit;
    }

    bool World::directLight(HitData &data, rtx::color &color) const {
        HitData tmpData;
        bool hit = false;
        float closest = std::numeric_limits<float>::max();

        // for (auto &light : _lights) {
        //     light->directLight(, data, color);
        // }
        return hit;
    }

    std::ostream &operator<<(std::ostream &os, World &w) {
        os << "World(" << w.objects().size() << " objects)" << std::endl;
        os << "World(" << w.lights().size() << " lights)";
        return os;
    }
}