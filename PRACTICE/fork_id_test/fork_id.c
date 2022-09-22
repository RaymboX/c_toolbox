#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
#include <errno.h>


int	main(void)
{
	int id;

	id = fork();
	printf("id:%d\n", id);
	return (0);
}