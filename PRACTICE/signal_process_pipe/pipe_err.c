
#include "pipe.h"
/*
#inlcude <errno.h> //errno
#include <unistd.h> //write etc
#include <stdlib.h> //malloc
*/


int	*pipe_err_get(void)
{
	static int	*pipe_err;

	if (pipe_err == NULL)
	{
		pipe_err = (int *)malloc(sizeof(int) * 2);
		pipe(pipe_err);
		write(pipe_err[1], "0*", 2);
	}
	return (pipe_err);
}

void	pipe_err_flush(int pipe_err_out)
{
	char	c;

	read(pipe_err_out, &c, 1);
	while (c != '*')
		read(pipe_err_out, &c, 1);
}

//len is always 0
int	putnbr_fd(int val, int fd, int len)
{
	char		c;

	if (val == 0)
	{
		if (len == 0)
			len += write(fd, "0", 1);
	}
	else
	{
		if (val < 0)
		{
			len += write(fd, "-", 1);
			val *= -1;
		}
		c = val % 10 + '0';
		val /= 10;
		len += 1;
		putnbr_fd(val, fd, len);
		write(fd, &c, 1);
	}
	return (len);
}

void	pipe_err_fill(int error, int *pipe_err)
{
	pipe_err_flush(pipe_err[0]);
	putnbr_fd(error, pipe_err[1], 0);
	write(pipe_err[1], "*", 1);
}

void	pipe_err_to_errno(int *pipe_err)
{
	char	c;
	int		error;

	error = 0;
	read(pipe_err[0], &c, 1);
	while (c != '*')
	{
		write(pipe_err[1], &c, 1);
		error = error * 10 + c - '0';
		read(pipe_err[0], &c, 1);
	}
	write(pipe_err[1], "*", 1);
	errno = error;
}