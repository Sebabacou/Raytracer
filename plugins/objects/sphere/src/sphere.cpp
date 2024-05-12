/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** sphere
*/

#include "sphere.hpp"
#include <sstream>



namespace raytracer {
    bool Sphere::hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const
    {
        rtx::vec3 oc = _position - r._origin;

        float a = r._direction.dot(r._direction);
        float b = -2.0 * oc.dot(r._direction);
        float c = oc.dot(oc) - _radius * _radius;
        float discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
            return false;
        data.t = (-b - std::sqrt(discriminant)) / (2.0 * a);
        if (rayRange.isInRange(data.t) == false)
            return false;
        data.p = r.at(data.t);
        data.normal = (data.p - _position) / _radius;
        if (data.normal.dot(r._direction) > 0) {
            data.normal = rtx::vec3::Null - data.normal;
            data.outside = false;
        } else {
            data.outside = true;
        }
        data.mat = _mat;

        float theta = acos(-data.p.y);
        float phi = atan2(-data.p.z, data.p.x) + M_PI;
        data.u = phi / (2 * M_PI);
        data.v = theta / M_PI;

        return true;
    }

}

extern "C" {
    raytracer::IPrimitive *factory(raytracer::Object &object, std::vector<std::shared_ptr<raytracer::IMaterial>> materials)
    {
        std::cout << "Creating sphere" << std::endl;
        rtx::vec3 position;
        float radius = 1;
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
            std::string sphereName = object.getParam("material");
            for (auto &mat_ : materials) {
                if (mat_->getName() == sphereName) {
                    mat = mat_;
                    break;
                }
            }
        } catch (const std::exception &e) {
            std::cout << "No material found: " << object.getParam("material") << std::endl;
        }

        return new raytracer::Sphere(position, radius, mat);
    }
    std::string getName()
    {
        return "Sphere";
    }
}