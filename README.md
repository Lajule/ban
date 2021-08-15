# ban
Add startup banners into your C applications.

## Example

```c
#include <stdio.h>

#include "ban.h"

int
main(int argc, char **argv)
{
	char banner[256] = {'\0'};
	bant(argv[0], "@NAME@ - @OS@ - @MEM@", banner, 256);
	puts(banner);
	return 0;
}
```

Compile previous program before running :

```sh
./example
./example - Linux - 805.98M/1.94G
````

## Template

| Placeholder | Description |
| ----------- | ----------- |
| @NAME@ | Binary name |
| @HOSTNAME@ | Hostname |
| @OS@ | Operating system name |
| @MEM@ | Available and total memory |
| @TIME@ | Current time |
