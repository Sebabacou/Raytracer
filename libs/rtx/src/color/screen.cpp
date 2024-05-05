/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** screen
*/

#include "screen.hpp"
#include <fstream>

namespace rtx {

    void screen::setPixel(int x, int y, const pixel &p) {
        if (x < 0 || x >= _width || y < 0 || y >= _height)
            throw std::out_of_range("Index out of range");
        _pixels[y][x] = p;
    }

    void screen::screenToPPM(std::string filename) {
        std::ofstream file(filename);
        file << "P3\n" << _width << " " << _height << "\n255\n";
        for (int i = 0; i < _height; i++) {
            for (int j = 0; j < _width; j++) {
                file << _pixels[i][j].r << " " << _pixels[i][j].g << " " << _pixels[i][j].b << "\n";
            }
        }
        file.close();
    }

    std::ostream &operator<<(std::ostream &os, screen &s) {
        os << "Screen(" << s.width() << ", " << s.height() << ")";
        return os;
    }

}