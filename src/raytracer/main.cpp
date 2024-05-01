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

    std::shared_ptr<raytracer::Mat> mat_ground = std::make_shared<raytracer::Lambertian>(rtx::color(0.8, 0.8, 0.8));
    std::shared_ptr<raytracer::Mat> mat_center = std::make_shared<raytracer::Lambertian>(rtx::color(0.1, 0.2, 0.5));
    std::shared_ptr<raytracer::Mat> mat_left = std::make_shared<raytracer::Dielectric>(1.5);
    std::shared_ptr<raytracer::Mat> mat_right = std::make_shared<raytracer::Metal>(rtx::color(0.8, 0.6, 0.2));
    std::shared_ptr<raytracer::Mat> mat_bubble = std::make_shared<raytracer::Dielectric>(1.0 / 1.5);

    std::shared_ptr<raytracer::DirectionalLight> light = std::make_shared<raytracer::DirectionalLight>(rtx::vec3(-5, -1, -0.5), rtx::color(0.4, 0.4, 0.4));
    std::shared_ptr<raytracer::AmbientLight> ambient = std::make_shared<raytracer::AmbientLight>(rtx::color(0.1, 0.1, 0.1));

    // raytracer::Sphere sphere(rtx::vec3(0, 0, -1), 0.5);
    // std::cout << sphere << std::endl;

    raytracer::Camera camera;
    std::cout << camera << std::endl;

    raytracer::World world;
    world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(0, -100.5, -1), 100, mat_ground));
    world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(0, 0, -1.2), 0.5, mat_center));
    // world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(-1.0, 0, -1.0), 0.5, mat_left));
    // world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(-1.0, 0, -1.0), 0.4, mat_bubble));
    // world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(1.0, 0, -1.0), 5, mat_right));
    // world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(3.0, 0, -0.5), -0.45, mat_right));
    world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(0, 1, -1), 0.5, mat_center));
    world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(0, -100.5, -1), 100, mat_ground));
    // world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(0, 10, -60), 50, mat_ground));
    // world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(0, 0, -1), 0.5));

    world.addLight(light);
    world.addLight(ambient);

    // world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(0, 10, -60), 50));
    // world.addObject(std::make_shared<raytracer::Sphere>(rtx::vec3(0, -100.5, -1), 100));
    std::cout << world << std::endl;
    camera.setLookAt(rtx::point3(0, 0, -1));
    camera.setPos(rtx::point3(1, 0, 0));
    // camera.rotate(rtx::vec3(25, -25, 0));
    camera.setFov(90);
    camera.setWidth(800);
    camera.setAntialiasing(true);
    camera.setAntialiasingSamples(5);
    // camera.rotate(rtx::vec3(0, 25, 0));
    // camera.rotate(rtx::vec3(0, 0, 0));

    rtx::screen image;
    // camera.render(world, image);
    camera.render(world, image, rtx::range(0, 800), rtx::range(0,450));
    image.screenToPPM(std::string("image.ppm"));
}
