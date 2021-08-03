#pragma once

#ifdef WIN32
  #define ban_EXPORT __declspec(dllexport)
#else
  #define ban_EXPORT
#endif

#ifdef _WIN32
	#define OS "Windows 32-bit"
#elif _WIN64
	#define OS "Windows 64-bit"
#elif __APPLE__ || __MACH__
	#define OS "Mac OSX"
#elif __linux__
	#define OS "Linux"
#elif __FreeBSD__
	#define OS "FreeBSD"
#elif __unix || __unix__
	#define OS "Unix"
#else
	#define OS "Other"
#endif

struct mem_s {
  long available;
  long total;
};

ban_EXPORT void ban(const char *);
