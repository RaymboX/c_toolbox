#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	i;
	char *ptr;

	ptr = malloc(sizeof(char));
	i = 5234;
	printf("%p\n", ptr);
	return (0);
}