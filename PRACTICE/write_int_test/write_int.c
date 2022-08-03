#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	i;

	scanf("%d", &i);
	write(1, &i, sizeof(int));
	write(1, "\n", 1);
	return (0);
}
