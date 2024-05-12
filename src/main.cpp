/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** main.cpp
*/

#include "Software.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        std::cout << "  SCENE_FILE: scene configuration" << std::endl;
        return 84;
    }
    if (std::string(av[1]) == "--help") {
        std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        std::cout << "  SCENE_FILE: scene configuration" << std::endl;
        return 0;
    }
    Software software;
    try {
        software.start(av[1]);

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}