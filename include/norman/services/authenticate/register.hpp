#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "norman/clients/http_client.hpp"
#include "norman/objects/services/authenticate/register.hpp"

namespace norman::services::authenticate
{
    namespace objects = norman::objects::services::authenticate;

    class Register
    {
    public:
        static void getAuthenticationFactors(const norman::clients::HttpClient &httpClient,
                                             const std::string &token,
                                             const std::string &accountId);

        static nlohmann::json generateApiKey(const norman::clients::HttpClient &httpClient,
                                             const std::string &token,
                                             const objects::register_::RegisterAuthFactorRequest &registerKeyRequest);

        static void registerPassword(const norman::clients::HttpClient &httpClient,
                                     const std::string &token,
                                     const objects::register_::RegisterPasswordRequest &registerPasswordRequest);

        static void registerEmail(const norman::clients::HttpClient &httpClient,
                                  const std::string &token,
                                  const objects::register_::RegisterEmailRequest &registerEmailRequest);

        static void verifyEmail(const norman::clients::HttpClient &httpClient,
                                const std::string &token,
                                const std::string &email,
                                const std::string &code);

        static void resendEmailOtp(const norman::clients::HttpClient &httpClient,
                                   const std::string &token,
                                   const objects::register_::ResendEmailVerificationCodeRequest &resendEmailVerificationCodeRequest);
    };

} // namespace norman::services::authenticate
