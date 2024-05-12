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
    class IPrimitive {
        public:
            IPrimitive() = default;
            ~IPrimitive() = default;

            virtual bool hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const = 0;

            virtual void setName(const std::string &name) = 0;
            virtual std::string getName() const = 0;
        protected:
        private:
            rtx::vec3 _position;
    };
}


#endif /* !OBJECT_HPP_ */
