#pragma once

#include "Libraries/MysqlConnector.hpp"

#include "SQL/DbConfig.hpp"

namespace sapp
{
struct Application
{
	Application() = default;

	i32 run(i32 argc, const char* const argv[]);

private:
	sql::Session getSession(const DbConfig& inConfig) const;
};
}
