/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** quadrilatere
*/

#include "quadrilatere.hpp"

namespace raytracer {

    bool Quadrilatere::hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const
    {
        auto denom = _normal.dot(r._direction);

        if (fabs(denom) < 1e-8)
            return false;

        auto t = (_d - _normal.dot(r._origin)) / denom;
        if (!rayRange.isInRange(t))
            return false;

        auto p = r.at(t);

        if (!_infinite) {
            auto planar = p - _position;
            float a = _w.dot(planar.cross(_v));
            float b = _w.dot(planar.cross(_u));
            rtx::range rangeU(0, 1);
            if (!rangeU.isInRange(a) || !rangeU.isInRange(b))
                return false;
            data.u = a;
            data.v = b;
        }

        data.t = t;
        data.p = p;
        data.mat = _mat;
        data.normal = _normal;
        data.outside = data.normal.dot(r._direction) < 0;
        if (!data.outside)
            data.normal = -data.normal;

        return true;
    }
}

extern "C" {
    raytracer::IPrimitive *factory(raytracer::Object &object, std::vector<std::shared_ptr<raytracer::IMaterial>> materials)
    {
        std::cout << "Creating quadrilatere" << std::endl;
        rtx::point3 position;
        rtx::vec3 u;
        rtx::vec3 v;
        std::shared_ptr<raytracer::IMaterial> mat = std::make_shared<raytracer::DefaultMaterial>();
        bool infinite = false;

        try {
            position = rtx::point3::stov3(object.getParam("position"));
        } catch (const std::exception &e) {
            position = rtx::point3(0, -1, 0);
        }
        try {
            u = rtx::vec3::stov3(object.getParam("u"));
        } catch (const std::exception &e) {
            u = rtx::vec3(0, 0, 1);
        }
        try {
            v = rtx::vec3::stov3(object.getParam("v"));
        } catch (const std::exception &e) {
            v = rtx::vec3(1, 0, 0);
        }
        try {
            infinite = object.getParam("infinite") == "true";
        } catch (const std::exception &e) {}
        try {
            std::string matName = object.getParam("material");
            for (auto &material : materials) {
                if (material->getName() == matName) {
                    mat = material;
                    break;
                }
            }
        } catch (const std::exception &e) {}

        return new raytracer::Quadrilatere(position, u, v, mat, infinite);
    }

    std::string getName()
    {
        return "Quadrilatere";
    }
}