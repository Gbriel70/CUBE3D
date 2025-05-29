#include "../includes/cube.h"

int main(int ac, char **av)
{
	t_data *game;

	validate_map(ac, av);
	game = ft_calloc(1, sizeof(t_data));
	game->map.path = av[1];
	parse_map(game);
	start_game(game);
	return (0);
}