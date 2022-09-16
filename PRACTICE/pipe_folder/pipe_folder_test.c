#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	c;

	fd = open("pipe_temp", O_CREAT | O_WRONLY, 0777);
	write(fd, "test\nc sa que c\n", 16);
	close(fd);
	fd = open("pipe_temp", O_RDONLY);
	while (read(fd, &c, 1) > 0)
		write(1, &c, 1);
	close(fd);
	unlink("pipe_temp");
}
