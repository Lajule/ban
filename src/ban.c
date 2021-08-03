#ifdef WIN32
#include <Windows.h>
#include <tchar.h>
#else
#include <unistd.h>
#include <sys/sysinfo.h>
#endif

#include <stdio.h>
#include <string.h>
#include "ban.h"

static void get_hostname(char *, size_t);
static void get_os(char *, size_t);
static void get_cores(long *);
static void get_mem(struct mem_s *);

void ban(const char *name) {
	#ifdef NDEBUG
	puts("ban/0.1: Hello World Release!");
	#else
	puts("ban/0.1: Hello World Release!");
	#endif

	char hostname[150] = {'\0'};
	get_hostname(hostname, 150);

	char os[150] = {'\0'};
	get_os(os, 150);

	long cores = 0;
	get_cores(&cores);

	struct mem_s mem = {.available=0, .total=0};
	get_mem(&mem);

	printf("%s %s %s %.ld %.ldB/%.ldB\n", name, hostname, os, cores, mem.available, mem.total);
}

static void get_hostname(char *hostname, size_t length) {
	#ifdef WIN32
	DWORD size = length;
	GetComputerName(hostname, &size);
	#else
	gethostname(hostname, length);
	#endif
}

static void get_os(char *os, size_t length) {
	strncpy(os, OS, length);
}

static void get_cores(long *cores) {
	#ifdef WIN32
	SYSTEM_INFO info = {.dwNumberOfProcessors=0};
	GetSystemInfo(&info);
	*cores = info.dwNumberOfProcessors;
	#else
	*cores = sysconf(_SC_NPROCESSORS_ONLN);
	#endif
}

static void get_mem(struct mem_s *mem) {
	#ifdef WIN32
	MEMORYSTATUS status = {.dwTotalPhys=0, .dwAvailPhys=0};
	GlobalMemoryStatus(&status);
	mem->available = status.dwAvailPhys;
	mem->total = status.dwTotalPhys;
	#else
	struct sysinfo info;
	sysinfo(&info);
	mem->available = info.freeram * info.mem_unit;
	mem->total = info.totalram * info.mem_unit;
	#endif
}
