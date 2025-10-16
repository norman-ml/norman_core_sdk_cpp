#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>

namespace norman::utils
{
    using json = nlohmann::json;
    class JsonConfig
    {
    private:
        json config;

    public:
        bool load(const std::string &filename);
        
        template <typename T>
        T get(const std::string &path, T defaultValue = T()) const;
    };
}