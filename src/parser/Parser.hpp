/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Parser.h
*/

#pragma once

#include "Settings.hpp"
#include <string>
#include <iostream>
#include <libconfig.h++>

/**
 * @namespace raytracer
 * @brief The main namespace
 */
namespace raytracer {
    /**
     * @class Parser
     * @brief This class will parse a file
     */
    class Parser {
        public:
            Parser() = default;
            ~Parser() = default;

            /**
             * @brief Parse a file
             *
             * @param file The file to parse
             * @return true if the file has been parsed, false otherwise
             */
            bool parseFile(std::string file);

            /**
             * @brief add a value to the scene
             *
             * @param setting The setting to add
             * @param type The type of the setting
             * @param subtype The subtype of the setting
             * @details This function will add a value to scene
             */
            void addSettingValue(const libconfig::Setting& setting, std::string type, std::string subtype);

            /**
             * @brief Parse the settings
             *
             * @param setting The setting to parse
             * @param type The type of the setting
             * @param subtype The subtype of the setting
             * @details This function will parse the settings and add them to the settings object
             * @details It will check what type of setting it is and call the right function for it
             */
            void parseSettings(const libconfig::Setting& setting, std::string type, std::string subtype = "");

            /**
             * @brief Get the settings
             *
             * @return The settings of the scene
             */
            Settings getSettings() { return _settings; }
    private:
            /**
             * @brief The settings of the scene
             */
            Settings _settings;

            /**
             * @brief The configuration of the file
             */
            libconfig::Config _cfg;
    };
}