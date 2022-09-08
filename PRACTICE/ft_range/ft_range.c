#include <stdlib.h>
#include <stdio.h>

int ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

int *ft_range(int start, int end)
{
	int *range;
	int i;
	int len;

	len = ft_abs(start - end) + 1;
	range = malloc(0);
	i = 0;
	while (i < len)
	{
		if (start < end)
			range[i] = start + i;
		else
			range[i] = start - i;
		i++;
	}
	return (range);
}

int main(void)
{
	int	*ptr;
	int	i;

	ptr = ft_range(-2, 5);
	i = -1;
	while (++i != 8)
		printf("%d\n", ptr[i]);
	free (ptr);
	return (0);
}
