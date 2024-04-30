/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** world
*/

#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <list>
#include <objects/object.hpp>
#include <memory>
#include <range.hpp>

namespace raytracer {

    class ILight;

    class World {
        public:
            World() {};
            ~World() {};

            void addObject(std::shared_ptr<Object> obj) {
                _objects.push_back(obj);
            }
            std::list<std::shared_ptr<Object>> &objects() {
                return _objects;
            }

            void addLight(std::shared_ptr<ILight> light) {
                _lights.push_back(light);
            }
            std::list<std::shared_ptr<ILight>> &lights() {
                return _lights;
            }

            bool hit(const rtx::ray &r, HitData &data) const;

        private:
            std::list<std::shared_ptr<Object>> _objects;
            std::list<std::shared_ptr<ILight>> _lights;
    };

    std::ostream &operator<<(std::ostream &os, World &w);
}

#endif /* !WORLD_HPP_ */
