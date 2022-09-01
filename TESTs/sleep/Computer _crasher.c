#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>



int main(void)
{
	struct	timeval now;
	long unsigned int start_su;
	long unsigned int how_long;
	long unsigned int now_su;

	gettimeofday(&now, NULL);
	printf("sec:%ld\nmicrosec:%d\n", now.tv_sec, now.tv_usec);
	start_su = now.tv_sec * 1000000 + now.tv_usec;
	printf("combine:%ld\n", start_su);
	how_long = 2345678;
	now_su = start_su;
	while ((now_su - start_su) < how_long)
	{
		gettimeofday(&now, NULL);
		now_su = now.tv_sec * 1000000 + now.tv_usec;
	}
	printf("how_long:%ld\ndiff:%ld\n", how_long, now_su - start_su);
	return (0);
}
