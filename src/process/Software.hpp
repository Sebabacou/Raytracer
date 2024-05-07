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


using FunctionType = void(*)();

class Software {
    public:
        Software() = default;
        ~Software() = default;

        int start();


        void loadAllLibs();
        std::map<std::string, DLLoader> getLibs() const { return _libs; }
        int execFunction(const std::string &libName, const std::string &funcName);
        int execAllFunction(std::string funcName);
        std::map<std::string, void(*)()> getBuilder() const { return _builder; }
    private:
        std::map<std::string, DLLoader> _libs;

        std::map<std::string, void(*)()> _builder;

        std::map<std::string, raytracer::IObject *(*)()> _objectBuilder;
        std::map<std::string, raytracer::IMaterial *(*)()> _materialBuilder;
        std::map<std::string, raytracer::ICamera *(*)()> _cameraBuilder;
        raytracer::World _world;

        template<typename T>
        T getFactory(const std::string &path) {
            try {
                DLLoader loader(path);
                return loader.getInstance<T>("factory");
            } catch (const std::runtime_error &e) {
                throw std::runtime_error("Cannot open library: " + std::string(dlerror()));
            }
        }

};

#endif //RAYTRACER_SOFTWARE_HPP
