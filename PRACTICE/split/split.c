
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//pos=0: nb word / pos>0: word pos
int	nbsplit_wordpos(char *str, char spliter, int pos, int w[2])
{
	int	nb = 0;
	
	w[0] = -1;
	w[1] = 0;
	while (str[++w[0]])
	{
		if (str[w[0]] == spliter)
		{
			if (w[0] > 0 && str[w[0] - 1] != spliter)
				nb += 1;
			if (nb == pos && nb != 0)
				return (nb);
			w[1] = w[0] + 1;
		}
	}
	if (w[0] > 0 && str[w[0] - 1] != spliter)
		nb += 1;
	return (nb);
}

void	strcpy_range(char *src, int start, int end, char *dest)
{
	int i = start;
	
	while (i < end)
	{
		dest[i-start] = src[i];
		i++;
	}
	dest[end] = '\0';
}

void	fill_split(char **ret_split, char *str, char spliter, int nbword, int w[2])
{
	int	iword = 0;

	while (++iword <= nbword)
	{
		nbsplit_wordpos(str, spliter, iword, w);
		ret_split[iword-1] = (char *)malloc(sizeof(char) * (w[0] - w[1] + 1));
		if (ret_split[iword-1] == NULL)
			break;
		strcpy_range(str, w[1], w[0], ret_split[iword-1]);
	}
}

char	**split(char *str, char spliter)
{
	char **ret_split;
	int nbword;
	int w[2];

	if (str == NULL)
		return (NULL);
	nbword = nbsplit_wordpos(str, spliter, 0, w);
	ret_split = (char **)malloc(sizeof(char *) * (nbword + 1));
	if (ret_split == NULL)
		return (NULL);
	ret_split[nbword] = NULL;
	fill_split(ret_split, str, spliter, nbword, w);
	return (ret_split);
}


int main(int argc, char **argv)
{	
	char 	**ret_split;
	int 	isplit = -1;
	//char	str[]="   test espace  en avant  ";

	ret_split = split(argv[1], ' ');
	while (ret_split[++isplit])
		printf("%s\n", ret_split[isplit]);
	return (0);
}




