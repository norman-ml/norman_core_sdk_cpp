#include "norman/services/authenticate/register.hpp"
#include <nlohmann/json.hpp>

namespace norman::services::authenticate
{
    using NormanHttpClient = norman::clients::HttpClient;
    using namespace norman::objects::services::authenticate::register_;

    void Register::getAuthenticationFactors(const NormanHttpClient &httpClient,
                                            const std::string &token,
                                            const std::string &accountId)
    {
        httpClient.get("authenticate/register/get/authentication/factors/" + accountId,
                       token,
                       nlohmann::json{});
    }

    nlohmann::json Register::generateApiKey(const NormanHttpClient &httpClient,
                                            const std::string &token,
                                            const RegisterAuthFactorRequest &registerKeyRequest)
    {
        return httpClient.post("authenticate/generate/key",
                               token,
                               registerKeyRequest.toJson());
    }

    void Register::registerPassword(const NormanHttpClient &httpClient,
                                    const std::string &token,
                                    const RegisterPasswordRequest &registerPasswordRequest)
    {
        httpClient.post("authenticate/register/password",
                        token,
                        registerPasswordRequest.toJson());
    }

    void Register::registerEmail(const NormanHttpClient &httpClient,
                                 const std::string &token,
                                 const RegisterEmailRequest &registerEmailRequest)
    {
        httpClient.post("authenticate/register/email",
                        token,
                        registerEmailRequest.toJson());
    }

    void Register::verifyEmail(const NormanHttpClient &httpClient,
                               const std::string &token,
                               const std::string &email,
                               const std::string &code)
    {
        httpClient.post("authenticate/register/email/verify/" + email + "/" + code,
                        token,
                        nlohmann::json{});
    }

    void Register::resendEmailOtp(const NormanHttpClient &httpClient,
                                  const std::string &token,
                                  const ResendEmailVerificationCodeRequest &resendEmailVerificationCodeRequest)
    {
        httpClient.post("authenticate/register/email/resend/otp",
                        token,
                        resendEmailVerificationCodeRequest.toJson());
    }

} // namespace norman::services::authenticate
