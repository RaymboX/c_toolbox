#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void)
{
	struct stat stat_buffer;
	
	printf("file exist:%d\n", access("a", F_OK));
	printf("file not exist:%d\n", access("b", F_OK));
	printf("file no permission:%d\n", access("not_access", X_OK));
	printf("result of stat:%d\n", stat("a", &stat_buffer));
	//printf("result:", stat_buffer.)
	return (0);
}