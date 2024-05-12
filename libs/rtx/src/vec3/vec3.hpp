/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** vec3
*/

#ifndef VEC3_HPP_
#define VEC3_HPP_

#include <cmath>
#include <iostream>
#include <random>

namespace rtx {

    inline float degToRad(float degrees) {
        return degrees * M_PI / 180.0f;
    }

    inline float radToDeg(float radians) {
        return radians * 180.0f / M_PI;
    }

    inline float randomFloat() {
        static std::uniform_real_distribution<double> distribution(0.0, 1.0);
        static std::mt19937 generator;
        return distribution(generator);
    }

    inline float randomFloat(float min, float max) {
        return min + (max - min) * randomFloat();
    }

    class vec3 {
        public:
            vec3() : x(0), y(0), z(0) {};
            vec3(float x, float y, float z) : x(x), y(y), z(z) {};
            vec3(vec3 const &vec) : x(vec.x), y(vec.y), z(vec.z) {};
            ~vec3() = default;

            float x;
            float y;
            float z;
            static const vec3 Null;

            vec3& operator=(const vec3& vec) {
                if (this != &vec) {
                    x = vec.x;
                    y = vec.y;
                    z = vec.z;
                }
                return *this;
            }

            vec3 operator-() const {
                return vec3(-x, -y, -z);
            }
            vec3 operator+=(const vec3 &vec) {
                x += vec.x;
                y += vec.y;
                z += vec.z;
                return *this;
            }
            vec3 operator*= (const float &f) {
                x *= f;
                y *= f;
                z *= f;
                return *this;
            }

            vec3 operator/=(const float &f) {
                x /= f;
                y /= f;
                z /= f;
                return *this;
            }

            float dot(const vec3 &vec) const {
                return x * vec.x + y * vec.y + z * vec.z;
            }
            float norm() const {
                return sqrt(x * x + y * y + z * z);
            }
            vec3 normalize() const {
                float n = norm();
                return vec3(x / n, y / n, z / n);
            }
            vec3 cross(const vec3 &vec) const {
                return vec3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
            }
            bool isZero() const {
                float tolerance = 1e-6;
                return std::fabs(x) < tolerance &&
                    std::fabs(y) < tolerance &&
                    std::fabs(z) < tolerance;
            }
            vec3 reflect(const vec3 &normal) const;
            vec3 refract(const vec3 &normal, float etaiOverEtat) const;

            static vec3 correctRandom() {
                float theta = randomFloat(0, 2 * M_PI);
                float phi = acos(2 * randomFloat(0, 1) - 1);
                float r = cbrt(randomFloat(0, 1));
                float sinPhi = sin(phi);
                return vec3(r * cos(theta) * sinPhi, r * sin(theta) * sinPhi, r * cos(phi));
            }
            vec3 rotateAroundPoint(const vec3 &point, const vec3 &rotation);

            class InvalidVectorString : public std::exception {
                public:
                    InvalidVectorString(int arg) : _arg(arg) {};
                    const char *what() const noexcept override {
                        return "Invalid vector string";
                    }
                    int _arg;
            };

            static vec3 stov3(std::string str) {
                std::string delimiter = ",";
                size_t pos = 0;
                std::string token;
                if (str.empty())
                    throw InvalidVectorString(0);
                float x, y, z;
                pos = str.find(delimiter);
                token = str.substr(0, pos);
                if (pos == std::string::npos)
                    throw InvalidVectorString(1);
                x = std::stof(token);
                str.erase(0, pos + delimiter.length());
                pos = str.find(delimiter);
                token = str.substr(0, pos);
                if (pos == std::string::npos)
                    throw InvalidVectorString(2);
                y = std::stof(token);
                str.erase(0, pos + delimiter.length());
                z = std::stof(str);
                return vec3(x, y, z);
            }
    };
    using point3 = vec3;
    using color = vec3;

    vec3 operator+(const vec3& u, const vec3& v);
    vec3 operator-(const vec3& u, const vec3& v);
    vec3 operator*(const vec3& u, const vec3& v);
    vec3 operator*(float x, const vec3& v);
    vec3 operator*(const vec3& v, float x);
    vec3 operator/(const vec3& v, float x);
    std::ostream &operator<<(std::ostream &os, const vec3 &v);


}

#endif /* !VEC3_HPP_ */
