/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** world
*/

#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <list>
#include <primitives/primitive.hpp>
#include <lights/light.hpp>
#include <memory>
#include <range.hpp>

namespace raytracer {

    class World {
        public:
            World() {};
            ~World() {};

            void addObject(std::shared_ptr<IPrimitive> obj) {
                _objects.push_back(obj);
            }
            std::list<std::shared_ptr<IPrimitive>> &objects() {
                return _objects;
            }

            void addLight(std::shared_ptr<ILight> light) {
                _lights.push_back(light);
            }
            std::list<std::shared_ptr<ILight>> &lights() {
                return _lights;
            }

            bool hit(const rtx::ray &r, HitData &data) const;
            bool directLight(HitData &data, rtx::color &color) const;

        private:
            std::list<std::shared_ptr<IPrimitive>> _objects;
            std::list<std::shared_ptr<ILight>> _lights;
    };

    std::ostream &operator<<(std::ostream &os, World &w);
}

#endif /* !WORLD_HPP_ */
