
#include "schooltime.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static void	skip_space(const char *nptr, size_t *i)
{
	while (ft_isspace((int)nptr[*i]) == 1)
		*i += 1;
}

static void	ft_signed(const char *nptr, size_t *i, int *negative)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*negative = -1;
		*i += 1;
	}
}

//Return int of char nptr 
int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		negative;
	int		value;

	i = 0;
	skip_space(nptr, &i);
	negative = 1;
	ft_signed(nptr, &i, &negative);
	value = 0;
	while (nptr[i] != '\0'
		&& nptr[i] >= '0'
		&& nptr[i] <= '9')
	{
		value *= 10;
		value += nptr[i] - '0';
		i++;
	}
	return (value * negative);
}

// Copy scr in dst for dstsize char and add \0. Return src len
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		i = -1;
		while (++i < dstsize - 1 && src[i] != '\0')
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

//retourne la longueur de la chaine de caractere sans le \0
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//Return the ascii diff of s1 & s2. If s1 = s2, return 0
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	i = 0;
	while (uc1[i] != '\0' && uc1[i] == uc2[i] && i < n - 1 && n > 0)
		i++;
	if (n == 0)
		return (0);
	else
		return ((int)(uc1[i] - uc2[i]));
}

static int	if_negative(long int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}

static int	nb_char_int(long int n, long int *x10)
{
	int	nbchar;

	nbchar = 0;
	while (n / (*x10 * 10) != 0)
	{
		*x10 *= 10;
		nbchar += 1;
	}
	return (nbchar);
}

static void	fill_str(char *str, long int *n, int negative, long int *x10)
{
	int	i;

	if (negative == 1)
		str[0] = '-';
	i = negative;
	while (*x10 > 0)
	{
		str[i++] = *n / *x10 + '0';
		*n -= (*n / *x10) * *x10;
		*x10 /= 10;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	char		*str;
	int			nbchar;
	int			negative;
	long int	x10;
	long int	val;

	val = n;
	negative = if_negative(&val);
	x10 = 1;
	nbchar = nb_char_int(val, &x10);
	str = (char *)malloc(sizeof(char) * (nbchar + negative + 2));
	if (str == NULL)
		return (NULL);
	fill_str(str, &val, negative, &x10);
	return (str);
}