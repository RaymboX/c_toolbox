#include <unistd.h>
#include <limits.h>

#define PBLEN 20

void	progress_bar(const int val)
{
	int	i;
	int j;
	int	div;

	i = -1;
	write(1, "progress:", 9);
	while (++i < PBLEN)
		write(1, "_", 1);
	i = 0;
	while (++i < val)
	{
		if (i % (val / PBLEN) == 0)
		{
			div = i / (val / PBLEN);
			j = -1;
			while (++j + div < PBLEN)
				write(1, "\b", 1);
			write(1, "|", 1);
			j = 0;
			while (++j + div < PBLEN)
				write(1, "_", 1);
		}
	}
	write(1, "\n", 1);
}

int main(void)
{
	int val = INT_MAX;
	progress_bar(val);
	return(0);
}