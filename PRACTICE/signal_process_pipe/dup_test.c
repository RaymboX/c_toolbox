
#include "pipe.h"

int *get_id(void)
{
	static int	*id;

	if (id == NULL)
		id = (int *)malloc(sizeof(int));
	return (id);
}

void	signal_handler(int signal)
{
	int	*id;
	int *pipe_err;

	id = get_id();
	pipe_err = pipe_err_get();
	printf("\nHI signal:%d id:%d errno:%d\n", signal, *id, errno);
	if (*id == 0)
	{
		pipe_err_fill(errno, pipe_err);
		printf("child exit\n");
		exit(errno);
	}
}

int	main(void)
{
	int fd_in;
	int fd_file;
	int id;
	int status;
	int *ptr_id;
	int	*pipe_err;

	pipe_err = pipe_err_get();
	signal(SIGINT, signal_handler);
	//fd_file = open("file", O_RDWR, S_IRUSR | S_IWUSR);
	printf("\nerrno before fork:%d\n", errno);
	id = fork();
	printf("\nid:%d errno:%d message:%s\n", id, errno, strerror(errno));
	ptr_id = get_id();
	printf("\nid:%d errno:%d message:%s\n", id, errno, strerror(errno));
	*ptr_id = id;
	printf("\nid:%d errno:%d message:%s\n", id, errno, strerror(errno));
	if (id == 0)
	{
		printf("\nid:%d errno:%d message:%s\n", id, errno, strerror(errno));
		usleep(2000000);
		printf("\nid:%d errno:%d message:%s\n", id, errno, strerror(errno));
		printf("child errno before exit:%d\n", errno);
		exit(errno);
	}
	else
		waitpid(id, &status, 0);
	printf("errno before read:%d\n", errno);
	printf("%s\n", strerror(errno));
	perror(strerror(errno));
	pipe_err_to_errno(pipe_err);
	printf("end of program id:%d errno:%d \n", id, errno);
	perror(strerror(errno));
	printf("status: %d %d %d\n", status / 256, WEXITSTATUS(status), WIFEXITED(status));
	WEXITSTATUS(status);
	printf("%s\n", strerror(WEXITSTATUS(status)));
	return (errno);
}

