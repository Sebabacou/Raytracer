/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Settings.hpp
*/

#pragma once

#include "Object.hpp"
#include <iostream>
#include <map>
#include <list>

/**
 * @namespace raytracer
 * @brief The main namespace
 */
namespace raytracer {
    /**
     * @class Settings
     * @brief This class will contain all the settings of the scene
     */
    class Settings {
        public:
            Settings() = default;
            ~Settings() = default;

            /**
             * @brief Add a type of object to the scene
             *
             * @param type The type of the object
             */
            void addTypeObject(const std::string &type);

            /**
             * @brief Add a subtype of object to the scene
             *
             * @param type The type of the object
             * @param name The name of the subtype
             */
            void addSubTypeObject(const std::string &type, const std::string &name);

            /**
             * @brief Add an empty object to the scene
             *
             * @param type The type of the object
             * @param name The name of the subtype
             * @details This function will add at the end of the list of objects of the subtype a new object
             * @details The id of the object will be incremented
             */
            void addEmptyObject(const std::string &type, const std::string &name);

            /**
             * @brief Add a parameter to an object
             *
             * @param type The type of the object
             * @param name The name of the subtype
             * @param param The name of the parameter
             * @param value The value of the parameter
             * @details This function will add a parameter to the last object of the subtype
             */
            void addParamToObject(const std::string &type, const std::string &name, const std::string &param, const std::string &value);

            /**
             * @brief Print all the settings of the scene
             *
             * @details This function will print all the settings of the scene in the console
             */
            void printSettings();

            /**
             * @brief Get the settings of the scene
             *
             * @return The settings of the scene
             */
            std::map<std::string, std::map<std::string, std::list<Object>>> getSceneSettings() { return _sceneSettings; }

            /**
             * @brief Get the objects of the scene by type
             *
             * @param type The type of the object
             * @return The objects of the scene by type
             */
            std::map<std::string, std::list<Object>> getObjectsByType(const std::string &type) { return _sceneSettings[type]; }

            /**
             * @brief Get the objects of the scene by subtype
             *
             * @param type The type of the object
             * @param subtype The subtype of the object
             * @return The objects of the scene by subtype
             */
            std::list<Object> getObjectsBySubType(const std::string &type, const std::string &subtype) { return _sceneSettings[type][subtype]; }
        private:
            /**
             * @brief The settings of the scene
             *
             * @param First The type of the object ( camera, light, object, material, etc... )
             * @param Second The subtype of the object ( camera_pixel, camera_classic, sphere, plane, etc... )
             * @param List The list of objects that are in the scene
             */
            std::map<std::string, std::map<std::string, std::list<Object>>> _sceneSettings;

            /**
             * @brief The id of the object
             *
             * @details This id will be incremented each time we add an object to the scene with the function addEmptyObject
             */
            std::size_t _id = 0;
    };
}