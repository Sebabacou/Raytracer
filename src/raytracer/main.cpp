/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** main
*/

#include <raytracer.hpp>
#include <rtx.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>

int main(int ac, char **av)
{

    std::shared_ptr<raytracer::IMaterial> mat_ground = std::make_shared<raytracer::TextureMaterial>(rtx::color(0.8, 0.8, 0.8));
    std::shared_ptr<raytracer::IMaterial> mat_center = std::make_shared<raytracer::TextureMaterial>(rtx::color(1, 0, 0));

    std::shared_ptr<raytracer::ITexture> checkText = std::make_shared<raytracer::CheckTexture>(rtx::color(0.2, 0.3, 0.1), rtx::color(0.9, 0.9, 0.9), 10);

    std::shared_ptr<raytracer::IMaterial> mat_left = std::make_shared<raytracer::TextureMaterial>(checkText);

    raytracer::Camera camera;
    std::cout << camera << std::endl;

    raytracer::World world;

    world.addObject(std::make_shared<raytracer::Sphere>(rtx::point3(0, 0, -1), 0.5, mat_center));
    world.addObject(std::make_shared<raytracer::Sphere>(rtx::point3(0, -100.5, -1), 100, mat_left));

    std::cout << world << std::endl;
    camera.setLookAt(rtx::point3(0, 0, -1));
    camera.setPos(rtx::point3(0, 1, 2));
    // camera.rotate(rtx::vec3(25, -25, 0));
    camera.setFov(90);
    camera.setWidth(800);
    camera.setAntialiasing(true);
    camera.setAntialiasingSamples(200);

    rtx::screen image;
    camera.render(world, image);
    // camera.render(world, image, rtx::range(0, 800), rtx::range(0,450));
    image.screenToPPM(std::string("image.ppm"));
}
