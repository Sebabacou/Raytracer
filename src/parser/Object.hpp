/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Object.hpp
*/

#pragma once

#include <iostream>
#include <string>
#include <map>

/**
 * @namespace raytracer
 * @brief The main namespace
 */
namespace raytracer {
    /**
     * @class Object
     * @brief This class will represent an object
     */
    class Object {
        public:
            Object(std::size_t id) : _id(id) {};
            ~Object() = default;

            /**
             * @brief Add a parameter to the object
             *
             * @param name The name of the parameter
             * @param value The value of the parameter
             */
            void addParam(const std::string &name, const std::string &value) {
                _params[name] = value;
            }

            /**
             * @brief Get the id of the object
             *
             * @return The id of the object
             */
            [[nodiscard]] std::size_t getId() const { return _id; }

            /**
             * @brief Get a parameter of the object
             *
             * @param name The name of the parameter
             * @return The value of the parameter or an empty string in case of error
             */
            [[nodiscard]] std::string getParam(const std::string &name) const { return _params.at(name); }

            /**
             * @brief Get the name of the object
             *
             * @return The name of the object
             */
            std::string getName() const {
                std::string _name;
                auto it = _params.find("name");
                if (it != _params.end()) {
                    _name = it->second;
                } else if (!_params.empty()) {
                    _name = "undefined_name_object_" + std::to_string(_id);
                }
                return _name;
            }

            /**
             * @brief Set a parameter of the object
             *
             * @param name The name of the parameter
             * @param value The value of the parameter
             * @details This function will add the parameter if it does not exist
             */
            void setParam(const std::string &name, const std::string &value) { _params[name] = value; }

            /**
             * @brief Get the parameters of the object
             *
             * @return The parameters of the object
             */
            [[nodiscard]] std::map<std::string, std::string> getParams() const { return _params; }

            /**
             * @brief Print the parameters of the object
             *
             * @details This function will print the parameters of the object in the following format:
             * @details [id]: param1 = value1
             */
            void printParams() {
                for (auto &param : _params) {
                    std::cout << "[" << _id << "]: " << param.first << " = " << param.second << std::endl;
                }
            }
        private:

            /**
             * @brief The id of the object
             */
            std::size_t _id;

            /**
             * @brief The parameters of the object
             *
             * @param First the name of the parameter
             * @param Second the value of the parameter
             */
            std::map<std::string, std::string> _params;

    };
}