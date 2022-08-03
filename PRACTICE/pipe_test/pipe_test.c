#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int	fd[2];
	int	len;
	char buf;

	pipe(fd);
	write(fd[1], "0", 1);
	len = read(fd[0], &buf, 1);
	printf("len:%d buf:%c\n", len, buf);
	write(fd[1], "12", 2);
	len = read(fd[0], &buf, 1);
	printf("len:%d buf:%c\n", len, buf);
	write(fd[1], "3", 1);
	len = read(fd[0], &buf, 1);
	printf("len:%d buf:%c\n", len, buf);
	len = read(fd[0], &buf, 1);
	printf("len:%d buf:%c\n", len, buf);
	return (0);
}