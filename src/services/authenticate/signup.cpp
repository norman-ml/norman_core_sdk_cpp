#include "norman/services/authenticate/signup.hpp"

namespace norman::services::authenticate
{
    using namespace norman::objects::services::authenticate::signup;
    using LoginResponse = norman::objects::services::authenticate::LoginResponse;
    using NormanHttpClient = norman::clients::HttpClient;
    using Account = norman::objects::shared::accounts::Account;

    LoginResponse Signup::signupDefault(const NormanHttpClient &httpClient)
    {
        auto response_raw = httpClient.put("authenticate/signup/default");
        return LoginResponse(response_raw);
    }

    Account Signup::signupWithEmail(const NormanHttpClient &httpClient, const SignupEmailRequest& request)
    {
        auto response = httpClient.put("authenticate/signup/password", "", request.toJson());
        return Account(response);
    }

    Account Signup::signupWithPassword(const NormanHttpClient &httpClient, const SignupPasswordRequest& request)
    {
        auto response = httpClient.put("authenticate/signup/email", "", request.toJson());
        return Account(response);
    }
}
