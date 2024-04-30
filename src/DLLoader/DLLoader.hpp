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

class DLLoader {
public:
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
        if (_handle)
            dlclose(_handle);
    }

    template<typename T>

     T getInstance(const std::string &name) {
        T create = (T)dlsym(_handle, name.c_str());
        if (!create) {
            throw std::runtime_error("Cannot load symbol: " + std::string(dlerror()));
        }
        return create;
    }

    private:
        void *_handle;
};


#endif /* !DLLOADER_HPP_ */