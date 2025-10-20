#include <exception>

#include <fmt/core.h>

#include "norman/utils/json_config.hpp"
#include "norman/clients/http_client.hpp"
#include "norman/services/authenticate/signup.hpp"


int main() {
    try {
        fmt::println("Establishing connection");
        auto config = norman::utils::JsonConfig();

        std::string filePath = "./norman_config.json";

        config.load(filePath);

        norman::clients::HttpClient client(config.get<std::string>("baseUrl"));

        auto res = norman::services::authenticate::Signup::signupDefault(client);
        fmt::println("Got response: {}", res.toString());
    }
    catch (const std::exception& e) {
        fmt::println(stderr, "Exception: {}", e.what());
        return 1;
    }
    catch (...) {
        fmt::println(stderr, "Unknown error occurred");
        return 1;
    }

    return 0;
}
