/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ambientLight
*/

#include "ambientLight.hpp"

namespace raytracer {
    bool AmbientLight::directLight(World &/* world */, HitData &/* data */, rtx::color &color)
    {
        color = _color;
        return true;
    }
}

extern "C" {
    raytracer::ILight *factory(raytracer::Object &object)
    {
        rtx::vec3 color;
        std::cout << "Creating AmbientLight" << std::endl;

        try {
            color = rtx::vec3::stov3(object.getParam("color"));
        } catch (const std::exception &e) {}

        return new raytracer::AmbientLight(color);
    }

    std::string getName()
    {
        return "AmbientLight";
    }
}