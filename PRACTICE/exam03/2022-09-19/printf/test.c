
#include <unistd.h>
#include <stdio.h>

void putnbr2(long long num, int base_len, char *base, int *len)
{
	char c;
	if (num < 0)
	{
		*len += write(1, "-", 1);
		num *= -1;
	}
	if (num >= base_len)
		putnbr2(num / base_len, base_len, base, len);
	c = base[num % base_len];
	*len += write(1, &c , 1);
}

int	main(void)
{
	int len;
	
	len = 0;
	putnbr2(123, 10, "0123456789", &len);
	printf("\n%d\n", len);
	len = 0;
	putnbr2(0, 10, "0123456789", &len);
	printf("\n%d\n", len);
	len = 0;
	putnbr2(-10, 10, "0123456789", &len);
	printf("\n%d\n", len);
	len = 0;
	putnbr2(100, 10, "0123456789", &len);
	printf("\n%d\n", len);
	len = 0;
	putnbr2(1000, 10, "0123456789", &len);
	printf("\n%d\n", len);
	len = 0;
	putnbr2(42, 16, "0123456789abcdef", &len);
	printf("\n%d\n", len);
	return (0);
}

bool mybool;

bool ?  : 