/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:02:53 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 15:02:54 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	extract_content(t_data *game, char **file)
{
	int		i;
	size_t	rows;

	rows = file_rows(game->map.path);
	game->map.content = ft_calloc(rows + 1, sizeof(char *));
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
	player = load_player(file);
	extract_content(game, file);
	player_initial_setup(game, player);
	extract_map(game);
	extract_floor_ceiling_color(game);
	extract_wall_texture(game);
	extract_weapon_texture(game);
	ft_free_matrix(file);
	free(player);
}
