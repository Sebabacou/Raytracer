/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Software
*/

#include "Software.hpp"
#include <iostream>

void Software::loadAllLibs()
{
    loadLibs("plugins/objects", _objectBuilder);
    loadLibs("plugins/materials", _materialBuilder);
    loadLibs("plugins/cameras", _cameraBuilder);
    loadLibs("plugins/lights", _lightBuilder);
}

void Software::linkLibsToConfig()
{
    linkLibToConfig("primitives", _objectBuilder);
    linkLibToConfig("camera", _cameraBuilder);
    linkLibToConfig("materials", _materialBuilder);
    linkLibToConfig("lights", _lightBuilder);
}

template <typename T>
void Software::loadLibs(const std::string& path, std::vector<std::shared_ptr<DLLoader<T>>>& builder)
{
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        if (entry.path().extension() == ".so") {
            try {
                auto loader = std::make_shared<DLLoader<T>>(entry.path());
                loader->getInstance("factory");
                std::cout << "Loaded: " << loader->getName() << std::endl;
                builder.push_back(loader);
            } catch (const std::runtime_error &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
}

template <typename T>
void Software::linkLibToConfig(const std::string& type, const std::vector<std::shared_ptr<DLLoader<T>>>& builder)
{
    std::vector<std::string> libNames;
    for (const auto& lib : builder) {
        libNames.push_back(lib->getName());
    }

    std::vector<std::string> typeNames;
    for (const auto &objectPair : _settings.getObjectsByType(type)) {
        typeNames.push_back(objectPair.first);
    }

    for (const auto& libName : libNames) {
        if (std::find(typeNames.begin(), typeNames.end(), libName) != typeNames.end()) {
            std::cout << type << " " << libName << " have library" << std::endl;
            std::list<raytracer::Object> objects = _settings.getObjectsBySubType(type, libName);
            for (const auto& object : objects) {
                std::cout << type << " ID: " << object.getId() << " | Name: " << object.getName() << std::endl;
                for (const auto& param : object.getParams()) {
                    std::cout << "  - " << param.first << ": " << param.second << std::endl;
                }
            }
        }
    }
}

int Software::start()
{
//    std::cout << _world << std::endl;
    std::cout << "============================= LOAD LIB =============================" << std::endl;
    loadAllLibs();
    std::cout << "=============================" << std::endl;
    std::cout << "Nbr of lib Object: " << _objectBuilder.size() << std::endl;
    for (auto it = _objectBuilder.begin(); it != _objectBuilder.end(); ++it) {
        std::cout << "  - " << (*it)->getName() << std::endl;
    }
    std::cout << "Nbr of lib Materials: " << _materialBuilder.size() << std::endl;
    for (auto it = _materialBuilder.begin(); it != _materialBuilder.end(); ++it) {
        std::cout << "  - " << (*it)->getName() << std::endl;
    }
    std::cout << "Nbr of lib Cameras: " << _cameraBuilder.size() << std::endl;
    for (auto it = _cameraBuilder.begin(); it != _cameraBuilder.end(); ++it) {
        std::cout << "  - " << (*it)->getName() << std::endl;
    }
    std::cout << "Nbr of lib Lights: " << _lightBuilder.size() << std::endl;
    for (auto it = _lightBuilder.begin(); it != _lightBuilder.end(); ++it) {
        std::cout << "  - " << (*it)->getName() << std::endl;
    }
    std::cout << "============================= CONFIG =============================" << std::endl;
    for (const auto &objectPair : _settings.getObjectsByType("primitives")) {
        std::cout << "Primitives: " << objectPair.first << std::endl;
        for (const auto &object : objectPair.second) {
            std::cout << "Primitive ID: " << object.getId() << " | Name: " << object.getName() << std::endl;
            for (const auto &param : object.getParams()) {
                std::cout << "  - " << param.first << ": " << param.second << std::endl;
            }
        }
    }
    std::cout << "=============================" << std::endl;
    for (const auto &cameraPair : _settings.getObjectsByType("camera")) {
        std::cout << "Camera: " << cameraPair.first << std::endl;
        for (const auto &camera : cameraPair.second) {
            std::cout << "Camera ID: " << camera.getId() << " | Name: " << camera.getName() << std::endl;
            for (const auto &param : camera.getParams()) {
                std::cout << "  - " << param.first << ": " << param.second << std::endl;
            }
        }
    }
    std::cout << "=============================" << std::endl;
    for (const auto &materialPair : _settings.getObjectsByType("materials")) {
        std::cout << "Material: " << materialPair.first << std::endl;
        for (const auto &material : materialPair.second) {
            std::cout << "Material ID: " << material.getId() << " | Name: " << material.getName() << std::endl;
            for (const auto &param : material.getParams()) {
                std::cout << "  - " << param.first << ": " << param.second << std::endl;
            }
        }
    }
    std::cout << "=============================" << std::endl;
    for (const auto &lightPair : _settings.getObjectsByType("lights")) {
        std::cout << "Light: " << lightPair.first << std::endl;
        for (const auto &light : lightPair.second) {
            std::cout << "Light ID: " << light.getId() << " | Name: " << light.getName() << std::endl;
            for (const auto &param : light.getParams()) {
                std::cout << "  - " << param.first << ": " << param.second << std::endl;
            }
        }
    }
    std::cout << "============================= LIB <-> CONFIG =============================" << std::endl;
    linkLibsToConfig();
    std::cout << "============================= RENDER =============================" << std::endl;
//    for (auto it = _objectBuilder.begin(); it != _objectBuilder.end(); ++it) {
//        raytracer::IObject *object = (*it)->getInstance()();
//        _world.addObject(std::shared_ptr<raytracer::IObject>(object));
//    }
//
//    raytracer::ICamera *camera = _cameras[0].get();
//    rtx::screen image;
//    camera->render(_world, image);
//    image.screenToPPM(std::string("image.ppm"));
//     raytracer::ICamera *camera = _cameraBuilder[0]->getInstance()();
    return 0;
}