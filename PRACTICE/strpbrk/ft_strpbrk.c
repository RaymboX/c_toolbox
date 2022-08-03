/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:42:04 by mraymond          #+#    #+#             */
/*   Updated: 2022/06/20 09:52:38 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i[2];

	i[0] = -1;
	while (s1[++i[0]])
	{
		i[1] = -1;
		while (s2[++i[1]])
		{
			if (s1[i[0]] == s2[i[1]])
				return ((char*)&s1[i[0]]);
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("string:%s tofind:%s strpbrk:%s ft_strpbrk:%s\n", argv[1], argv[2],
			strpbrk(argv[1], argv[2]), ft_strpbrk(argv[1], argv[2]));
	return (0);
}
