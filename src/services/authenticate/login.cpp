#include "norman/services/authenticate/login.hpp"

namespace norman::services::authenticate
{
    using LoginResponse = norman::objects::services::authenticate::LoginResponse;
    using NormanHttpClient = norman::clients::HttpClient;
    using namespace norman::objects::services::authenticate::login;

    LoginResponse Login::loginDefault(const NormanHttpClient &httpClient,
                                      const std::string &accountId)
    {
        auto response_json = httpClient.post("authenticate/login/default/" + accountId);
        return LoginResponse(response_json);
    }

    LoginResponse Login::loginWithKey(const NormanHttpClient &httpClient,
                                      const ApiKeyLoginRequest &request)
    {
        auto json_body = request.toJson();
        auto response_json = httpClient.post(
            "authenticate/login/key",
            "",
            json_body);

        return LoginResponse(response_json);
    }

    LoginResponse Login::loginPasswordAccountId(const NormanHttpClient &httpClient,
                                                const AccountIDPasswordLoginRequest &request)
    {
        auto json_body = request.toJson();
        auto response_json = httpClient.post(
            "authenticate/login/password/account_id",
            "",
            json_body);

        return LoginResponse(response_json);
    }

    LoginResponse Login::loginPasswordName(const NormanHttpClient &httpClient,
                                           const NamePasswordLoginRequest &request)
    {
        auto json_body = request.toJson();
        auto response_json = httpClient.post(
            "authenticate/login/password/name",
            "",
            json_body);

        return LoginResponse(response_json);
    }

    LoginResponse Login::loginPasswordEmail(const NormanHttpClient &httpClient,
                                            const EmailPasswordLoginRequest &request)
    {
        auto json_body = request.toJson();
        auto response_json = httpClient.post(
            "authenticate/login/password/email",
            "",
            json_body);

        return LoginResponse(response_json);
    }

    void Login::loginEmailOtp(const NormanHttpClient &httpClient,
                              const std::string &email)
    {
        nlohmann::json json_body = {{"email", email}};
        httpClient.post("authenticate/login/email/otp", "", json_body);
    }

    LoginResponse Login::verifyEmailOtp(const NormanHttpClient &httpClient,
                                        const std::string &email,
                                        const std::string &code)
    {
        nlohmann::json json_body = {
            {"email", email},
            {"code", code}};

        auto response_json = httpClient.post(
            "authenticate/login/email/otp/verify",
            "",
            json_body);

        return LoginResponse(response_json);
    }

}
