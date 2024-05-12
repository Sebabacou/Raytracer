/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Software
*/

#include "Software.hpp"

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

int Software::start(const std::string path)
{
    loadAllLibs();
    if (! path.empty()) {
        if (!_parser.parseFile(path))
            throw std::runtime_error("Error while parsing the file");
        _settings = _parser.getSettings();
        std::cout << GREEN << "Settings loaded" << RESET << std::endl;
        loadWorld();
        if (_cameras.size() != 0) {
            _validScene = true;
            _cam = 0;
            _cameras[_cam]->render(_world, _image, true);
        }
    }
    shell();
    return 0;
}
