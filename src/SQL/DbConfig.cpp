#include "SQL/DbConfig.hpp"

#include "Libraries/Format.hpp"
#include "Process/Environment.hpp"

namespace sapp
{

/*****************************************************************************/
DbConfig DbConfig::get()
{
	DbConfig conf;

	conf.assignStringFromVariable(conf.m_host, "SAPP_MYSQL_HOST");
	conf.assignStringFromVariable(conf.m_port, "SAPP_MYSQL_PORT");
	conf.assignStringFromVariable(conf.m_user, "SAPP_MYSQL_USER");
	conf.assignStringFromVariable(conf.m_pwd, "SAPP_MYSQL_PWD");
	conf.assignStringFromVariable(conf.m_db, "SAPP_MYSQL_DB");
	conf.validate();

	return conf;
}

/*****************************************************************************/
const std::string& DbConfig::db() const noexcept
{
	return m_db;
}

/*****************************************************************************/
void DbConfig::validate()
{
	if (m_port.find_first_not_of("0123456789") != std::string::npos)
	{
		throw std::runtime_error(fmt::format("invalid port: {}", m_port));
	}

	if (m_host.empty())
	{
		throw std::runtime_error(fmt::format("host was empty: SAPP_MYSQL_HOST was not set.", m_host));
	}
	if (m_port.empty())
	{
		throw std::runtime_error(fmt::format("port was empty: SAPP_MYSQL_PORT was not set.", m_port));
	}
	if (m_user.empty())
	{
		throw std::runtime_error(fmt::format("user was empty: SAPP_MYSQL_USER was not set.", m_user));
	}
	if (m_pwd.empty())
	{
		throw std::runtime_error(fmt::format("pwd was empty: SAPP_MYSQL_PWD was not set.", m_pwd));
	}
	if (m_db.empty())
	{
		throw std::runtime_error(fmt::format("db was empty: SAPP_MYSQL_DB was not set.", m_db));
	}
}

/*****************************************************************************/
void DbConfig::assignStringFromVariable(std::string& outString, const char* inVariable)
{
	auto variable = Environment::get(inVariable);
	if (!variable.empty())
	{
		outString = std::move(variable);
	}
}

/*****************************************************************************/
sql::SessionSettings DbConfig::getSessionSettings() const
{
	return sql::SessionSettings(getPrivateHostName());
}

/*****************************************************************************/
std::string DbConfig::getHostName() const
{
	return fmt::format("mysqlx://{}@{}", m_user, m_host);
}

/*****************************************************************************/
std::string DbConfig::getPrivateHostName() const
{
	return fmt::format("mysqlx://{}:{}@{}:{}", m_user, m_pwd, m_host, m_port);
}
}
