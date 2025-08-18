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

#define BIT(x) (1 << x) // shift by one place