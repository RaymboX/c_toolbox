#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*a;

	a = (unsigned char *)s;
	i = -1;
	while (++i < n)
		a[i] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*v;

	v = malloc(count * size);
	if (v != NULL)
		ft_bzero(v, count * size);
	return (v);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i])
		i++;
	return (i);
}

//Retourne le pointeur de la cpy de s
char	*ft_strdup(const char *s)
{
	char	*str;

	str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (str != NULL)
		ft_strcpy(str, s);
	return (str);
}

int	main(void)
{
	int		id;
	char	*cmd;
	char	*exec_args[4];

	id = fork();
	if (id != 0)
		wait(0);
	else
	{
		cmd = ft_strdup("/bin/cp");
		exec_args[0] = ft_strdup("cp");
		exec_args[1] = ft_strdup("a");
		exec_args[2] = ft_strdup("b");
		exec_args[3] = NULL;
		execve(cmd, exec_args, NULL);
		free(cmd);
		free(exec_args[0]);
		free(exec_args[1]);
		free(exec_args[2]);
		write(2, "error: fail to create temp file\n", 32);
		return (id);
	}
	return (id);
}
