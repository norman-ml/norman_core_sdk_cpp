#include "norman/clients/http_client.hpp"

using json = nlohmann::json;
using HttpClient = norman::clients::HttpClient;

HttpClient::HttpClient(const std::string &baseUrl)
    : baseUrl(baseUrl) {}

json HttpClient::request(const std::string &method,
                         const std::string &endpoint,
                         const std::string &token,
                         const json &jsonBody) const
{
    cpr::Header headers{{"Content-Type", "application/json"}};
    if (!token.empty())
    {
        headers["Authorization"] = "Bearer " + token;
    }

    cpr::Response response;

    std::string url = baseUrl + endpoint;
    std::string body = jsonBody.dump();

    if (method == "GET")
    {
        response = cpr::Get(cpr::Url{url}, headers, cpr::Body{body});
    }
    else if (method == "POST")
    {
        response = cpr::Post(cpr::Url{url}, headers, cpr::Body{body});
    }
    else if (method == "PUT")
    {
        response = cpr::Put(cpr::Url{url}, headers, cpr::Body{body});
    }
    else if (method == "DELETE")
    {
        response = cpr::Delete(cpr::Url{url}, headers, cpr::Body{body});
    }
    else if (method == "PATCH")
    {
        response = cpr::Patch(cpr::Url{url}, headers, cpr::Body{body});
    }
    else
    {
        throw std::invalid_argument("Unsupported HTTP method: " + method);
    }

    if (response.status_code != 200)
    {
        throw std::runtime_error(
            "HTTP error " + std::to_string(response.status_code) + ": " + response.text);
    }

    try
    {
        return json::parse(response.text);
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error(std::string("Invalid JSON: ") + e.what());
    }
}

json HttpClient::get(const std::string &endpoint, const std::string &token, const json &jsonBody) const
{
    return request("GET", endpoint, token, jsonBody);
}

json HttpClient::post(const std::string &endpoint, const std::string &token, const json &jsonBody) const
{
    return request("POST", endpoint, token, jsonBody);
}

json HttpClient::put(const std::string &endpoint, const std::string &token, const json &jsonBody) const
{
    return request("PUT", endpoint, token, jsonBody);
}

json HttpClient::del(const std::string &endpoint, const std::string &token, const json &jsonBody) const
{
    return request("DELETE", endpoint, token, jsonBody);
}

json HttpClient::patch(const std::string &endpoint, const std::string &token, const json &jsonBody) const
{
    return request("PATCH", endpoint, token, jsonBody);
}

std::stringstream HttpClient::stream(const std::string &endpoint,
                                     const std::string &token,
                                     const json &jsonBody) const
{
    cpr::Header headers{{"Content-Type", "application/json"}};
    if (!token.empty())
    {
        headers["Authorization"] = "Bearer " + token;
    }

    std::string url = baseUrl + endpoint;
    cpr::Response response = cpr::Get(cpr::Url{url}, headers, cpr::Body{jsonBody.dump()});

    if (response.status_code != 200)
    {
        throw std::runtime_error(
            "HTTP error " + std::to_string(response.status_code) + ": " + response.text);
    }

    std::stringstream ss;
    ss << response.text;
    return ss;
}
