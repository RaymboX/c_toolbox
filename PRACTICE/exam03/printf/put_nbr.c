#include "ft_printf.h"

int	ft_put_nbr(int val, int *put_count)
{
	char	nbr;

	if (val == 0)
	{
		if (*put_count == 0)
		{
			write(1, "0", 1);
			*put_count += 1;
		}
	}
	else
	{
		if (val < 0)
		{
			write(1, "-", 1);
			*put_count += 1;
			val *= -1;
		}
		nbr = val % 10 + '0';
		val /= 10;
		*put_count += 1;
		ft_put_nbr(val, put_count);
		write(1, &nbr, 1);
	}
	return (*put_count);
}

int	main(void)
{
	int	put_count;
	int	len;

	len = 0;
	put_count = 0;
	len += ft_put_nbr(543, &put_count);
	printf(" -> %d %d\n", put_count, len);
	put_count = 0;
	len += ft_put_nbr(-7003, &put_count);
	printf(" -> %d %d\n", put_count, len);
	put_count = 0;
	len += ft_put_nbr(0, &put_count);
	printf(" -> %d %d\n", put_count, len);
	put_count = 0;
	len += ft_put_nbr(-0, &put_count);
	printf(" -> %d %d\n", put_count, len);
	return (0);
}