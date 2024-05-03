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
#include "DLLoader/DLLoader.hpp"

using FunctionType = void(*)();

class Software {
    public:
        Software() = default;
        ~Software() = default;
        void loadAllLibs();
        std::map<std::string, DLLoader> getLibs() const { return _libs; }
        int execFunction(const std::string &libName, const std::string &funcName);
        int execAllFunction(std::string funcName);
        std::map<std::string, void(*)()> getBuilder() const { return _builder; }
    private:
        std::map<std::string, DLLoader> _libs;
        std::map<std::string, void(*)()> _builder;
};


#endif //RAYTRACER_SOFTWARE_HPP
