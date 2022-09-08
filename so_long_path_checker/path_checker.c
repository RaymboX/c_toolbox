
#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_map
{
	int	size_x;
	int	size_y;
	int	player_x;
	int	player_y;
	int	nb_collectable;
}				t_map;

typedef	struct	s_checker
{
	int	fd;
	int	**case_checked;
	int found_collectable;
	int	found_exit;
}				t_checker;

//1: map_name 2:map_size x 3:map_size y 4:nb_collectable 5:player x 6:player y 
int	main(int argc, char **argv)
{
	int	fd = open(argv[1]);
	t_map	map;
	t_checker checker;
	int	i = -1;

	if (fd != -1)
	{
		map.nb_collectable = atoi(argv[2]);
		map.size_x = atoi(argv[3]);
		map.size_y = atoi(argv[4]);
		map.player_x = atoi(argv[5]);
		map.player_y = atoi(argv[6]);
		checker.case_checked = (t_checker **)calloc(sizeof(t_checker *), map.size_x);
		while (++i < map.size_x)
			checker.case_checked[i] = (t_checker *)calloc(sizeof(t_checker), map.size_y);
		checker.found_collectable = 0;
		checker.found_exit = 0;
	}
}

void	path_checker(int x, int y, t_checker *checker, char **map)
{

}