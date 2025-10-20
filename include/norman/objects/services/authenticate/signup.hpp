#pragma once

#include <nlohmann/json.hpp>

namespace norman::objects::services::authenticate::signup
{
    class SignupPasswordRequest
    {
    public:
        std::string name;
        std::string password;

        SignupPasswordRequest(const std::string &name, const std::string &password) 
            : name(name), password(password) {}

        nlohmann::json toJson() const
        {
            nlohmann::json json_data;
            json_data["name"] = name;
            json_data["password"] = password;
            return json_data;
        }
    };

    class SignupEmailRequest
    {
    public:
        std::string name;
        std::string email;

        SignupEmailRequest(const std::string &name, const std::string &email, const std::string &password) 
            : name(name), email(email) {}

        nlohmann::json toJson() const
        {
            nlohmann::json json_data;
            json_data["name"] = name;
            json_data["email"] = email;
            return json_data;
        }
    };
}