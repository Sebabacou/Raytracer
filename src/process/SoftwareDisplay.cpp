/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** SoftwareDisplay
*/

#include "Software.hpp"

void Software::display()
{
    sf::Image image;
    if (!_image.width() == 0 && !_image.height() == 0) {

        image.create(_image.width(), _image.height(), sf::Color::Black);
        for (int y = 0; y < _image.height(); y++) {
            for (int x = 0; x < _image.width(); x++) {
                image.setPixel(x, y, sf::Color(_image[y][x].r, _image[y][x].g, _image[y][x].b));
            }
        }
        _texture.loadFromImage(image);
        _sprite.setTexture(_texture);
    }

    _window.clear();
    _window.draw(_sprite);
    _text.setString(std::string("raytracer> ") + _input);
    _window.draw(_text);
    _window.display();
}

int Software::update()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return -1;
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Escape)
                return -1;
        }
        if (_event.type == sf::Event::TextEntered) {
            if (_event.text.unicode < 128 && _event.text.unicode != 8 && _event.text.unicode != 13) {
                _input += static_cast<char>(_event.text.unicode);
            }
            if (_event.text.unicode == 8 && _input.size() > 0) {
                _input.pop_back();
            }
        }
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Return) {
                if (_input == "exit")
                    return -1;
                try {
                    handleCommand();
                } catch (const std::exception &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                _input.clear();
            }
        }
    }
    return 0;
}

void Software::shell()
{
    while (true) {
        if (!_isRendering)
            if (update() == -1)
                break;
        display();
    }
}

void Software::handleCommand()
{
    if (_input.substr(0, 4) == "load") {
        std::string arg = _input.substr(5);
        if (!_parser.parseFile(arg))
            throw std::runtime_error("Error while parsing the file");
        std::cout << GREEN << "Settings loaded" << RESET << std::endl;
        _settings = _parser.getSettings();
        loadWorld();
        if (_cameras.size() == 0)
            throw std::runtime_error("No camera loaded");
        std::cout << GREEN << "Scene loaded" << RESET << std::endl;
        _validScene = true;
        _cam = 0;
        _cameras[_cam]->render(_world, _image, true);
    }
    if (_input.substr(0, 4) == "save") {
        std::string arg = "renders/image.ppm";
        if (_input.size() > 5)
            arg = _input.substr(5);
        _image.screenToPPM(arg);
        std::cout << GREEN << "Image saved to: " << arg << RESET << std::endl;
    }

    if (_input.substr(0, 6) == "render") {
        if (_validScene == false)
            throw std::runtime_error("No scene loaded");
        if (_renderThread.joinable()) {
            _renderThread.join();
        }
        _renderThread = std::thread([&]() {
            raytracer::ICamera *camera = _cameras[_cam].get();
            camera->render(_world, _image);
            std::lock_guard<std::mutex> lock(_mutex);
            _isRendering = false;
        });
        _isRendering = true;
        return;
    }

    if (_input.substr(0, 6) == "thread") {
        std::string arg = _input.substr(7);
        int nbThreads = std::stoi(arg);
        if (_validScene == false)
            throw std::runtime_error("No scene loaded");
        _cameras[_cam]->setNbThreads(nbThreads);
        std::cout << GREEN << "Threads set to: " << nbThreads << RESET << std::endl;
    }

    if (_input.substr(0, 3) == "cam") {
        if (_validScene == false)
            throw std::runtime_error("No scene loaded");
        std::string arg = _input.substr(4);
        if (arg == "next") {
            _cam++;
            if (_cam >= (int)_cameras.size())
                _cam = 0;
            std::cout << GREEN << "Camera switched to: " << _cameras[_cam]->getName() << RESET << std::endl;
        }
        if (arg == "prev") {
            _cam--;
            if (_cam < 0)
                _cam = _cameras.size() - 1;
            std::cout << GREEN << "Camera switched to: " << _cameras[_cam]->getName() << RESET << std::endl;
        }
    }
}
