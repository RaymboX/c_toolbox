#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("file exist:%d\n", access("a", F_OK));
	printf("file not exist:%d\n", access("b", F_OK));
	return (0);
}