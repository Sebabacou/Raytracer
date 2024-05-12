/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** SoftwareDisplay
*/

#ifndef SOFTWAREDISPLAY_HPP_
#define SOFTWAREDISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include <rtx.hpp>

class SoftwareDisplay {
    public:
        SoftwareDisplay(rtx::screen &screen) {
            _screen = screen;
            _width = screen.width();
            _ratio = 16.0f / 9.0f;
            _window.create(sf::VideoMode(_width, _width / _ratio), "Raytracer");
        };
        ~SoftwareDisplay() {};

        int update();
        int display();

    protected:
    private:
        rtx::screen _screen;
        sf::RenderWindow _window;
        int _width;
        int _ratio;
};

#endif /* !SOFTWAREDISPLAY_HPP_ */
