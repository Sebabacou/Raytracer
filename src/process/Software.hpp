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
        /**
         * @brief Constructor of the Software
         *
         * @details This function will load the settings from the config file
         */
        Software(std::string path) : _parser() {
            try {
                _parser.parseFile(path);
                std::cout << "settings loaded" << std::endl;
                _settings = _parser.getSettings();
            } catch (const std::exception &e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        ~Software() = default;

        int start();

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

        /**
         * @brief Link the libraries to the config
         *
         * @details This function will link the libraries to the config by calling the linkLibToConfig function for each type
         */
        void linkLibsToConfig();

        /**
         * @brief Link the libraries to the config
         *
         * @tparam T The type of the library
         * @param type The type of the object
         * @param builder The vector of the libraries
         * @details This function will link the libraries to the config
         */
        template <typename T>
        void linkLibToConfig(const std::string& type, const std::vector<std::shared_ptr<DLLoader<T>>>& builder);

        void loadWorld();
        void loadCameras();
        void loadCamera(std::string cameraType);
        void loadTextures();

    private:
        raytracer::Parser _parser;

        raytracer::Settings _settings;
        raytracer::World _world;
        std::vector<std::pair<std::string, std::shared_ptr<raytracer::ICamera>>> _cameras;

        std::vector<std::shared_ptr<DLLoader<raytracer::IPrimitive *(*)(void)>>> _objectBuilder;
        std::vector<std::shared_ptr<DLLoader<raytracer::IMaterial *(*)(void)>>> _materialBuilder;
        std::vector<std::shared_ptr<DLLoader<raytracer::ICamera *(*)(raytracer::Object &)>>> _cameraBuilder;
        std::vector<std::shared_ptr<DLLoader<raytracer::ILight *(*)(void)>>> _lightBuilder;
};

#endif //RAYTRACER_SOFTWARE_HPP
