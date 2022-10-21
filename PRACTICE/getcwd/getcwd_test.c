#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define ENV_PATH "TERM=xterm-256color_="

int	main(int argc, char **argv, char **envp)
{
	char	buf[100];
	int		i;

	printf("%s\n", getcwd(buf, 100));
	printf("%s\n", buf);
	i = strlen(argv[0]);
	while (argv[0][--i] != '/'){}
	argv[0][++i] = '\0';
	printf("%s%s%s\n", buf, "/", argv[0]);
	return (0);
}
