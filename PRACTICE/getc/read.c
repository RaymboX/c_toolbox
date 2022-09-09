#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int	main(void)
{
	char c;
	
	
	
	while (read(0, &c, 1) == 0){}
	printf("%d\n", c);
	return (0);
}