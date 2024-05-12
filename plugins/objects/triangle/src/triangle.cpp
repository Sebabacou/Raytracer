/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** triangle.cpp
*/

#include "triangle.hpp"

namespace raytracer {
    bool Triangle::hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const
    {
        rtx::vec3 edge1 = _p2 - _p1;
        rtx::vec3 edge2 = _p3 - _p1;
        rtx::vec3 h = cross(r._direction, edge2);
        float a = edge1.x * h.x + edge1.y * h.y + edge1.z * h.z;

        if (a > -0.00001 && a < 0.00001)
            return false;

        float f = 1.0 / a;
        rtx::vec3 s = r._origin - _p1;
        float u = f * (s.x * h.x + s.y * h.y + s.z * h.z);
        if (u < 0.0 || u > 1.0)
            return false;

        rtx::vec3 q = cross(s, edge1);
        float v = f * (r._direction.x * q.x + r._direction.y * q.y + r._direction.z * q.z);
        if (v < 0.0 || u + v > 1.0)
            return false;

        float t = f * (edge2.x * q.x + edge2.y * q.y + edge2.z * q.z);

        if (t > rayRange._min && t < rayRange._max) {
            data.t = t;
            data.p = r.at(data.t);
            data.normal = cross(edge1, edge2);
            data.mat = _mat;
            return true;
        }

        return false;
    }
}

extern "C" {
    raytracer::IPrimitive *factory(raytracer::Object &object, std::vector<std::shared_ptr<raytracer::IMaterial>> materials)
    {
        std::cout << "Creating triangle" << std::endl;
        rtx::vec3 p1, p2, p3;
        std::shared_ptr<raytracer::IMaterial> mat = std::make_shared<raytracer::DefaultMaterial>();

        try {
            p1 = rtx::point3::stov3(object.getParam("p1"));
            p2 = rtx::point3::stov3(object.getParam("p2"));
            p3 = rtx::point3::stov3(object.getParam("p3"));
        } catch (const std::exception &e) {}
        try {
            std::string triangleName = object.getParam("material");
            for (auto &mat_ : materials) {
                if (mat_->getName() == triangleName) {
                    mat = mat_;
                    break;
                }
            }
        } catch (const std::exception &e) {
            std::cout << "No material found: " << object.getParam("material") << std::endl;
        }

        return new raytracer::Triangle(p1, p2, p3, mat);
    }
    std::string getName()
    {
        return "Triangle";
    }
}