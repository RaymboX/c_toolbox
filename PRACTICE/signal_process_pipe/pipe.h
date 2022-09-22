#ifndef PIPE_H
# define PIPE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <time.h>

int		*pipe_err_get(void);
void	pipe_err_flush(int pipe_err_out);
int		putnbr_fd(int val, int fd, int len);
void	pipe_err_fill(int error, int *pipe_err);
void	pipe_err_to_errno(int *pipe_err);
int		*get_id(void);
void	signal_handler(int signal);

#endif