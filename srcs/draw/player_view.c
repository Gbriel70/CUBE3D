/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:02:17 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 15:06:04 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static void	draw_background(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(game->playerview_img, x, y,
					game->map.ceiling_color);
			else
				mlx_put_pixel(game->playerview_img, x, y,
					game->map.floor_color);
			x++;
		}
		y++;
	}
}

static void	update_fps(t_data *game)
{
	char				*fps;
	char				*fps_str;
	static int			i;
	static mlx_image_t	*fps_img;

	game->frame_time = game->mlx->delta_time;
	if (i++ % 15 == 0)
	{
		fps = ft_itoa((int)(1.0 / game->frame_time));
		fps_str = ft_strjoin("FPS: ", fps);
		free(fps);
		if (fps_img)
			mlx_delete_image(game->mlx, fps_img);
		fps_img = mlx_put_string(game->mlx, fps_str, WIDTH - 75, HEIGHT - 20);
		fps_img->instances->z = 4;
		free(fps_str);
	}
}

static void	limit_fps(t_data *game __attribute__((unused)))
{
	static double	last_time = 0;
	static double	target_fps = 100.0;
	double			target_frame_time;
	double			current_time;

	target_frame_time = 1.0 / target_fps;
	if (last_time == 0)
	{
		last_time = mlx_get_time();
		return ;
	}
	while (1)
	{
		current_time = mlx_get_time();
		if (current_time - last_time >= target_frame_time)
			break ;
	}
	last_time = current_time;
}

void	draw_player_view(void *param)
{
	t_data	*game;

	game = param;
	limit_fps(game);
	draw_background(game);
	update_fps(game);
	raycast_walls(game);
}
