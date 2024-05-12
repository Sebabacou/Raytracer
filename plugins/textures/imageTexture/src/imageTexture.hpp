/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** checkTexture
*/

#ifndef IMAGETEXTURE_HPP_
#define IMAGETEXTURE_HPP_

#include <textures/texture.hpp>
#include <parser/Object.hpp>
#include <SFML/Graphics.hpp>

#include <rtx.hpp>

namespace raytracer {
    class ImageTexture : public ITexture {
      public:
        ImageTexture(std::string path) : _path(path) {
            if (!_image.loadFromFile(path)) {
                std::cerr << "Failed to load image: " << path << std::endl;
                return;
            }
            _loaded = true;
        }
        ~ImageTexture() = default;

        rtx::color value(float u, float v, const rtx::point3 &p) const override;

        void setName(const std::string &name) override { _name = name; }
        std::string getName() const override { return _name; }

      private:
        std::string _path;
        sf::Image _image;
        bool _loaded = false;
        std::string _name;
    };
}    // namespace raytracer

#endif /* !IMAGETEXTURE_HPP_ */
