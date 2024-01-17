#pragma once

#include "Libraries/MysqlConnector.hpp"

namespace sapp
{
struct DbConfig
{
	static DbConfig get();

	const std::string& db() const noexcept;

	void validate();

	void assignStringFromVariable(std::string& outString, const char* inVariable);

	sql::SessionSettings getSessionSettings() const;
	std::string getHostName() const;

private:
	std::string getPrivateHostName() const;

	std::string m_host = "localhost";
	std::string m_port = "33060";
	std::string m_user;
	std::string m_pwd;
	std::string m_db;
};
}
