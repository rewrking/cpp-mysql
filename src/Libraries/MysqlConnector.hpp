#pragma once

#if defined(SAPP_MSVC)
	#pragma warning(push)
// #pragma warning(disable : 4189)
#else
	#pragma GCC diagnostic push
// #pragma GCC diagnostic ignored "-Wpedantic"
// #pragma GCC diagnostic ignored "-Wunused-parameter"
// #pragma GCC diagnostic ignored "-Wtype-limits"
// #pragma GCC diagnostic ignored "-Wshadow"
// #pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include <mysqlx/xdevapi.h>

#if defined(SAPP_MSVC)
	#pragma warning(pop)
#else
	#pragma GCC diagnostic pop
#endif

namespace sapp
{
namespace sql = mysqlx;
}