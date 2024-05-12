/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** triangle.hpp
*/

#include <primitives/primitive.hpp>
#include <materials/defaultMaterial.hpp>
#include <parser/Object.hpp>
#include <memory>

namespace raytracer {
    class Triangle : public IPrimitive {
    public:
        Triangle(rtx::point3 p1, rtx::point3 p2, rtx::point3 p3, std::shared_ptr<IMaterial> material)
                : _p1(p1), _p2(p2), _p3(p3), _mat(material) {};
        ~Triangle() = default;

        rtx::point3 _p1;
        rtx::point3 _p2;
        rtx::point3 _p3;
        std::shared_ptr<IMaterial> _mat;

        bool hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const override;

        void setName(const std::string &name) override { _name = name; }
        std::string getName() const override { return _name; }
    private:
        rtx::vec3 cross(const rtx::vec3 &v1, const rtx::vec3 &v2) const {
            return rtx::vec3(v1.y * v2.z - v1.z * v2.y,
                             v1.z * v2.x - v1.x * v2.z,
                             v1.x * v2.y - v1.y * v2.x);
        }
        std::string _name;
    };
}