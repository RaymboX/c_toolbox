/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:34:46 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/13 14:19:47 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_negative(int val)
{
	if (val < 0)
		return (1);
	return (0);
}

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

int	int_abs(int val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}

void	int_to_str(char *str, int val, int len, int neg)
{
	int	x10;
	int	i;

	val = int_abs(val);
	if (neg == 1)
		str[0] = '-';
	i = 0;
	while (i < len)
	{
		x10 = ft_pow(10, len - (1 + i));
		str[i + neg] = val / x10 + '0';
		val -= (val / x10) * x10;
		i++;
	}
	str[i + neg] = '\0';
}


char	*ft_itoa(int val)
{
	char	*str;
	int		neg;
	int		i;
	int		x10;
	int		len;

	neg = is_negative(val);
	len = int_len(val);
	str = (char *)malloc(sizeof(char) * (len + neg + 1));
	int_to_str(str, val, len, neg);
	return (str);
}

int main(void)
{
	printf("%s\n", ft_itoa(234));
	printf("%s\n", ft_itoa(304));
	printf("%s\n", ft_itoa(04));
	printf("%s\n", ft_itoa(-3053));
	return (0);
}