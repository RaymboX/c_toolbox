#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <time.h>

int	main(void)
{
	char	c;
	int		fd;

	fd = open("input.txt", O_RDWR | O_CREAT, 0777);
	c = '0';
	dup2(fd, 0);
	write(fd, &c, 1);
	while (c != '!')
	{
		lseek(fd, SEEK_SET, 0);
		if (c == '!')
			printf("%c\n", c);
		write(fd, &c, 1);
	}
	return (0);
}
