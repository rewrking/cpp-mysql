#pragma once

#if (defined(__cpp_exceptions) || defined(__EXCEPTIONS) || defined(_CPPUNWIND))
	#ifndef SAPP_EXCEPTIONS
		#define SAPP_EXCEPTIONS
	#endif

	#define SAPP_THROW(exception) throw exception
	#define SAPP_TRY try
	#define SAPP_CATCH(exception) catch (exception)
	#define SAPP_EXCEPT_ERROR(what) UNUSED(what); // TODO
#else
	#include <cstdlib>
	#define SAPP_THROW(exception) std::abort()
	#define SAPP_TRY if (true)
	#define SAPP_CATCH(exception) if (false)
	#define SAPP_EXCEPT_ERROR(what)
#endif
