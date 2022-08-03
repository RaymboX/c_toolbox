
#ifndef SCHOOLTIME_H
# define SCHOOLTIME_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <time.h>

typedef struct s_time
{
	int	hours;
	int	minute;
	int	second;
}		t_time;

int		ft_atoi(const char *nptr);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	reset_time(t_time *s_timem);
void	time_converting(t_time *s_timem);
char	*ft_itoa(int n);

#endif