#include "getnextline.h"

void	strclear(char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		str[i] = '\0';
}

char	*getnextline(int fd)
{
	char	*line;
	int		i;
	int		len_read;

	line = (char *)malloc(sizeof(char) * 10000);
	strclear(line, 10000);
	len_read = read(fd, &line[0], 1);
	i = 0;
	while (len_read > 0 && line[i] != '\n' && line[i] != '\0')
	{
		i++;
		len_read = read(fd, &line[i], 1);
	}
	if (len_read <= 0 && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test2", O_RDONLY);
	line = getnextline(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = getnextline(fd);
	}
	return (0);
}