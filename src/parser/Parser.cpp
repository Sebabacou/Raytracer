/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

namespace raytracer {

    void Parser::parseSettings(const libconfig::Setting& setting, std::string type, std::string subtype)
    {
        switch (setting.getType()) {
            case libconfig::Setting::TypeGroup:
                for (int i = 0; i < setting.getLength(); ++i)
                    parseSettings(setting[i], type, subtype);
                break;
            case libconfig::Setting::TypeList:
                _settings.addSubTypeObject(type, setting.getName());
                for (int i = 0; i < setting.getLength(); ++i) {
                    _settings.addEmptyObject(type, setting.getName());
                    for (int j = 0; j < setting[i].getLength(); ++j) {
                        if (setting[i].isGroup())
                            parseSettings(setting[i][j], type, setting.getName());
                        else
                            addSettingValue(setting[i], type, subtype);
                    }
                }
                break;
            default:
                addSettingValue(setting, type, subtype);
                break;
        }
    }

    void Parser::addSettingValue(const libconfig::Setting& setting, std::string type, std::string subtype)
    {
        std::string name = setting.getName();
        switch (setting.getType()) {
            case libconfig::Setting::TypeInt: {
                int value = setting;
                _settings.addParamToObject(type, subtype, name, std::to_string(value));
                break;
            }
            case libconfig::Setting::TypeFloat: {
                double value = setting;
                _settings.addParamToObject(type, subtype, name, std::to_string(value));
                break;
            }
            case libconfig::Setting::TypeString: {
                std::string value = setting.c_str();
                _settings.addParamToObject(type, subtype, name, value);
                break;
            }
            default:
                std::cerr << name << " has an unsupported type: " << setting.getType() << std::endl;
                break;
        }
    }

    bool Parser::parseFile(std::string file)
    {
        try {
            _cfg.readFile(file.c_str());
            for (auto & it : _cfg.getRoot()) {
                _settings.addTypeObject(it.getName());
                parseSettings(it, it.getName());
            }
            _settings.printSettings();
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file: " << file << std::endl;
            return false;
        } catch (const libconfig::ParseException &pex) {
            std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
            return false;
        }
        return true;
    }

}
