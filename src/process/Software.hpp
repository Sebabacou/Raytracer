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


using FunctionType = void(*)();

class Software {
    public:
        Software() {
            try {
                _parser.parseFile("scenes/config.cfg");
                std::cout << "settings loaded" << std::endl;
                _settings = _parser.getSettings();
//                std::cout << _parser.getSettings() << std::endl;
            } catch (const std::exception &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        ~Software() = default;

        int start();


        void loadAllLibs();
    private:
        raytracer::Parser _parser;

        raytracer::Settings _settings;
        std::vector<std::shared_ptr<DLLoader<raytracer::IObject *(*)(void)>>> _objectBuilder;
        std::vector<std::shared_ptr<DLLoader<raytracer::IMaterial *(*)(void)>>> _materialBuilder;
        std::vector<std::shared_ptr<DLLoader<raytracer::ICamera *(*)(void)>>> _cameraBuilder;
        raytracer::World _world;
        std::vector<std::shared_ptr<raytracer::ICamera>> _cameras;
};

#endif //RAYTRACER_SOFTWARE_HPP
