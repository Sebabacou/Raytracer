/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Software
*/

#include "Software.hpp"
#include <iostream>


void Software::loadWorld()
{
    std::cout << std::endl << "Loading world..." << std::endl;
    try {
        loadCameras();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

}

void Software::loadCamera(std::string cameraType)
{
     std::list<raytracer::Object> objects;

    std::cout << "Loading cameras of type: " << cameraType << std::endl;
    for (const auto &builder : _cameraBuilder) {
        if (builder->getName() == cameraType) {
            objects = _settings.getObjectsBySubType("camera", cameraType);
            for (auto &object : objects) {
                // std::cout << "Primitive ID: " << object.getId() << " | Name: " << object.getName() << std::endl;
                // for (const auto &param : object.getParams()) {
                //     std::cout << "  - " << param.first << ": " << param.second << std::endl;
                // }
                try {
                    auto camera = builder->getInstance()(object);
                    // _cameras.push_back(std::make_pair(object.getName(), camera));
                    std::cout << "Loaded camera: omg" << std::endl;
                } catch (const std::exception &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            }
        }
    }
}

void Software::loadCameras()
{
    for (const auto &cameraPair : _settings.getObjectsByType("camera")) {
        loadCamera(cameraPair.first);
    }
}

void Software::loadTextures()
{

}