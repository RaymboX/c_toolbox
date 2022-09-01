#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

static long unsigned int	now_millisecond(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	ft_msleep(long unsigned int wait_millisecond)
{
	long unsigned int	start;
	long unsigned int	how_long;

	start = now_millisecond();
	while (now_millisecond() < wait_millisecond + start)
		usleep(50);
}

int	main(void)
{
	ft_msleep(2000);
	return (0);
}