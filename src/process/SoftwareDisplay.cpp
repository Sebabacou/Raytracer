/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** SoftwareDisplay
*/

#include "SoftwareDisplay.hpp"

int SoftwareDisplay::display()
{
    _window.clear();
    // for (int i = 0; i < _screen.width(); i++) {
    //     for (int j = 0; j < _screen.height(); j++) {
    //         // rtx::color color = _screen.getPixel(i, j);
    //         // sf::Color sfcolor(color.r() * 255, color.g() * 255, color.b() * 255);
    //         // sf::RectangleShape pixel(sf::Vector2f(1, 1));
    //         // pixel.setPosition(i, j);
    //         // pixel.setFillColor(sfcolor);
    //         // _window.draw(pixel);
    //     }
    // }
    _window.display();
}

int SoftwareDisplay::update()
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
    }
}
