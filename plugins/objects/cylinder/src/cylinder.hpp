/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** cylinder.hpp
*/

#include <primitives/primitive.hpp>
#include <materials/defaultMaterial.hpp>
#include <parser/Object.hpp>
#include <memory>

namespace raytracer {
    class cylinder : public IPrimitive {
        public:
            cylinder(rtx::point3 center, float radius, float height, std::shared_ptr<IMaterial> material)
                : _position(center), _radius(radius), _height(height), _mat(material) {};
            ~cylinder() = default;

            rtx::point3 _position;
            float _radius;
            float _height;
            std::shared_ptr<IMaterial> _mat;

            bool hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const override;

            void setName(const std::string &name) override { _name = name; }
            std::string getName() const override { return _name; }
        private:
            std::string _name;
    };
}