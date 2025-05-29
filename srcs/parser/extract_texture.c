#include "../../includes/cube.h"

void	extract_weapon_texture(t_data *game)
{
	int	i;

	game->wand_tex[0] = mlx_load_png("./textures/weapon/wand_0.png");
	game->wand_tex[1] = mlx_load_png("./textures/weapon/wand_1.png");
	game->wand_tex[2] = mlx_load_png("./textures/weapon/wand_2.png");
	game->wand_tex[3] = mlx_load_png("./textures/weapon/wand_3.png");
	i = 0;
	while (i < WEAPON_FRAMES)
	{
		if (!game->wand_tex[i])
			handle_error("Error loading weapon texture", game, 1);
		i++;
	}
}

void	extract_wall_texture(t_data *game)
{
	game->map.north_tex = mlx_load_png(game->map.content[0]);
	game->map.south_tex = mlx_load_png(game->map.content[1]);
	game->map.west_tex = mlx_load_png(game->map.content[2]);
	game->map.east_tex = mlx_load_png(game->map.content[3]);
}
