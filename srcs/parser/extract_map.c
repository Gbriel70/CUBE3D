/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:02:46 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 15:02:46 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	extract_map(t_data *game)
{
	size_t	rows;
	size_t	columns;

	game->map.layout = &game->map.content[6];
	rows = 0;
	columns = 0;
	while (game->map.layout[rows])
	{
		if (ft_strlen(game->map.layout[rows]) > columns)
			columns = ft_strlen(game->map.layout[rows]);
		rows++;
	}
	game->map.layout_rows = rows;
	game->map.layout_columns = columns;
}
