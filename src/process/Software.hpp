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
//        std::map<std::string, std::shared_ptr<T>> getLibs() const { return _libs; }
    private:
//        std::map<std::string, std::shared_ptr<T>> _libs;
};


#endif //RAYTRACER_SOFTWARE_HPP
