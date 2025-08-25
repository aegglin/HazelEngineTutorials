#pragma once

/* These macros either export or import symbols depending on where they're run from */

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL //only defined for Hazel, not Sandbox, so we export from Hazel and import for Sandbox
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif


#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) {if(!(x)) { HZ_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HZ_CORE_ASSERT(x, ...) { if (!(x)) HZ_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); }
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x) // shift by one place