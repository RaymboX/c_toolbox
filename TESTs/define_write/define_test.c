#include <unistd.h>
#include <stddef.h>

#define TEXT "Bonjour test fdgd fg"

//retourne la longueur de la chaine de caractere sans le \0
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i])
		i++;
	return (i);
}


int main(void)
{
	write(1, TEXT, ft_strlen(TEXT));
	//write(1, "bonjour test", ft_strlen("Bonjour test"));
	return (0);
}