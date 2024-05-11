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
                std::cout << GREEN << "Settings loaded" << RESET << std::endl;
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

    private:
        raytracer::Parser _parser;

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
        void loadCameras();
        void loadCamera(std::string subType);
        void loadTextures();
        void loadTexture(std::string subType);
        void loadMaterials();
        void loadMaterial(std::string subType);
        void loadLights();
        void loadLight(std::string subType);
        void loadObjects();
        void loadObject(std::string subType);
};

#endif //RAYTRACER_SOFTWARE_HPP
