#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace norman::objects::services::authenticate::login
{
    class ApiKeyLoginRequest
    {
    public:
        std::string account_id;
        std::string api_key;
        
        ApiKeyLoginRequest(const std::string& account_id, const std::string& api_key)
            : account_id(account_id), api_key(api_key) {}

        nlohmann::json toJson() const
        {
            nlohmann::json json_data;
            json_data["account_id"] = account_id;
            json_data["api_key"] = api_key;
            return json_data;
        }
    };

    class AccountIDPasswordLoginRequest
    {
    public:
        std::string account_id;
        std::string password;
        
        AccountIDPasswordLoginRequest(const std::string& account_id, const std::string& password)
            : account_id(account_id), password(password) {}

        nlohmann::json toJson() const
        {
            nlohmann::json json_data;
            json_data["account_id"] = account_id;
            json_data["password"] = password;
            return json_data;
        }
    };

    class NamePasswordLoginRequest
    {
    public:
        std::string name;
        std::string password;
        
        NamePasswordLoginRequest(const std::string& name, const std::string& password)
            : name(name), password(password) {}

        nlohmann::json toJson() const
        {
            nlohmann::json json_data;
            json_data["name"] = name;
            json_data["password"] = password;
            return json_data;
        }
    };

    class EmailPasswordLoginRequest
    {
    public:
        std::string email;
        std::string password;
        
        EmailPasswordLoginRequest(const std::string& email, const std::string& password)
            : email(email), password(password) {}

        nlohmann::json toJson() const
        {
            nlohmann::json json_data;
            json_data["email"] = email;
            json_data["password"] = password;
            return json_data;
        }
    };
}