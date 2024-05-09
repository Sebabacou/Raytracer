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

    void Object::printParams()
    {
        for (auto &param : _params) {
            std::cout << "[" << _id << "]: " << param.first << " = " << param.second << std::endl;
        }
    }

    std::string Object::getName() const
    {
        std::string _name;
        auto it = _params.find("name");
        if (it != _params.end()) {
            _name = it->second;
        } else if (!_params.empty()) {
            _name = "undefined_name_object_" + std::to_string(_id);
        }
        return _name;
    }
}
