/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** main.cpp
*/

#include "Software.hpp"
#include <iostream>

int main()
{
    Software software;
    software.loadAllLibs();
    try {
        software.execFunction("light.so", "hello");
        software.execAllFunction("hello");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}