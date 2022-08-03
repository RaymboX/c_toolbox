#include <sys/errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void other_fct(void)
{
	printf("Errno:%d\n", errno);
	open("file2", O_RDWR); 
}

int main(void)
{
	int fd;

	
	printf("Errno:%d\n", errno);
	//fd = open("file2", O_RDWR); 
	//printf("Errno:%d\n", errno);
	other_fct();
	printf("Errno:%d\n", errno);
	fd = open("file", O_RDWR);
	//errno = 0;
	printf("Errno:%d\n", errno);
	printf("fd:%d\n", fd);
	return (0);
}

