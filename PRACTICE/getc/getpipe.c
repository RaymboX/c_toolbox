#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

typedef struct s_snake
{
	pthread_mutex_t	mute;
	pthread_t		snake_thread;
	int				stop;
	char			c;
}			t_snake;

void	*addenter(void *void_snake);

int	main(void)
{
	t_snake	snake;

	snake.stop = 0;
	usleep(1000000);
	printf("bonjour\n");
	pthread_create(&snake.snake_thread, NULL, &addenter, (void *)&snake);
	pthread_mutex_init(&snake.mute, NULL);
	snake.c = '1';
	while (snake.stop != 1)
	{
		read(0, &snake.c, 1);
		pthread_mutex_lock(&snake.mute);
		printf("%c", snake.c);
		if (snake.c == 0 || snake.c == '0')
		{
			printf("\nSTOP!!!\n");
			snake.stop = 1;
		}
		pthread_mutex_unlock(&snake.mute);
	}
	pthread_join(snake.snake_thread, NULL);
	pthread_mutex_destroy(&snake.mute);
	while (snake.c != '\n')
		read(0, &snake.c, 1);
	return (0);
}

void	*addenter(void *void_snake)
{
	t_snake	*snake;

	snake = (t_snake *)void_snake;
	while (snake->stop != 1)
	{
		pthread_mutex_lock(&snake->mute);
		//write(0, "\n", 1);
		snake->c = '\n';
		pthread_mutex_unlock(&snake->mute);
		usleep(100000);
	}
}
