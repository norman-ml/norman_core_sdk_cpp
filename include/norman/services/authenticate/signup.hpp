#pragma once

#include <string>

#include "norman/clients/http_client.hpp"
#include "norman/objects/services/authenticate/signup.hpp"
#include "norman/objects/services/authenticate/login_response.hpp"
#include "norman/objects/shared/accounts/account.hpp"


namespace norman::services::authenticate
{
    namespace clients = norman::clients;
    namespace objects = norman::objects::services::authenticate;

    class Signup
    {
    public:
        static objects::LoginResponse signupDefault(const clients::HttpClient &httpClient);

        static norman::objects::shared::accounts::Account signupWithEmail(const clients::HttpClient &httpClient, const objects::signup::SignupEmailRequest& request);
        
        static norman::objects::shared::accounts::Account signupWithPassword(const clients::HttpClient &httpClient, const objects::signup::SignupPasswordRequest& request);
    };
}
