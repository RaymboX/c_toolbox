
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
# include <stdlib.h>

int	main(void)
{
	int fd_in;
	int fd_file;
	int id;

	fd_file = open("file", O_RDWR, S_IRUSR | S_IWUSR);
	id = fork();
	if (id == 0)
	{
		fd_in = dup(1);
		dup2(fd_file, 1);
	}
	else
		wait(0);
	printf("id:%d\n", id);
	return (0);
}