#include <string.h>
#include <sys/errno.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	printf("%s\n", strerror(errno));
	open("filenotexist", O_RDWR);
	printf("test: %s\n", strerror(errno));
	perror("test");
	printf("%d\n", errno);
	return (errno);
}