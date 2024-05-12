/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** cylinder.cpp
*/

#include "cylinder.hpp"

namespace raytracer {
    bool cylinder::hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const
    {

        rtx::vec3 oc = r._origin - _position;
        float a = r._direction.x * r._direction.x + r._direction.y * r._direction.y + r._direction.z * r._direction.z - pow(r._direction.y, 2);
        float b = 2 * (oc.x - _position.x) * r._direction.x+ 2 * (oc.z - _position.z) * r._direction.z;
        float c = pow(oc.x - _position.x, 2) + pow(oc.z - _position.z, 2) - pow(_radius, 2);
        float discriminant = pow(b, 2) - 4 * a * c;

        if (discriminant < 0)
            return false;
        float root = (-b - sqrt(discriminant)) / (2 * a);
        if (root < rayRange._min || root > rayRange._max) {
            root = (-b + sqrt(discriminant)) / (2 * a);
            if (root < rayRange._min || root > rayRange._max)
                return false;
        }
        data.t = root;
        data.p = r.at(data.t);
        data.normal = (data.p - rtx::point3(_position.x, data.p.y, _position.z)) / _radius;
        data.mat = _mat;
        return true;
    }
}

extern "C" {
    raytracer::IPrimitive *factory(raytracer::Object &object, std::vector<std::shared_ptr<raytracer::IMaterial>> materials)
    {
        std::cout << "Creating cylinder" << std::endl;
        rtx::vec3 position;
        float radius = 1;
        float height = 1;
        std::shared_ptr<raytracer::IMaterial> mat = std::make_shared<raytracer::DefaultMaterial>();

        try {
            position = rtx::point3::stov3(object.getParam("position"));
        } catch (const std::exception &e) {
            position = rtx::point3(0, 0, 0);
        }
        try {
            radius = std::stof(object.getParam("radius"));
        } catch (const std::exception &e) {
            radius = 1;
        }
        try {
            height = std::stof(object.getParam("height"));
        } catch (const std::exception &e) {
            height = 1;
        }
        try {
            std::string coneName = object.getParam("material");
            for (auto &mat_ : materials) {
                if (mat_->getName() == coneName) {
                    mat = mat_;
                    break;
                }
            }
        } catch (const std::exception &e) {
            std::cout << "No material found: " << object.getParam("material") << std::endl;
        }

        return new raytracer::cylinder(position, radius, height, mat);
    }
    std::string getName()
    {
        return "cylinder";
    }
}