/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <string>
#include <stdexcept>
#include <dlfcn.h>
#include <memory>
#include <iostream>

template<typename T>
class DLLoader {
public:
    DLLoader() : _handle(nullptr) {}

    DLLoader(std::string path) {
        try {
            _handle = dlopen(path.c_str(), RTLD_LAZY);
            if (!_handle) {
                throw std::runtime_error("Cannot open library: " + std::string(dlerror()));
            }
        } catch (const std::exception &e) {
            throw std::runtime_error("Cannot open library: " + std::string(dlerror()));
        }
    }
    ~DLLoader() {
        std::cout << "Destructor of DLLoader" << std::endl;
        if (_handle)
            dlclose(_handle);
    }

    DLLoader(const DLLoader& other)
            : _handle(nullptr) {
        if (other._handle) {
            _handle = other._handle;
        }
    }

    DLLoader& operator=(const DLLoader& other) {
        if (this != &other) {
            DLLoader tmp(other);
            std::swap(_handle, tmp._handle);
        }
        return *this;
    }

    DLLoader& operator=(DLLoader&& other) noexcept {
        if (this != &other) {
            _handle = nullptr;
            std::swap(_handle, other._handle);
        }
        return *this;
    }

    void getInstance(const std::string &name) {
        std::string (*getName)() = (std::string (*)())dlsym(_handle, "getName");
        if (!getName) {
            throw std::runtime_error("Cannot load symbol: " + std::string(dlerror()));
        }
        _name = getName();
        std::cout << "Name: " << _name << std::endl;

        T create = (T)dlsym(_handle, name.c_str());
        if (!create) {
            throw std::runtime_error("Cannot load symbol: " + std::string(dlerror()));
        }
        _instance = create;
    }

    T getInstance() {
        return _instance;
    }

    std::string getName() {
        return _name;
    }

    private:
        void *_handle;
        T _instance;
        std::string _name;
};


#endif /* !DLLOADER_HPP_ */