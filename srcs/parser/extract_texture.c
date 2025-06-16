/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:02:50 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 15:02:50 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	extract_weapon_texture(t_data *game)
{
	int	i;

	game->wand_tex[0] = mlx_load_png("./textures/weapon/00_frame.png");
	game->wand_tex[1] = mlx_load_png("./textures/weapon/01_frame.png");
	game->wand_tex[2] = mlx_load_png("./textures/weapon/02_frame.png");
	game->wand_tex[3] = mlx_load_png("./textures/weapon/03_frame.png");
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
