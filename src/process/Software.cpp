/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Software
*/

#include "Software.hpp"

void Software::loadAllLibs()
{
    for (const auto &entry : std::filesystem::directory_iterator("plugins")) {
        if (entry.path().extension() != ".so")
            continue;
        DLLoader lib = DLLoader(entry.path().string());
        auto hello = lib.getInstance<void(*)()>("hello");
        hello();
    }
}