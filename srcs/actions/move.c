/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:57:18 by gabastos          #+#    #+#             */
/*   Updated: 2025/05/27 14:12:57 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static	int	get_signal(float num)
{
	if (num > 0)
		return (1);
	else
		return (-1);
}

void	move_player(t_data *game, float speed)
{
	t_vector	velocity;
	t_coord		new_pos;
	float		wall;

	velocity.x = game->dir.x * speed * game->frame_time;
	velocity.y = game->dir.y * speed * game->frame_time;
	wall = get_signal(velocity.x) * WALL_OFFSET;
	new_pos.x = game->player.x + velocity.x + wall;
	wall = get_signal(velocity.y) * WALL_OFFSET;
	new_pos.y = game->player.y + velocity.y + wall;
	if (game->map.layout[(int)game->player.y][new_pos.x] == '0')
		game->player.x += velocity.x;
	if (game->map.layout[new_pos.y][(int)game->player.x] == '0')
		game->player.y += velocity.y;
}

void	move_left(t_data *game, float speed)
{
	t_vector	velocity;
	t_coord		new_pos;
	float		wall;

	velocity.x = game->dir.y * speed * game->frame_time;
	velocity.y = -game->dir.x * speed * game->frame_time;
	wall = get_signal(velocity.x) * WALL_OFFSET;
	new_pos.x = game->player.x + velocity.x + wall;
	wall = get_signal(velocity.y) * WALL_OFFSET;
	new_pos.y = game->player.y + velocity.y + wall;
	if (game->map.layout[(int)game->player.y][new_pos.x] == '0')
		game->player.x += velocity.x;
	if (game->map.layout[new_pos.y][(int)game->player.x] == '0')
		game->player.y += velocity.y;
}

void	move_right(t_data *game, float speed)
{
	t_vector	velocity;
	t_coord		new_pos;
	float		wall;

	velocity.x = -game->dir.y * speed * game->frame_time;
	velocity.y = game->dir.x * speed * game->frame_time;
	wall = get_signal(velocity.x) * WALL_OFFSET;
	new_pos.x = game->player.x + velocity.x + wall;
	wall = get_signal(velocity.y) * WALL_OFFSET;
	new_pos.y = game->player.y + velocity.y + wall;
	if (game->map.layout[(int)game->player.y][new_pos.x] == '0')
		game->player.x += velocity.x;
	if (game->map.layout[new_pos.y][(int)game->player.x] == '0')
		game->player.y += velocity.y;
}

void	rotate_player(t_data *game, float speed)
{
	float	old_dir_x;

	old_dir_x = game->dir.x;
	game->dir.x = game->dir.x * cos(speed * game->frame_time)
		- game->dir.y * sin(speed * game->frame_time);
	game->dir.y = old_dir_x * sin(speed * game->frame_time)
		+ game->dir.y * cos(speed * game->frame_time);
	old_dir_x = game->plane.x;
	game->plane.x = game->plane.x * cos(speed * game->frame_time)
		- game->plane.y * sin(speed * game->frame_time);
	game->plane.y = old_dir_x * sin(speed * game->frame_time)
		+ game->plane.y * cos(speed * game->frame_time);
}
