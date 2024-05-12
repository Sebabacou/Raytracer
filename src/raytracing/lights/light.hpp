/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** light
*/

#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include <rtx.hpp>
#include <hitData.hpp>

namespace raytracer {

    class World;
    class ILight {
        public:
            ILight() = default;
            ~ILight() = default;

            virtual bool directLight(World &world, HitData &data, rtx::color &color) = 0;

            virtual void setName(const std::string &name) = 0;
            virtual std::string getName() const = 0;
        protected:
        private:
    };
}

#endif /* !LIGHT_HPP_ */
