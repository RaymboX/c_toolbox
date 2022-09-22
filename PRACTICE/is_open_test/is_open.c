#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define FILE_NAME "file1"

void fct_routine(char *fct_name, int ret)
{
	printf("%s return:%d errno:%d %s\n", fct_name, ret, errno, strerror(errno));
	errno = 0;
}

void fct_test(int fd)
{
	int ret;

	ret = 0;
	printf("control return:%d errno:%d text:%s\n", ret, errno, strerror(errno));
	ret = ioctl(fd, 0);
	fct_routine("ioctl", ret);
	ret = isatty(fd);
	fct_routine("isatty", ret);
	ret = close(fd);
	fct_routine("close", ret);
	if (ret == 0)
		printf("fd %d is close\n", fd);
}

// keep the value of errno for close function. Return close function status
int close_noerr(int fd)
{
	int	temp_err;
	int	ret;

	temp_err = errno;
	ret = close(fd);
	errno = temp_err;
	return (ret);
}


int main(void)
{
	int fd;

	fd = open(FILE_NAME, O_CREAT | O_RDWR, 0777);
	if (fd < 0)
		return (printf("fail opening file\n"));
	printf("fd %d is open\n", fd);
	fct_test(fd);
	fct_test(fd);
	isatty(fd);
	return (0);
}

