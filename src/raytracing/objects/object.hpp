/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <rtx.hpp>
#include <hitData.hpp>

namespace raytracer {

    class IObject {
        public:
            IObject() = default;
            ~IObject() = default;

            virtual bool hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const = 0;
        protected:
        private:
            rtx::vec3 _position;
    };
}

#endif /* !OBJECT_HPP_ */
