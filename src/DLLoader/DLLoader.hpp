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
#include <DLSym.hpp>

    class DLLoader {
        public:
            /**
             * @brief Construct a new DLLoader object
             *
             * @param path path to the library
             * @param entryPoint name of the function to load
             */
            DLLoader(std::string path, std::string entryPoint) {
                try {
                    _handle = dlopen(path.c_str(), RTLD_LAZY);
                    if (!_handle) {
                        throw std::runtime_error("Cannot open library: " + std::string(dlerror()));
                    }
                } catch (const std::exception &e) {
                    throw std::runtime_error("Cannot open library: " + std::string(dlerror()));
                }
            }

            /**
             * @brief Destroy the DLLoader object
             *
             */
            ~DLLoader() {
                if (_handle) {
                    dlclose(_handle);
                }
            }

            template<typename T>
            T getFunction(const std::string &entryPoint) {
                try {
                    DLSym<T> sym(_handle);
                    return sym.getFunction(entryPoint);
                } catch (const std::exception &e) {
                    throw std::runtime_error("Cannot load symbol: " + std::string(dlerror()));
                }
            }

        private:
            void std::shared_ptr<void> _handle;
    };


#endif /* !DLLOADER_HPP_ */
