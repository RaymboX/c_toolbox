
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
#include <errno.h>

int *get_id(void)
{
	static int	*id;

	if (id == NULL)
		id = (int *)malloc(sizeof(int));
	return (id);
}

void	signal_handler(int signal)
{
	int	*id;

	id = get_id();
	printf("\nHI signal:%d id:%d errno:%d\n", signal, *id, errno);
}

int	main(void)
{
	int fd_in;
	int fd_file;
	int id;
	int *ptr_id;

	signal(SIGINT, signal_handler);
	fd_file = open("file", O_RDWR, S_IRUSR | S_IWUSR);
	id = fork();
	ptr_id = get_id();
	*ptr_id = id;
	if (id == 0)
	{
		//fd_in = dup(1);
		//dup2(fd_file, 1);
		while(1){}
	}
	else
		wait(0);
	printf("id:%d\n", id);
	return (0);
}