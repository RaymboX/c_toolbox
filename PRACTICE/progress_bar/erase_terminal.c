#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	write(1, "Bonjour", 7);
	write(1, "\b\b\b\bl", 5);
	write(1, "\n", 1);
	return (0);
}