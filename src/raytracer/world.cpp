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

    std::ostream &operator<<(std::ostream &os, World &w) {
        os << "World(" << w.objects().size() << " objects)";
        return os;
    }
}