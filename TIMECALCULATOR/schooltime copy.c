
#include "schooltime.h"

void	reset_time(t_time *s_timem)
{
	s_timem->hours = 0;
	s_timem->minute = 0;
	s_timem->second = 0;
}

void	time_converting(t_time *s_timem)
{
	s_timem->minute += s_timem->second / 60;
	s_timem->second %= 60;
	s_timem->hours += s_timem->minute / 60;
	s_timem->minute %= 60;
}

void	time_soustract(int hours, t_time s_timem, int i[3])
{
	char	time_soustract[9] = {0};
	int		retenu = 0;

	if (hours > s_timem.hours)
	{
		i[2] = 60 - s_timem.second;
		if (s_timem.second > 0)
		{
			i[2] = 60 - s_timem.second;
			retenu = 1;
		}
		if (s_timem.minute + retenu > 0)
		{
			i[1] = 60 - (s_timem.minute + retenu);
			retenu = 1;
		}
		i[0] = hours - (s_timem.hours + retenu);
	}
	else
	{
		i[0] = s_timem.hours - hours;
		i[1] = s_timem.minute;
		i[2] = s_timem.second;
	}
}

int	read_daytime(t_time *s_timem, char BUF[10], int fd)
{
	//prend en note le temps fait pour cette journee
	//heure
	
	int read_len;

	

	read_len = read(fd, BUF, 1);
	while (read_len > 0 && BUF[0] != ':')
			read_len = read(fd, BUF, 1);
	if (read_len != 0)
	{
		//skip "
		read(fd, BUF, 1);
		read(fd, BUF, 2);
		BUF[2] = '\0';
		s_timem->hours += ft_atoi(BUF);
		//min
		read(fd, BUF, 1);
		read(fd, BUF, 2);
		BUF[2] = '\0';
		s_timem->minute += ft_atoi(BUF);
		//sec
		read(fd, BUF, 1);
		read(fd, BUF, 2);
		BUF[2] = '\0';
		s_timem->second += ft_atoi(BUF);
		return (1);
	}
	return (0);
}

void	date_reading()
{
	ft_strlcpy(actual_month, (const char *)read_month, 8);
}
/*
int	reste_jour_sem()
{
	time_t	now;
	struct	tm *tm;
	
	now = time(0);
	if ((tm = localtime(&now)) == NULL)
		printf("Error extracting time stuff\n");
	else
		printf("%04d-%02d-%02d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
}
*/



int	main(void)
{
	int 	fd;
	char	actual_month[8] = {0};
	char	*read_month[8] = {0};
	char	BUF[10];
	t_time	s_timem;
	int		read_len;
	int		reste[3];
	char	reste_or_clear[2][6] = {"reste", "pass\0"};
	int		under0_over1 = 0;

	fd = open("locations_stats.json", O_RDONLY);
	if (fd < 0)
		return (1);
	reset_time(&s_timem);
	read_len = read(fd, BUF, 1);
	while (read_daytime(&s_timem, BUF, fd) != 0)
	{
		read(fd, BUF, 1); // skip le "
		read(fd, read_month, 7); //read la date yyyy-mm
		if (ft_strncmp((const char *)read_month, actual_month, 7) != 0) //si il n'y en a plus dans le meme mois
		{
			if (actual_month[0] != '\0') //Si pas le premier mois
			{
				time_converting(&s_timem); // converti les sec en min et min en heure
				time_soustract(100, s_timem, reste); //soustrait cible 100 a actuel
				// verifie si objectif atteind
				if (s_timem.hours < 100)
					under0_over1 = 0;
				else
					under0_over1 = 1;
				//inscrit date / temps total / temps restant
				printf("%s = %02d:%02d:%02d  %s: %02d:%02d:%02d\n", actual_month, s_timem.hours, s_timem.minute, s_timem.second, reste_or_clear[under0_over1], reste[0], reste[1], reste[2]);
				// reset la struct de temps pour next month
				reset_time(&s_timem);
			}
			ft_strlcpy(actual_month, (const char *)read_month, 8);
		}
	}
	close(fd);
	return (0);
}
