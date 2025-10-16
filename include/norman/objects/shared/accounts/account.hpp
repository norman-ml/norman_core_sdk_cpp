#pragma once

#include <string>

#include <nlohmann/json.hpp>

namespace norman::objects::shared::accounts {
	class Account {
	public:
		std::string id;
		std::string name;
		std::string creation_time;

		Account(const std::string& id, const std::string& name, const std::string& creation_time);
		Account(const nlohmann::json& json);
		std::string Account::toString() const;

		Account() = default;
		~Account() = default;
	};
}