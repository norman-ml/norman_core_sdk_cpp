#include "norman/utils/json_config.hpp"

namespace norman::utils
{
    bool JsonConfig::load(const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Error: Cannot open " << filename << std::endl;
            return false;
        }

        try
        {
            file >> config;
            return true;
        }
        catch (const json::parse_error &e)
        {
            std::cerr << "JSON Parse Error: " << e.what() << std::endl;
            return false;
        }
    }

    template <typename T>
    T JsonConfig::get(const std::string &path, T defaultValue) const
    {
        try
        {
            std::istringstream iss(path);
            std::string token;
            const json *current = &config;

            while (std::getline(iss, token, '.'))
            {
                if (current->is_object() && current->contains(token))
                    current = &((*current)[token]);
                else
                    return defaultValue;
            }
            return current->get<T>();
        }
        catch (...)
        {
            return defaultValue;
        }
    }


    template std::string JsonConfig::get<std::string>(const std::string &, std::string) const;
    template int JsonConfig::get<int>(const std::string &, int) const;
    template double JsonConfig::get<double>(const std::string &, double) const;
    template bool JsonConfig::get<bool>(const std::string &, bool) const;
    template json JsonConfig::get<json>(const std::string &, json) const;
}