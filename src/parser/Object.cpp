/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Object.cpp
*/

#include "Object.hpp"

namespace raytracer {

    void Object::addParam(const std::string &name, const std::string &value)
    {
        _params[name] = value;
    }

    void Object::printParams() const
    {
        for (auto &param : _params) {
            std::cout << "[" << _id << "]: " << param.first << " = " << param.second << std::endl;
        }
    }
}
