/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** screen
*/

#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include <color/color.hpp>
#include <vector>

namespace rtx {

    class screen {
        public:
            screen(int width, int height) : _width(width), _height(height) {
                setScreenSize();
            };
            screen() : _width(0), _height(0) {
                setScreenSize();
            };
            ~screen() = default;

            std::vector<pixel> &operator[](int i) {
                if (i < 0 || i >= _height)
                    throw std::out_of_range("Index out of range");
                return _pixels[i];
            }

            int width() const { return _width; }
            int height() const { return _height; }

            void setSize(int width, int height) {
                _width = width;
                _height = height;
                setScreenSize();
            }
            void clearScreen() {
                for (int i = 0; i < _height; i++) {
                    for (int j = 0; j < _width; j++) {
                        _pixels[i][j] = color(0, 0, 0);
                    }
                }
            }

            void setPixel(int x, int y, const pixel &p);
            void screenToPPM(std::string filename);

        private:
            std::vector<std::vector<pixel>> _pixels;
            int _width;
            int _height;

            void setScreenSize() {
                _pixels.resize(_height);
                for (int i = 0; i < _height; i++) {
                    _pixels[i].resize(_width);
                }
            }
    };

    std::ostream &operator<<(std::ostream &os, screen &s);

}

#endif /* !SCREEN_HPP_ */
