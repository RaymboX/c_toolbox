

#include <stdio.h>


int	ft_pow(int base, int expo)
{
	int	val;

	if (expo == 0)
		return (1);
	else
	{
		val = base;
		while (--expo > 0)
			val *= base;
	}
	return (val);
}

int	int_len(int val)
{
	int	len;

	if (val == 0)
		return (1);
	len = 9;
	while (val / ft_pow(10, len) == 0 && len > 0)
		len--;
	return (len + 1);
}

int	main(void)
{
	printf("%d\n", int_len(0));
	printf("%d\n", int_len(-1));
	printf("%d\n", int_len(5));
	printf("%d\n", int_len(234));
	printf("%d\n", int_len(452346));
	printf("%d\n", ft_pow(10, 0));
	printf("%d\n", ft_pow(10, 1));
	printf("%d\n", ft_pow(10, 2));
	printf("%d\n", ft_pow(10, 3));
	printf("%d\n", ft_pow(10, 4));
	return (0);
}