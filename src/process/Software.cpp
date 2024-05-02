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
    for (const auto &entry : std::filesystem::directory_iterator("plugins")) {
        if (entry.path().extension() != ".so")
            continue;
        _libs[entry.path().filename().string()] = DLLoader(entry.path().string());
        std::cout << "Loaded: " << entry.path().filename().string() << std::endl;
    }
}
int Software::execAllFunction(std::string funcName)
{
    for (const auto &lib : _libs) {
        if (_libs[lib.first].getInstance<void(*)()>(funcName) == nullptr)
            throw std::runtime_error("Function not load in library");
        _libs[lib.first].getInstance<void(*)()>(funcName)();
    }
    return 0;
}
int Software::execFunction(const std::string &libName, const std::string &funcName)
{
    if (_libs.find(libName) == _libs.end())
        throw std::runtime_error("Library is empty");
    if (_libs.find(libName) == _libs.end())
        throw std::runtime_error("Library not found");
    if (_libs[libName].getInstance<void(*)()>(funcName) == nullptr)
        throw std::runtime_error("Function not load in library");

    _libs[libName].getInstance<void(*)()>(funcName)();
    return 0;
}