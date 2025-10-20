#pragma once

#include <string>

#include "norman/clients/http_client.hpp"
#include "norman/objects/services/authenticate/login.hpp"
#include "norman/objects/services/authenticate/login_response.hpp"

namespace norman::services::authenticate
{
    namespace clients = norman::clients;
    namespace objects = norman::objects::services::authenticate;

    class Login
    {
    public:
        static objects::LoginResponse loginDefault(const clients::HttpClient &httpClient, const std::string &accountId);

        static objects::LoginResponse loginWithKey(const clients::HttpClient &httpClient, const objects::login::ApiKeyLoginRequest &request);

        static objects::LoginResponse loginPasswordAccountId(const clients::HttpClient &httpClient, const objects::login::AccountIDPasswordLoginRequest &request);

        static objects::LoginResponse loginPasswordName(const clients::HttpClient &httpClient, const objects::login::NamePasswordLoginRequest &request);

        static objects::LoginResponse loginPasswordEmail(const clients::HttpClient &httpClient, const objects::login::EmailPasswordLoginRequest &request);

        static void loginEmailOtp(const clients::HttpClient &httpClient, const std::string &email);

        static objects::LoginResponse verifyEmailOtp(const clients::HttpClient &httpClient,
                                                     const std::string &email,
                                                     const std::string &code);
    };
}
