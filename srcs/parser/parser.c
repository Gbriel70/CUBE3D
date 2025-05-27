#include "../../includes/cube.h"

void	extract_content(t_data *game, char **file)
{
	int		i;
	size_t	rows;

	rows = file_rows(game->map.path);
	game->map.content = ft_calloc(rows + 1, sizeof(char *));
	if (!game->map.content)
	{
		ft_printf("%sError\nFailed to allocate memory for map content%s\n", RED, RESET);
		ft_free_matrix(file);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (file[i])
	{
		game->map.content[i] = ft_strdup(file[i]);
		i++;
	}
	game->map.content_rows = rows;
}

void	parse_map(t_data *game)
{
	char	**file;
	int		*player;

	file = load_file(game->map.path);
	if (!file)
	{
		ft_printf("%sError\nFailed to load map file: %s%s\n", RED, game->map.path, RESET);
		exit(EXIT_FAILURE);
	}
	player = load_player(file);
	if (!player)
	{
		ft_printf("%sError\nFailed to load player data from map file: %s%s\n", RED, game->map.path, RESET);
		ft_free_matrix(file);
		exit(EXIT_FAILURE);
	}
	extract_content(game, file);

	player_initial_setup(game, player);
	extract_map(game);
	extract_floor_ceiling_color(game);
	extract_wall_texture(game);
	extract_weapon_texture(game);
	ft_free_matrix(file);
	free(player);
}
