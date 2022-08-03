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
	range = (int *)malloc(1);
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
	int i = -1;
	int start = 3;
	int end = 10;
	//int *range;
	int *avant;
	int *apres;
	int garbage = 0;
	
	avant = malloc(sizeof(int));
	*avant = -69;
	avant[5] = 9999;
	//range = ft_range(start, end);
	apres = (int *)malloc(1);
	*apres = -96;
	//range[4] = 8457;
	while (++i <= ft_abs(start - end) + 10) 
	{
		garbage += avant[i];
		printf("%d - %d - %d\n", avant[i], i, garbage);
		//printf("%p\n", &range[i]);
	}
	//free(range);
	return (0);
}
