#include <unistd.h>
#include <limits.h>

#define PBLEN 20

void	progress_bar(const int val)
{
	int	i;

	write(1, "progress:", 9);
	i = -1;
	while (++i < PBLEN)
		write(1, "_", 1);
	i = -1;
	while (++i < PBLEN)
		write(1, "\b", 1);
	i = 0;
	while (++i < val)
	{
		if (i % (val / PBLEN) == 0)
			write(1, "|", 1);
	}
	write(1, "\n", 1);
}

int main(void)
{
	int val = INT_MAX;
	progress_bar(val);
	return(0);
}