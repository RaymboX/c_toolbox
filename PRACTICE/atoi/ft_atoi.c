/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:02:06 by mraymond          #+#    #+#             */
/*   Updated: 2022/06/20 09:21:36 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	skip_space(char *str, int *i)
{
	while (((int)str[*i] >= 9 && (int)str[*i] <= 13) || (int)str[*i] == 32)
		*i += 1;
}

int	val_signed(char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		*i += 1;
		if (str[*i - 1] == '-')
			return (-1);
	}
	return (1);
}

int	is_digit(char *str, int *i)
{
	if (str[*i] >= '0' && str[*i] <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	val;
	int	i;

	i = 0;
	val = 0;
	skip_space(str, &i);
	neg = val_signed(str, &i);
	while (is_digit(str, &i) == 1)
	{
		val *= 10;
		val += (int)str[i] - '0';
		i += 1;
	}
	return (val * neg);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("input:%s atoi:%d ft_atoi:%d\n", argv[1], atoi(argv[1]), ft_atoi(argv[1]));
	return (0);	
}
