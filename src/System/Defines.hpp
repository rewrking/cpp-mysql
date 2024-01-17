#pragma once

#if defined(__APPLE__)
	#include <TargetConditionals.h>
#endif

#if defined(_DEBUG) || defined(DEBUG)
	#ifndef SAPP_DEBUG
		#define SAPP_DEBUG
	#endif
#endif

#if defined(__APPLE__)
	#ifndef SAPP_MACOS
		#define SAPP_MACOS
	#endif
	#if defined(TARGET_CPU_ARM64) && TARGET_CPU_ARM64
		#define SAPP_MACOS_ARM64
	#endif
#elif defined(__linux__)
	#ifndef SAPP_LINUX
		#define SAPP_LINUX
	#endif
	#if defined(WSLENV)
		#ifndef SAPP_WSL
			#define SAPP_WSL
		#endif
	#endif
	#if defined(__arm__)
		#ifndef SAPP_LINUX_ARM
			#define SAPP_LINUX_ARM
		#endif
	#endif
#elif defined(_WIN32)
	#ifndef SAPP_WIN32
		#define SAPP_WIN32
	#endif
#else
// static_assert(false, "Unknown platform");
	#error "Unknown platform"
#endif

#if defined(__clang__)
	#define SAPP_CLANG
#endif

#if defined(_MSC_VER)
	#define SAPP_MSVC
#elif defined(__GNUC__)
	#define SAPP_GCC
#endif

#if defined(SAPP_WIN32)
	#define SAPP_EXIT_SUCCESS EXIT_SUCCESS
	#define SAPP_EXIT_FAILURE 1067
#else
	#define SAPP_EXIT_SUCCESS EXIT_SUCCESS
	#define SAPP_EXIT_FAILURE EXIT_FAILURE
#endif

#if defined(SAPP_DEBUG)
	#define SAPP_ENABLE_LOGGING
#endif

#include "System/DefinesExceptions.hpp"
