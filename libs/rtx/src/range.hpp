/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** range
*/

#ifndef RANGE_H_
#define RANGE_H_

#include <iostream>

namespace rtx {
    class range {
        public:
            range() = default;
            range(float min, float max) : _min(min), _max(max) {};
            ~range() = default;

            bool isInRange(float value) const { return value >= _min && value <= _max; }
            float clamp(float value) const { return std::max(_min, std::min(value, _max)); }

            float _min;
            float _max;
    };
}

#endif /* !RANGE_H_ */
