/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DLSym
*/

#ifndef DLSYM_HPP_
#define DLSYM_HPP_

#include <dlfcn.h>
#include <memory>

template<typename T>
class DLSym {
    public:
        DLSym(std::shared_ptr<void> handle) : _handle(handle) {};
        ~DLSym();

        T getFunction(const std::string &entryPoint) {
            try {
                T func = reinterpret_cast<T>(dlsym(_handle.get(), entryPoint.c_str()));
                if (!func) {
                    throw std::runtime_error("Cannot load symbol: " + std::string(dlerror()));
                }
                return func;
            } catch (const std::exception &e) {
                throw std::runtime_error("Cannot load symbol: " + std::string(dlerror()));
            }
        }

    protected:
    private:
        std::shared_ptr<void> _handle;

};

#endif /* !DLSYM_HPP_ */
