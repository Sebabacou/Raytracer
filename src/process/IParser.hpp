/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** IParser.h
*/

#pragma once

#include <string>
#include <iostream>
#include <libconfig.h++>

namespace raytracer {
    class IParser {
        public:
            IParser();
            ~IParser();

            bool parseFile(std::string file);

        private:
    };
}