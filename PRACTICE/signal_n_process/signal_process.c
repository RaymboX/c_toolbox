#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int	id;

void	signal_handler(int signal)
{
	printf("id:%d signal:%d\n", id, signal);
	exit(0);
}


int	main(void)
{
	signal(SIGINT, signal_handler);
	id = fork();
	sleep(10);
	return(0);
}