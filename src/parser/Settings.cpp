/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Settings.cpp
*/

#include "Settings.hpp"

namespace raytracer {

    void Settings::addTypeObject(const std::string &type)
    {
        _sceneSettings[type] = {};
    }

    void Settings::addSubTypeObject(const std::string &type, const std::string &name)
    {
        _sceneSettings[type][name] = {};
    }

    void Settings::printSettings()
    {
        for (auto &type : _sceneSettings) {
            std::cout << "[TYPE]: " << type.first << std::endl;
            for (auto &subtype : type.second) {
                std::cout << "[SUBTYPE]: " << subtype.first << std::endl;
                for (auto &object : subtype.second) {
                    std::cout << "[OBJECT]: " << object.getId() << std::endl;
                    object.printParams();
                }
            }
        }
    }

    void Settings::addEmptyObject(const std::string &type, const std::string &name)
    {
        Object obj(_id++);
        _sceneSettings[type][name].push_back(obj);
    }

    void Settings::addParamToObject(const std::string &type, const std::string &subtype, const std::string &param,
                                    const std::string &value)
    {
        _sceneSettings[type][subtype].back().addParam(param, value);
    }


}
