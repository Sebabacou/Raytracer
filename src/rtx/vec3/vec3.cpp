/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** vec3
*/

#include <vec3/vec3.hpp>

namespace rtx {
    vec3 operator+(const vec3& u, const vec3& v)
    {
        return vec3(u.x + v.x, u.y + v.y, u.z + v.z);
    }
    vec3 operator-(const vec3& u, const vec3& v)
    {
        return vec3(u.x - v.x, u.y - v.y, u.z - v.z);
    }
    vec3 operator*(const vec3& u, const vec3& v)
    {
        return vec3(u.x * v.x, u.y * v.y, u.z * v.z);
    }
    vec3 operator*(float x, const vec3& v)
    {
        return vec3(v.x * x, v.y * x, v.z * x);
    }
    vec3 operator*(const vec3& v, float x)
    {
        return vec3(v.x * x, v.y * x, v.z * x);
    }
    vec3 operator/(const vec3& v, float x)
    {
        return vec3(v.x / x, v.y / x, v.z / x);
    }
    std::ostream &operator<<(std::ostream &os, const vec3 &v)
    {
        os << v.x << " " << v.y << " " << v.z;
        return os;
    }

    vec3 vec3::rotateAroundPoint(const vec3 &point, const vec3 &rotation)
    {
        vec3 newVec = *this - point;
        float x = newVec.x;
        float y = newVec.y;
        float radX = degToRad(rotation.x);
        float radY = degToRad(rotation.y);

        float cosX = cos(radX);
        float sinX = sin(radX);
        float cosY = cos(radY);
        float sinY = sin(radY);
        float newX = x * (cosY * 0) + y * (cosY * 0) + z * (-sinY);
        float newY = x * (sinX * sinY * 0 - cosX * 0) + y * (sinX * sinY * 0 + cosX * 0) + z * (sinX * cosY);
        float newZ = x * (cosX * sinY * 0 + sinX * 0) + y * (cosX * sinY * 0 - sinX * 0) + z * (cosX * cosY);
        return vec3(newX, newY, newZ) + point;
    }

    vec3 vec3::reflect(const vec3 &normal) const {
        float dotProduct = dot(normal);
        vec3 n = normal * 2 * dotProduct;
        return *this - n;
    }
    vec3 vec3::refract(const vec3 &normal, float etaiOverEtat) const {
        vec3 inverse = -(*this);
        float cosTheta = std::fmin(inverse.dot(normal), 1.0);
        vec3 rOutPerp = etaiOverEtat * (*this + cosTheta * normal);
        vec3 rOutParallel = -std::sqrt(std::fabs(1.0f - rOutPerp.norm() * rOutPerp.norm())) * normal;
        return rOutPerp + rOutParallel;
    }

    const vec3 vec3::Null = vec3(0, 0, 0);
}
