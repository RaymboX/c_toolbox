/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:08:53 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/19 10:18:52 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int val, int *nb_put)
{
	char	nbr;

	if (val == 0)
	{
		if (*nb_put == 0)
			*nb_put = write(1, "0", 1);
	}
	else
	{
		if (val < 0)
		{
			*nb_put = write(1, "-", 1);
			val *= -1;
		}
		nbr = val % 10 + '0';
		val /= 10;
		*nb_put += 1;
		ft_putnbr(val, nb_put);
		write(1, &nbr, 1);
	}
}

void putnbr2(long long num, int base_len, char *base)
{
	char c;
	if (num > base_len)
		putnbr2(num / base_len, base_len, base);
	c = base[num % base_len];
	write(1, &c , 1);
}

void	ft_puthex(unsigned int val, int *nb_put)
{
	char	nbr;

	if (val == 0)
	{
		if (*nb_put == 0)
			*nb_put = write(1, "0", 1);
	}
	else
	{
		if (val < 0)
		{
			*nb_put = write(1, "-", 1);
			val *= -1;
		}
		nbr = val % 16 + '0';
		if (nbr > '9')
			nbr += 'a' - ('9' + 1);
		val /= 16;
		*nb_put += 1;
		ft_putnbr(val, nb_put);
		write(1, &nbr, 1);
	}
}

void	ft_putstr(char *str, int *nb_put)
{
	while (str[*nb_put])
	{
		write(1, &str[*nb_put], 1);
		*nb_put += 1;
	}
}

void	ft_putchar(int c, int *nb_put)
{
	*nb_put = write(1, &c, 1);
}

int	flag_management(va_list ap, char flag)
{
	int	nb_put;

	nb_put = 0;
	if (flag == 'd')
		ft_putnbr(va_arg(ap, int), &nb_put);
	if (flag == 'x')
		ft_puthex(va_arg(ap, unsigned int), &nb_put);
	if (flag == 's')
		ft_putstr(va_arg(ap, char *), &nb_put);
	if (flag == 'c')
		ft_putchar(va_arg(ap, int), &nb_put);
	if (flag == '%')
		nb_put = write(1, "%", 1);
	return (nb_put);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, format);
	len = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			len += flag_management(ap, format[++i]);
		else
			len += write(1, &format[i], 1);
	}
	va_end(ap);
	return (len);
}

int main(void)
{
	int i;
	
	i = ft_printf("bonjour %d hehe %s hex:%x char:%c %%\n", 34, "test", 11, 'b');
	printf("%d\n", i);
	i = 66;
	write(1, &i, 1);
	write(1, "\n", 1);
	return (0);
}