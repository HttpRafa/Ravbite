#pragma once

#ifdef RB_PLATFORM_WINDOWS
#ifdef RB_BUILD_DLL
#define RB_API __declspec(dllexport)
#else
#define RB_API __declspec(dllimport)
#endif
#else


#endif