#pragma once

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace norman::objects::services::authenticate::register_
{
    class RegisterAuthFactorRequest
    {
    public:
        std::string account_id;
        std::optional<std::string> second_token;

        RegisterAuthFactorRequest(const std::string& account_id, 
                                 const std::optional<std::string>& second_token = std::nullopt)
            : account_id(account_id), second_token(second_token) {}

        virtual nlohmann::json toJson() const
        {
            nlohmann::json json_data;
            json_data["account_id"] = account_id;
            if (second_token.has_value()) {
                json_data["second_token"] = second_token.value();
            }
            return json_data;
        }
    };

    class RegisterPasswordRequest : public RegisterAuthFactorRequest
    {
    public:
        std::string password;

        RegisterPasswordRequest(const std::string& account_id, 
                               const std::string& password,
                               const std::optional<std::string>& second_token = std::nullopt)
            : RegisterAuthFactorRequest(account_id, second_token), password(password) {}

        nlohmann::json toJson() const override
        {
            nlohmann::json json_data = RegisterAuthFactorRequest::toJson();
            json_data["password"] = password;
            return json_data;
        }
    };

    class RegisterEmailRequest : public RegisterAuthFactorRequest
    {
    public:
        std::string email;

        RegisterEmailRequest(const std::string& account_id, 
                            const std::string& email,
                            const std::optional<std::string>& second_token = std::nullopt)
            : RegisterAuthFactorRequest(account_id, second_token), email(email) {}

        nlohmann::json toJson() const override
        {
            nlohmann::json json_data = RegisterAuthFactorRequest::toJson();
            json_data["email"] = email;
            return json_data;
        }
    };

    class ResendEmailVerificationCodeRequest : public RegisterAuthFactorRequest
    {
    public:
        std::string email;

        ResendEmailVerificationCodeRequest(const std::string& account_id, 
                                          const std::string& email,
                                          const std::optional<std::string>& second_token = std::nullopt)
            : RegisterAuthFactorRequest(account_id, second_token), email(email) {}

        nlohmann::json toJson() const override
        {
            nlohmann::json json_data = RegisterAuthFactorRequest::toJson();
            json_data["email"] = email;
            return json_data;
        }
    };
}