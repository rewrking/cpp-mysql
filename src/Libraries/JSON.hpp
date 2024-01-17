#pragma once

#if defined(SAPP_MSVC)
// #pragma warning(push)
// #pragma warning(disable : 4100)
#else
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wpedantic"
	#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#include <nlohmann/json.hpp>

#if defined(SAPP_MSVC)
// #pragma warning(pop)
#else
	#pragma GCC diagnostic pop
#endif

inline nlohmann::ordered_json operator"" _ojson(const char* s, std::size_t n)
{
	return nlohmann::ordered_json::parse(s, s + n);
}

namespace sapp
{
using Json = nlohmann::ordered_json;
using JsonDataType = nlohmann::detail::value_t;
}
