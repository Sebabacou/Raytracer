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
#include "DLLoader/DLLoader.hpp"

class Software {
    public:
        Software() = default;
        ~Software() = default;
        void loadAllLibs();
        std::map<std::string, DLLoader> getLibs() const { return _libs; }
        int execFunction(const std::string &libName, const std::string &funcName);
        int execAllFunction(std::string funcName);
    private:
        std::map<std::string, DLLoader> _libs;
};


#endif //RAYTRACER_SOFTWARE_HPP
