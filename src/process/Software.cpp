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
                std::cout << "Object loaded: " << entry.path() << std::endl;
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
    std::cout << _world << std::endl;
    loadAllLibs();
    std::cout << "Objects: " << _objectBuilder.size() << std::endl;
    std::cout << "Materials: " << _materialBuilder.size() << std::endl;
    std::cout << "Cameras: " << _cameraBuilder.size() << std::endl;

    // _cameras.push_back(std::shared_ptr<raytracer::ICamera>(_cameraBuilder["basicCamera.so"]()));
    std::cout << "name: " << _objectBuilder[0]->getName() << std::endl;

    raytracer::IObject *object = _objectBuilder[0]->getInstance()();
    _world.addObject(std::shared_ptr<raytracer::IObject>(object));

    raytracer::ICamera *camera = _cameraBuilder[0]->getInstance()();
    rtx::screen image;
    camera->render(_world, image);
    image.screenToPPM(std::string("image.ppm"));
    // raytracer::ICamera *camera = _cameraBuilder[0]->getInstance()();
    return 0;
}