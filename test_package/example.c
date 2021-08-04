#include <stdio.h>

#include "ban.h"

int
main(int argc, char **argv)
{
	char banner[256] = {'\0'};

	ban(argv[0], banner, 256);
	puts(banner);

	return 0;
}
