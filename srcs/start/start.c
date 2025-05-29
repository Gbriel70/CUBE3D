/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:22:22 by gabastos          #+#    #+#             */
/*   Updated: 2025/05/27 14:35:37 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	start_game(t_data *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!game->mlx)
		handle_error("Failed to initialize MLX42", game, 1);
	create_mlx_images(game);
	mlx_close_hook(game->mlx, close_game, game);
	mlx_loop_hook(game->mlx, key_press, game);
	mlx_cursor_hook(game->mlx, cursor_movement, game);
	mlx_loop_hook(game->mlx, mouse_click, game);
	mlx_loop_hook(game->mlx, draw_player_view, game);
	mlx_loop_hook(game->mlx, draw_minimap, game);
	mlx_loop(game->mlx);
}
