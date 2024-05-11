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
    std::cout << std::endl;
    try {
        loadCameras();
        loadTextures();
        loadLights();
        loadMaterials();
        loadObjects();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << GREEN << "World loaded" << RESET << std::endl;
}

void Software::loadCamera(std::string subType)
{
    std::list<raytracer::Object> objects;

    for (const auto &builder : _cameraBuilder) {
        if (builder->getName() == subType) {
            objects = _settings.getObjectsBySubType("cameras", subType);
            for (auto &object : objects) {
                try {
                    std::shared_ptr<raytracer::ICamera> camera = std::shared_ptr<raytracer::ICamera>(builder->getInstance()(object));
                    _cameras.push_back(camera);
                } catch (const std::exception &e) {
                    std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
                }
            }
        }
    }
}



void Software::loadCameras()
{
    for (const auto &cameraPair : _settings.getObjectsByType("cameras")) {
        loadCamera(cameraPair.first);
    }
}

void Software::loadTexture(std::string subType)
{
    std::list<raytracer::Object> objects;

   for (const auto &builder : _textureBuilder) {
        if (builder->getName() == subType) {
            objects = _settings.getObjectsBySubType("textures", subType);
            for (auto &object : objects) {
                try {
                    raytracer::ITexture *texture = builder->getInstance()(object);
                    _textures.push_back(std::shared_ptr<raytracer::ITexture>(texture));
                } catch (const std::exception &e) {
                    std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
                }
            }
        }
    }
}

void Software::loadTextures()
{
    for (const auto &texturePair : _settings.getObjectsByType("textures")) {
        loadTexture(texturePair.first);
    }
}

void Software::loadLight(std::string subType)
{
    std::list<raytracer::Object> objects;

    for (const auto &builder : _lightBuilder) {
        if (builder->getName() == subType) {
            objects = _settings.getObjectsBySubType("lights", subType);
            for (auto &object : objects) {
                try {
                    std::shared_ptr<raytracer::ILight> light = std::shared_ptr<raytracer::ILight>(builder->getInstance()(object));
                    _world.addLight(light);
                } catch (const std::exception &e) {
                    std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
                }
            }
        }
    }
}

void Software::loadLights()
{
    for (const auto &lightPair : _settings.getObjectsByType("lights")) {
        loadLight(lightPair.first);
    }
}

void Software::loadMaterials()
{
    for (const auto &materialPair : _settings.getObjectsByType("materials")) {
        loadMaterial(materialPair.first);
    }
}

void Software::loadMaterial(std::string subType)
{
    std::list<raytracer::Object> objects;

    for (const auto &builder : _materialBuilder) {
        if (builder->getName() == subType) {
            objects = _settings.getObjectsBySubType("materials", subType);
            for (auto &object : objects) {
                try {
                    std::shared_ptr<raytracer::IMaterial> material = std::shared_ptr<raytracer::IMaterial>(builder->getInstance()(object, _textures));
                    _materials.push_back(material);
                } catch (const std::exception &e) {
                    std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
                }
            }
        }
    }
}

void Software::loadObject(std::string subType)
{
    std::list<raytracer::Object> objects;

    for (const auto &builder : _objectBuilder) {
        if (builder->getName() == subType) {
            objects = _settings.getObjectsBySubType("primitives", subType);
            for (auto &object : objects) {
                try {
                    std::shared_ptr<raytracer::IPrimitive> objectPrimitive = std::shared_ptr<raytracer::IPrimitive>(builder->getInstance()(object, _materials));
                    _world.addObject(objectPrimitive);
                } catch (const std::exception &e) {
                    std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
                }
            }
        }
    }
}

void Software::loadObjects()
{
    for (const auto &objectPair : _settings.getObjectsByType("primitives")) {
        loadObject(objectPair.first);
    }
}