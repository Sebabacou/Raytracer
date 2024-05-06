/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** testSo
*/

#ifndef RAYTRACER_TESTSO_HPP
#define RAYTRACER_TESTSO_HPP

#include <iostream>
#include <memory>

///////////////////////////////////////////////////////////////////
// TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST //
///////////////////////////////////////////////////////////////////
class light {
    public:
        light() = default;
        ~light() = default;
        void hello() { std::cout << "Hello from light" << std::endl; }
};

extern "C" {
    void hello() { std::cout << "Hello from light" << std::endl; }
}

#endif //RAYTRACER_TESTSO_HPP