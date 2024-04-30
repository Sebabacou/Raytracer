/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** IParser.cpp
*/

#include "IParser.hpp"

namespace raytracer {
    IParser::IParser()
    {
    }

    IParser::~IParser()
    {
    }

    bool IParser::parseFile(std::string file)
    {
        try {
            libconfig::Config cfg;

            std::cout << "Parsing file: " << file << std::endl;
            cfg.readFile(file.c_str());
            std::cout << "Config file read successfully." << std::endl;

        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
            return false;
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
            return false;
        }
        return true;
    }
}