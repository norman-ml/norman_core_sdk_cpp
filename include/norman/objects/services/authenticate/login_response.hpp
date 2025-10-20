#pragma once

#include <string>

#include <nlohmann/json.hpp>

#include "norman/objects/shared/accounts/account.hpp"

namespace norman::objects::services::authenticate
{
    class LoginResponse
    {
    public:
		std::string access_token;
		std::string id_token;
		norman::objects::shared::accounts::Account account;

        LoginResponse() = default;
        LoginResponse(const std::string& access_token, const std::string& id_token, const norman::objects::shared::accounts::Account& account);
		LoginResponse(const nlohmann::json& json);
        std::string toString() const;
    };
}
