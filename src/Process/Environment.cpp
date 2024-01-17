#include "Process/Environment.hpp"

#include "Libraries/Format.hpp"

#if defined(SAPP_MSVC)
	#define putenv _putenv
	#pragma warning(push)
	#pragma warning(disable : 4996)
#endif

namespace sapp
{
/*****************************************************************************/
std::string Environment::get(const char* inName)
{
	const char* result = ::getenv(inName);
	if (result != nullptr)
		return std::string(result);

	return std::string();
}

/*****************************************************************************/
bool Environment::set(const char* inName, const std::string& inValue)
{
#if defined(SAPP_WIN32)
	std::string outValue = fmt::format("{}={}", inName, inValue);
	// LOG(outValue);
	i32 result = ::putenv(outValue.c_str());
#else
	i32 result = 0;
	if (!inValue.empty())
		result = ::setenv(inName, inValue.c_str(), true);
	else
		::unsetenv(inName);
#endif

	return result == 0;
}

}
