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
    for (const auto &entry : std::filesystem::directory_iterator("plugins/objects")) {
        if (entry.path().extension() == ".so") {
            try {
                std::shared_ptr<DLLoader<raytracer::IObject *(*)(void)>> loader = std::make_shared<DLLoader<raytracer::IObject *(*)(void)>>(entry.path());
                loader->getInstance("factory");
                std::cout << "Object loaded: " << loader->getName() << std::endl;
                _objectBuilder.push_back(loader);
            } catch (const std::runtime_error &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    for (const auto &entry : std::filesystem::directory_iterator("plugins/materials")) {
        if (entry.path().extension() == ".so") {
            try {
                std::shared_ptr<DLLoader<raytracer::IMaterial *(*)(void)>> loader = std::make_shared<DLLoader<raytracer::IMaterial *(*)(void)>>(entry.path());
                loader->getInstance("factory");
                std::cout << "Material loaded: " << loader->getName() << std::endl;
                _materialBuilder.push_back(loader);
            } catch (const std::runtime_error &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    for (const auto &entry : std::filesystem::directory_iterator("plugins/cameras")) {
        if (entry.path().extension() == ".so") {
            try {
                std::shared_ptr<DLLoader<raytracer::ICamera *(*)(void)>> loader = std::make_shared<DLLoader<raytracer::ICamera *(*)(void)>>(entry.path());
                loader->getInstance("factory");
                std::cout << "Camera loaded: " << loader->getName() << std::endl;
                _cameraBuilder.push_back(loader);
            } catch (const std::runtime_error &e) {
                std::cerr << "Error: " << e.what() << std::endl;
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
    std::cout << "============================= RENDER =============================" << std::endl;
    std::cout << "==================================================================" << std::endl;
//    std::cout << "name: " << _objectBuilder[0]->getName() << std::endl;

//    for (auto it = _objectBuilder.begin(); it != _objectBuilder.end(); ++it) {
//        raytracer::IObject *object = (*it)->getInstance()();
//        _world.addObject(std::shared_ptr<raytracer::IObject>(object));
//    }
//
//    raytracer::ICamera *camera = _cameraBuilder[0]->getInstance()();
//    rtx::screen image;
//    camera->render(_world, image);
//    image.screenToPPM(std::string("image.ppm"));
//     raytracer::ICamera *camera = _cameraBuilder[0]->getInstance()();
    return 0;
}