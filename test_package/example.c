#include <stdio.h>

#include "ban.h"

int
main(int argc, char **argv) {
	char banner[256] = {'\0'};
	bant(argv[0], argv[1], banner, 256);
	puts(banner);
	return 0;
}
