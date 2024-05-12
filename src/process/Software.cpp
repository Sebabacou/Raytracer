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
    std::cout << std::endl;
    loadLibs("plugins/objects", _objectBuilder);
    loadLibs("plugins/textures", _textureBuilder);
    loadLibs("plugins/materials", _materialBuilder);
    loadLibs("plugins/cameras", _cameraBuilder);
    loadLibs("plugins/lights", _lightBuilder);
    std::cout << GREEN << "Libraries loaded" << RESET << std::endl;
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
                std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
            }
        }
    }
}

int Software::start()
{
    loadAllLibs();
    loadWorld();

    raytracer::ICamera *camera = _cameras[0].get();
    rtx::screen image;
    std::cout << _world << std::endl;
    camera->render(_world, image);
    image.screenToPPM(std::string("image.ppm"));
    return 0;
}