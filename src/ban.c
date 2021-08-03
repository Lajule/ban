#ifdef WIN32
#include <Windows.h>
#include <tchar.h>
#else
#include <unistd.h>
#include <sys/sysinfo.h>
#endif

#include <stdio.h>
#include "ban.h"

static void get_hostname(char *, size_t);
static const char *get_os();
static long get_cores();
static void get_mem();

void ban(const char *name) {
	#ifdef NDEBUG
	puts("ban/0.1: Hello World Release!");
	#else
	puts("ban/0.1: Hello World Release!");
	#endif

	char hostname[150] = {'\0'};
	get_hostname(hostname, 150);

	const char *os = get_os();

	long cores = get_cores();

	get_mem();

	printf("%s %s %s %.ld\n", name, hostname, os, cores);
}

static void get_hostname(char *hostname, size_t length) {
	#ifdef WIN32
	DWORD size = length;
	GetComputerName(hostname, &size)
	#else
	gethostname(hostname, length);
	#endif
}

static const char *get_os() {
	#ifdef _WIN32
	return "Windows 32-bit";
	#elif _WIN64
	return "Windows 64-bit";
	#elif __APPLE__ || __MACH__
	return "Mac OSX";
	#elif __linux__
	return "Linux";
	#elif __FreeBSD__
	return "FreeBSD";
	#elif __unix || __unix__
	return "Unix";
	#else
	return "Other";
	#endif
}

static long get_cores() {
	#ifdef WIN32
	SYSTEM_INFO info = {.dwNumberOfProcessors=0};
	GetSystemInfo(&info);
	return info.dwNumberOfProcessors
	#else
	return sysconf(_SC_NPROCESSORS_ONLN);
	#endif
}

static void get_mem() {
	#ifdef WIN32
	MEMORYSTATUS status;
	GlobalMemoryStatus(&status)
	#else
	struct sysinfo info;
	sysinfo(&info);
	#endif
}
