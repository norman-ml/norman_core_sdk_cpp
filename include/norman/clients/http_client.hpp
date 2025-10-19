#pragma once

#include <string>
#include <map>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <stdexcept>
#include <sstream>

namespace norman::clients
{

    class HttpClient
    {
    public:
        explicit HttpClient(const std::string &baseUrl);

        nlohmann::json get(const std::string &endpoint,
                           const std::string &token = "",
                           const nlohmann::json &jsonBody = {}) const;

        nlohmann::json post(const std::string &endpoint,
                            const std::string &token = "",
                            const nlohmann::json &jsonBody = {}) const;

        nlohmann::json put(const std::string &endpoint,
                           const std::string &token = "",
                           const nlohmann::json &jsonBody = {}) const;

        nlohmann::json del(const std::string &endpoint,
                           const std::string &token = "",
                           const nlohmann::json &jsonBody = {}) const;

        nlohmann::json patch(const std::string &endpoint,
                             const std::string &token = "",
                             const nlohmann::json &jsonBody = {}) const;

        std::stringstream stream(const std::string &endpoint,
                                 const std::string &token = "",
                                 const nlohmann::json &jsonBody = {}) const;

    private:
        std::string baseUrl;
        nlohmann::json request(const std::string &method,
                               const std::string &endpoint,
                               const std::string &token,
                               const nlohmann::json &jsonBody) const;
    };
}
