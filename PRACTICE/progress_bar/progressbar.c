#include <stdio.h>
#include <limits.h>

#define PBLEN 20

void	progress_bar(const int val)
{
	int	i;
	int j;
	int	div;

	i = -1;
	printf("progress:");
	while (++i < PBLEN)
		printf("_");
	i = 0;
	while (++i < val)
	{
		if (i % (val / PBLEN) == 0)
		{
			div = i / (val / PBLEN);
			j = -1;
			while (++j + div < PBLEN)
				printf("\b");
			printf("|");
			j = 0;
			while (++j + div < PBLEN)
				printf("_");
		}
	}
	printf("\n");
}

int main(void)
{
	int val = INT_MAX;
	progress_bar(val);
	return(0);
}