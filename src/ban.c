#ifdef WIN32
    #include <Windows.h>
    #include <tchar.h>
#else
    #include <unistd.h>
#endif

#include <stdio.h>
#include "ban.h"

static void get_hostname(char *, size_t);

void ban(const char *name) {
	#ifdef NDEBUG
	puts("ban/0.1: Hello World Release!");
	#else
	puts("ban/0.1: Hello World Release!");
	#endif

	char hostname[150] = {0};
	get_hostname(hostname, 150);

	printf("%s %s\n", name, hostname);
}

static void get_hostname(char *hostname, size_t length) {
	#ifdef WIN32
	DWORD size = length;
	GetComputerName(hostname, &size)
	#else
	gethostname(hostname, length);
	#endif
}
