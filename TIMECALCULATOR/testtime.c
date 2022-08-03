#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t	now;
	struct	tm *tm;

	now = time(0);
	if ((tm = localtime(&now)) == NULL)
		printf("Error extracting time stuff\n");
	else
		printf("%04d-%02d-%02d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
	return (0);
}