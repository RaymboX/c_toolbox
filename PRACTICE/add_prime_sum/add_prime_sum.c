/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:57:28 by mraymond          #+#    #+#             */
/*   Updated: 2022/06/20 10:32:04 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//retourne 1 si str all digit
int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	mini_atoi(char *str)
{
	int	i;
	int	val;

	val = 0;
	i = 0;
	while (str[i])
	{
		val *= 10;
		val += (int)str[i] - '0';
		i++;
	}
	return (val);
}

//return 1 if prime
int	is_prime(int val)
{
	int	i;

	i = 1;
	while (++i < val)
	{
		if (val % i == 0)
			return (0);
	}
	return (1);
}

int	sum_prime_under(int val)
{
	int	i;
	int	sum;

	sum = 0;
	i = 2;
	while (i <= val)
	{
		if (is_prime(i) == 1)
			sum += i;
		i++;
	}
	return (sum);
}

void	write_itoa(int val)
{
	char	c;

	if (val != 0)
	{
		write_itoa(val / 10);
		c = val % 10 + '0';
		write(1, &c, 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2 && str_is_digit(argv[1]) == 1)
		write_itoa(sum_prime_under(mini_atoi(argv[1])));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
