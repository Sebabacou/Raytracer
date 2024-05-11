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
    std::cout << std::endl << "Loading libraries..." << std::endl;
    loadLibs("plugins/objects", _objectBuilder);
    loadLibs("plugins/materials", _materialBuilder);
    loadLibs("plugins/cameras", _cameraBuilder);
    loadLibs("plugins/lights", _lightBuilder);
}

void Software::linkLibsToConfig()
{
    std::cout << "================ P ================" << std::endl;
    linkLibToConfig("primitives", _objectBuilder);
    std::cout << "================ C ================" << std::endl;
    linkLibToConfig("camera", _cameraBuilder);
    std::cout << "================ M ================" << std::endl;
    linkLibToConfig("materials", _materialBuilder);
    std::cout << "================ L ================" << std::endl;
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
    loadAllLibs();
    loadWorld();
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