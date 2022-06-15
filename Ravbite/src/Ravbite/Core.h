#pragma once

#ifdef RB_PLATFORM_WINDOWS
#ifdef RB_BUILD_DLL
#define RAVBITE_API __declspec(dllexport)
#else
#define RAVBITE_API __declspec(dllimport)
#endif
#else
#endif

#define BIT(x) (1 << x)