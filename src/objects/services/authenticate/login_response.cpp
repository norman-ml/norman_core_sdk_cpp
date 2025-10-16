#include "norman/objects/services/authenticate/login_response.hpp"
#include <sstream>

namespace norman::objects::services::authenticate
{
    LoginResponse::LoginResponse(const std::string &access_token,
                                 const std::string &id_token,
                                 const norman::objects::shared::accounts::Account &account)
        : access_token(access_token),
          id_token(id_token),
          account(account) {}

    LoginResponse::LoginResponse(const nlohmann::json &json)
    {
        access_token = json.at("access_token").get<std::string>();
        id_token = json.at("id_token").get<std::string>();
        auto account_json = json.at("account");
        account = norman::objects::shared::accounts::Account(account_json);
    }

    std::string LoginResponse::toString() const
    {
        std::ostringstream ss;
        ss << "LoginResponse{access_token=<REDACTED>, id_token=<REDACTED>, account=" << account.toString() << "}";
        return ss.str();
    }

}
