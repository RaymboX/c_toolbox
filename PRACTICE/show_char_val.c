#include <stdio.h>

int	main(int argc, char **argv)
{
	
	if (argc == 2)
		printf("%c:%d\n", argv[1][0], (int)argv[1][0]);
	return (0);
}
