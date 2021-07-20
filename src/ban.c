#include <stdio.h>
#include "ban.h"

void ban() {
	#ifdef NDEBUG
	puts("ban/0.1: Hello World Release!");
	#else
	puts("ban/0.1: Hello World Release!");
	#endif
}
