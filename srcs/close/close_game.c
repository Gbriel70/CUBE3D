/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:02:06 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 15:02:08 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	delete_textures(t_data *game)
{
	if (game->map.north_tex)
		mlx_delete_texture(game->map.north_tex);
	if (game->map.south_tex)
		mlx_delete_texture(game->map.south_tex);
	if (game->map.west_tex)
		mlx_delete_texture(game->map.west_tex);
	if (game->map.east_tex)
		mlx_delete_texture(game->map.east_tex);
}

void	ft_free_matrix(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		free (mtx[i]);
		i++;
	}
	free (mtx);
}

void	handle_error(char *message, t_data *game, int stage)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
	if (stage > 0)
	{
		ft_free_matrix(game->map.content);
		delete_textures(game);
		if (stage > 1)
		{
			mlx_close_window(game->mlx);
			mlx_terminate(game->mlx);
		}
	}
	free(game);
	exit(EXIT_FAILURE);
}

void	close_game(void *param)
{
	t_data	*game;

	game = param;
	mlx_close_window(game->mlx);
	delete_textures(game);
	mlx_terminate(game->mlx);
	ft_free_matrix(game->map.content);
	free(game);
	exit(EXIT_SUCCESS);
}
