#include <fcntl.h>
#include <stdio.h>
#include <sys/errno.h>
#include <unistd.h>

void clear_file(int fd)
{
	int	ret;
	int i;

	ret = 1;
	i = 0;
	while (ret > 0)
	{
		ret = write(fd, "\0", ++i);
		printf("%d\n", ret);
	}
	
}

int	main(void)
{
	int	fd;

	fd = open("filenew", O_RDWR | O_CREAT, 0777);
	write(fd, "line1\nline2\nline3", 17);
	close(fd);
	fd = open("filenew", O_RDWR | O_TRUNC, 0777);
	close(fd);
	return (0);
}

