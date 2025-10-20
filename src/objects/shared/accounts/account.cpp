#include "norman/objects/shared/accounts/account.hpp"
#include <sstream>

namespace norman::objects::shared::accounts
{
    using Account = norman::objects::shared::accounts::Account;

    Account::Account(const std::string &id,
                     const std::string &name,
                     const std::string &creation_time)
        : id(id), name(name), creation_time(creation_time) {}

    Account::Account(const nlohmann::json &json) : Account(
                                                       json.at("id").get<std::string>(),
                                                       json.at("name").get<std::string>(),
                                                       json.at("creation_time").get<std::string>()) {};

    std::string Account::toString() const
    {
        std::ostringstream ss;
        ss << "Account{id=\"" << id
           << "\", name=\"" << name
           << "\", creation_time=\"" << creation_time << "\"}";
        return ss.str();
    }

}
