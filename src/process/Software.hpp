/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Software
*/

#ifndef RAYTRACER_SOFTWARE_HPP
#define RAYTRACER_SOFTWARE_HPP

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <filesystem>
#include <functional>
#include <DLLoader/DLLoader.hpp>
#include <raytracer.hpp>
#include <Parser.hpp>
#include <debug.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Software {
    public:
        /**
         * @brief Constructor of the Software
         *
         * @details This function will load the settings from the config file
         */
        Software() : _parser() {
            _width = 1200;
            _height = 675;
            _window.create(sf::VideoMode(_width, _height), "Raytracer");
            if (!_font.loadFromFile("assets/arial.ttf"))
                throw std::runtime_error("Error while loading the font");
            _text.setFont(_font);
            _text.setCharacterSize(18);
            _text.setFillColor(sf::Color::White);
            _text.setPosition(5, _height - 25);
        }
        ~Software() {
            if (_renderThread.joinable())
                _renderThread.join();
            _window.close();
        }

        int start(const std::string path = "");

    private:
        /**
         * @brief Load all the libraries
         *
         * @details This function will load all the libraries by calling the loadLibs function for each type
         */
        void loadAllLibs();

        /**
         * @brief Load all the libraries in a specific path
         *
         * @tparam T The type of the library
         * @param path The path of the libraries
         * @param builder The vector of the libraries
         * @details This function will load all the libraries in the path and add them to the builder vector
         */
        template <typename T>
        void loadLibs(const std::string& path, std::vector<std::shared_ptr<DLLoader<T>>>& builder);

    private:
        raytracer::Parser _parser;
        rtx::screen _image;
        sf::RenderWindow _window;
        sf::Event _event;

        raytracer::Settings _settings;
        raytracer::World _world;
        std::vector<std::shared_ptr<raytracer::ICamera>> _cameras;
        std::vector<std::shared_ptr<raytracer::ITexture>> _textures;
        std::vector<std::shared_ptr<raytracer::IMaterial>> _materials;

        std::vector<std::shared_ptr<DLLoader<raytracer::ICamera *(*)(raytracer::Object &)>>> _cameraBuilder;
        std::vector<std::shared_ptr<DLLoader<raytracer::ILight *(*)(raytracer::Object &)>>> _lightBuilder;
        std::vector<std::shared_ptr<DLLoader<raytracer::ITexture *(*)(raytracer::Object &)>>> _textureBuilder;
        std::vector<std::shared_ptr<DLLoader<
            raytracer::IMaterial *(*)(raytracer::Object &, std::vector<std::shared_ptr<raytracer::ITexture>>)>>> _materialBuilder;
        std::vector<std::shared_ptr<DLLoader<
        raytracer::IPrimitive *(*)(raytracer::Object &, std::vector<std::shared_ptr<raytracer::IMaterial>>)>>> _objectBuilder;

        void loadWorld();
        void loadCamera(std::string subType);
        void loadTexture(std::string subType);
        void loadMaterial(std::string subType);
        void loadLight(std::string subType);
        void loadObject(std::string subType);

        void shell();
        void display();
        int update();
        void handleCommand();
        int _width;
        int _height;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Font _font;
        sf::Text _text;
        std::string _input = "";
        bool _validScene = false;
        int _cam = 0;
        bool _isRendering = false;
        std::thread _renderThread;
        std::mutex _mutex;
};

#endif //RAYTRACER_SOFTWARE_HPP
