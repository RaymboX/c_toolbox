/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:41:25 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/13 15:27:17 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_put_hex(unsigned int val, int *put_count)
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
		nbr = val % 16 + '0';
		if (nbr > '9')
			nbr += 'a' - ('9' + 1);
		val /= 16;
		*put_count += 1;
		ft_put_nbr(val, put_count);
		write(1, &nbr, 1);
	}
	return (*put_count);
}

int	ft_put_str(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

void	flag_manager(char flag, va_list ap, int *len)
{
	int	put_count;

	put_count = 0;
	if (flag == 'd')
		*len += ft_put_nbr(va_arg(ap, int), &put_count);
	if (flag == 's')
		*len += ft_put_str(va_arg(ap, char *));
	if (flag == 'x')
		*len += ft_put_hex(va_arg(ap, unsigned int), &put_count);
	if (flag == '%')
		*len += write(1, &flag, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	len = 0;
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
			flag_manager(format[++i], ap, &len);
		else
			len += write(1, &format[i], 1);
	}
	va_end(ap);
	return (len);
}

int main(void)
{
	int i;
	
	i = ft_printf("bonjour %d hehe %s hex:%x\n", 34, "test", 200);
	printf("%d\n", i);
	return (0);
}