#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char buf[1000];
	
	printf("path: %s\n", getcwd(buf, 1000));
	if (argc > 1)
		chdir(argv[1]);
	printf("path: %s\n", getcwd(buf, 1000));
	chdir("");
	printf("path: %s\n", getcwd(buf, 1000));
	printf("errno:%d\n", errno);
	return (0);
}
