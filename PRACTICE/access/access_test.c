#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void)
{
	struct stat	stat_buffer;
	int			pipe_test[2];
	
	printf("file exist F:%d\n", access("a", F_OK));
	printf("file not exist F:%d\n", access("b", F_OK));
	printf("file no permission X:%d\n", access("not_access", X_OK));
	
	printf("folder exist F:%d\n", access("dir_test", F_OK)); // result 0
	printf("folder exist X:%d\n", access("dir_test", X_OK)); // result 0
	printf("folder not exist F:%d\n", access("dir_not_exist", F_OK)); // result -1
	printf("folder not exist X:%d\n", access("dir_not_exist", X_OK)); // result -1
	printf("folder no permission F:%d\n", access("dir_not_access", F_OK)); // result 0
	printf("folder no permission X:%d\n", access("dir_not_access", X_OK)); // result -1
	printf("result of stat:%d\n", stat("a", &stat_buffer));
	//printf("result:", stat_buffer.)
	printf("pipe_test\n");
	pipe(pipe_test);
	printf("pipe[0] exist:%d\n", fstat(pipe_test[0], &stat_buffer));
	printf("pipe[1] exist:%d\n", fstat(pipe_test[1], &stat_buffer));
	close(pipe_test[0]);
	close(pipe_test[1]);
	printf("pipe[0] closed:%d\n", fstat(pipe_test[0], &stat_buffer));
	printf("pipe[1] closed:%d\n", fstat(pipe_test[1], &stat_buffer));

	return (0);
}