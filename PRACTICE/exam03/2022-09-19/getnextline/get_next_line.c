/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:01:03 by mraymond          #+#    #+#             */
/*   Updated: 2022/09/19 10:52:11 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	str_reset(char *str)
{
	int	i;

	i = -1;
	while (i++ < MALLOC_LEN)
		str[i] = '\0';
}

char	*get_next_line(int fd)
{
	char	*line;
	int		read_ret;
	int		i;

	line = (char *)malloc(sizeof(char) * MALLOC_LEN);
	str_reset(line);
	i = -1;
	read_ret = read(fd, &line[++i], 1);
	while (read_ret > 0 && line[i] != '\n' && line[i] != '\0')
		read_ret = read(fd, &line[++i], 1);
	if (read_ret <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("file1", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);

	do
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
	} while (line);
	

	
}