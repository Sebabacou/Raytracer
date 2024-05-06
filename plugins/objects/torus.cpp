/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** torus
*/

#include "torus.hpp"
#include <cmath>
#include <complex>

namespace raytracer {

    std::array<std::complex<float>, 4> Torus::solveQuartic(float a, float b, float c, float d, float e) const {
        std::array<std::complex<float>, 4> roots;

        std::complex<float> A = std::complex<float>(b) / std::complex<float>(a);
        std::complex<float> B = std::complex<float>(c) / std::complex<float>(a);
        std::complex<float> C = std::complex<float>(d) / std::complex<float>(a);
        std::complex<float> D = std::complex<float>(e) / std::complex<float>(a);

        std::complex<float> squareRoot = sqrt(std::complex<float>(256) * A * A * A * A * D * D - std::complex<float>(192) * A * A * A * B * C * D + std::complex<float>(128) * A * A * A * C * C * C + std::complex<float>(144) * A * A * B * B * D * D - std::complex<float>(6) * A * A * B * B * B * C - std::complex<float>(27) * A * A * C * C * C * C + std::complex<float>(144) * A * B * B * C * C * D - std::complex<float>(6) * A * B * B * B * B * D - std::complex<float>(128) * B * B * B * B * C * C + std::complex<float>(4) * B * B * B * B * B * B);
        std::complex<float> P = std::complex<float>(8) * A * C - std::complex<float>(3) * B * B;
        std::complex<float> Q = B * B * B - std::complex<float>(4) * A * D;
        std::complex<float> R = std::complex<float>(256) * A * A * C * C * C - std::complex<float>(64) * A * A * A * D * D - std::complex<float>(3) * B * B * B * B * B + std::complex<float>(16) * A * B * B * C * C;


        std::complex<float> resultS;
        if (sqrt(std::norm(Q * Q)) - sqrt(std::norm(std::complex<float>(4) * R)) >= 0) {
            resultS = sqrt(Q * Q - std::complex<float>(4) * R);
        } else {
            resultS = -sqrt(std::complex<float>(4) * R - Q * Q);
        }
        std::complex<float> S = std::complex<float>(0.25) * sqrt((-std::complex<float>(2) * P + resultS + std::complex<float>(2) * sqrt(squareRoot)) / std::complex<float>(3));

        std::complex<float> resultT;
        if ((sqrt(std::norm(Q * Q)) - sqrt(std::norm(std::complex<float>(4) * R))) >= 0) {
            resultT = sqrt(Q * Q - std::complex<float>(4) * R);
        } else {
            resultT = -sqrt(std::complex<float>(4) * R - Q * Q);
        }
        std::complex<float> T = std::complex<float>(0.25) * sqrt((-std::complex<float>(2) * P + resultT + std::complex<float>(2) * sqrt(squareRoot)) / std::complex<float>(3));

        roots[0] = -std::complex<float>(0.25) * A + std::complex<float>(0.5) * sqrt(-std::complex<float>(4) * S * S - std::complex<float>(2) * P + Q / S) - S;
        roots[1] = -std::complex<float>(0.25) * A + std::complex<float>(0.5) * sqrt(-std::complex<float>(4) * S * S - std::complex<float>(2) * P - Q / S) - S;
        roots[2] = -std::complex<float>(0.25) * A + std::complex<float>(0.5) * sqrt(-std::complex<float>(4) * T * T - std::complex<float>(2) * P + Q / T) + T;
        roots[3] = -std::complex<float>(0.25) * A + std::complex<float>(0.5) * sqrt(-std::complex<float>(4) * T * T - std::complex<float>(2) * P - Q / T) + T;

        return roots;
    }

    bool Torus::hit(const rtx::ray &r, HitData &data, rtx::range rayRange) const
    {
        rtx::vec3 d = r._direction;
        rtx::vec3 oc = r._origin - _position;

        float dd = d.dot(d);
        float doC = d.dot(oc);
        float ococ = oc.dot(oc);
        float rR = _torusRadius * _torusRadius;
        float radiusTube = _tubeRadius * _tubeRadius;

        float a = dd * dd;
        float b = 4.0 * doC * dd;
        float c = 2.0 * (2.0 * doC * doC + 2.0 * rR * (d.z * d.z - 1) + ococ * dd);
        float f = 4.0 * (doC * ococ + rR * oc.z * d.z);
        float e = ococ * ococ + 4.0 * rR * (oc.z * oc.z - radiusTube) - rR * rR;

        std::array<std::complex<float>, 4> roots = solveQuartic(a, b, c, f, e);

        for (const auto& root : roots) {
            if (root.imag() == 0) {
                float t = root.real();
                if (rayRange.isInRange(t)) {
                    rtx::vec3 hitPoint = r.at(t);
                    rtx::vec3 normal = (hitPoint - _position).normalize();
                    if (data.normal.dot(r._direction) > 0) {
                        data.normal = rtx::vec3::Null - data.normal;
                        data.outside = false;
                    } else {
                        data.outside = true;
                    }
                    data.t = t;
                    data.normal = normal;
                    data.p = hitPoint;
                    data.mat = _mat;
                    return true;
                }
            }
        }
        return false;
    }
}
