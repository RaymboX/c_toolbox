/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixxbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:23:57 by mraymond          #+#    #+#             */
/*   Updated: 2022/06/20 09:35:43 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	mini_itoa(int i)
{
	char	c;

	if (i != 0)
	{
		mini_itoa(i / 10);
		c = i % 10 + '0';
		write(1, &c, 1);
	}
}

int	main(void)
{
	int	i;

	i = 0;
	while (++i <= 100)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			if (i % 3 == 0)
				write(1, "fizz", 4);
			if (i % 5 == 0)
				write(1, "buzz", 4);
		}
		else
			mini_itoa(i);
		write(1, "\n", 1);
	}
	return (0);
}
