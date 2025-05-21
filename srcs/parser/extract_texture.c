#include "../../includes/cube.h"

void	extract_weapon_texture(t_data *game)
{
	int	i;

	game->wand_tex[0] = mlx_load_png("assets/weapon.png");
	game->wand_tex[1] = mlx_load_png("assets/weapon2.png");
	game->wand_tex[2] = mlx_load_png("assets/weapon3.png");
	game->wand_tex[3] = mlx_load_png("assets/weapon4.png");
	i = 0;
	while (i < WEAPON_FRAMES)
	{
		if (!game->wand_tex[i])
			handle_error(game, "Error loading weapon texture", game, 1);
		i++;
	}
}

void	extract_wall_texture(t_data *game)
{
	game->map.north_tex = mlx_load_png(game->map.content[1]);
	game->map.south_tex = mlx_load_png(game->map.content[2]);
	game->map.west_tex = mlx_load_png(game->map.content[3]);
	game->map.east_tex = mlx_load_png(game->map.content[4]);
}
