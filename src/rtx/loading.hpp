/*
** EPITECH PROJECT, 2024
** raytracing
** File description:
** loading
*/

#ifndef LOADING_HPP_
#define LOADING_HPP_

#include <iostream>
#include <ctime>

namespace rtx {
    class loading {
        public:
            loading(float goal) : _goal(goal) {
                _width = 50;
                _start = time(0);
            };
            ~loading() {};

            void displayLoading(float current) {
                float progress = current / _goal;
                int pos = _width * progress + 1;
                time_t now = time(0);

                std::cout << "\r[";
                for (int i = 0; i < _width; i++) {
                    if (i < pos) std::cout << "=";
                    else if (i == pos) std::cout << ">";
                    else std::cout << " ";
                }
                std::cout << "] ";
                displayPourcentage(progress * 100 + 1);
                std::cout << " ";
                displayTime(now - _start);
                if (current != 0) {
                    std::cout << " (aprox: ";
                    displayTime((now - _start) * (_goal - current) / current);
                    std::cout << ")";
                }
                std::cout << std::flush;
                if (current == _goal || current == _goal - 1) {
                    std::cout << std::endl;
                    displayTime(getTime());
                    std::cout << std::endl;
                }
                _end = now;
            }
            int getTime() {
                return _end - _start;
            }

        protected:
        private:
            float _goal;
            float _width;
            time_t _start;
            time_t _end;

            void displayTime(int seconds) {
                int hours = seconds / 3600;
                int minutes = (seconds % 3600) / 60;
                seconds = seconds % 60;
                if (hours > 0) {
                    if (hours < 10) std::cout << "0";
                    std::cout << hours << ":";
                }
                if (minutes < 10) std::cout << "0";
                std::cout << minutes << ":";
                if (seconds < 10) std::cout << "0";
                std::cout << seconds;
            }
            void displayPourcentage(int pourcentage) {
                if (pourcentage < 10) std::cout << " ";
                if (pourcentage < 100) std::cout << " ";
                std::cout << pourcentage << "%";
            }
    };
}

#endif /* !LOADING_HPP_ */
