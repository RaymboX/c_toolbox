#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void	waiting_all_child(int nb_child, int *status)
{
	int	i;
	int child_id;

	i = -1;
	while (++i < nb_child)
	{
		child_id = waitpid(-1, status, 0);
		if (child_id != -1)
			printf("child id waitpid return:%d\n", child_id);
		else
		{
			if (WEXITSTATUS(*status) == 0)
				printf("all child done");
			else
				printf("waitpid error status:%d\n", WEXITSTATUS(*status));
		}
	}
}

void	waittime(int id)
{
	int	wait_time;

	wait_time = getpid() % 10;
	if (wait_time == 0)
		wait_time = 10;
	wait_time *= 100000;
	usleep(1000);
	printf("child %d will wait %d micro sec\n", getpid(), wait_time);
	usleep(wait_time);
	printf("child %d finished waiting\n", getpid());
}

int	main(void)
{
	int	id;
	int	*status;
	int	nb_child;
	int i;
	

	id = -1;
	nb_child = 5;
	i = -1;
	while (++i < nb_child && id != 0)
	{
		id = fork();
		if (id != 0)
			printf("id:%d created\n", id);
	}
	if (id == 0)
	{
		//waittime(id);
		sleep(getpid() % 10 + 1);
	}
	else
		waiting_all_child(nb_child, status);
	if (id == 0)
	{
		printf("child %d ended\n", getpid());
		exit(errno);
	}
	else
		printf("parent end\n");
	return (errno);
}
