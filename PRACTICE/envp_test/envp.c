#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **envp, char **environ)
{
	int i;

	putenv("POULET=FRIT");
	i = -1;
	while (envp[++i])
		printf("%s\n", envp[i]);
	i = -1;
	while (environ[++i])
		printf("%s\n", environ[i]);
	printf("%s\n", getenv("POULET"));	
	return (0);


}