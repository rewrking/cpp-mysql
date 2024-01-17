#pragma once

#if defined(SAPP_MSVC)
	#pragma warning(push)
// #pragma warning(disable : 4189)
#elif defined(SAPP_CLANG)
	#pragma clang diagnostic push
// #pragma clang diagnostic ignored "-Wdelete-non-virtual-dtor"
#else
	#pragma GCC diagnostic push
#endif

#include <mysqlx/xdevapi.h>

#if defined(SAPP_MSVC)
	#pragma warning(pop)
#elif defined(SAPP_CLANG)
	#pragma clang diagnostic push
#else
	#pragma GCC diagnostic pop
#endif

namespace sapp
{
namespace sql = mysqlx;
}