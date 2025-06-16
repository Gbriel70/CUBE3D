/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:22:22 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 10:20:12 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	start_game(t_data *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!game->mlx)
		handle_error("Failed to initialize MLX42", game, 1);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	create_mlx_images(game);
	mlx_close_hook(game->mlx, close_game, game);
	mlx_loop_hook(game->mlx, key_press, game);
	mlx_cursor_hook(game->mlx, cursor_movement, game);
	mlx_loop_hook(game->mlx, mouse_click, game);
	mlx_loop_hook(game->mlx, draw_player_view, game);
	mlx_loop_hook(game->mlx, draw_minimap, game);
	mlx_loop(game->mlx);
}
