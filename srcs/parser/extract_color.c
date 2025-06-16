/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:02:41 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 15:02:42 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	extract_color(char *color)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	rgb = ft_split(color, ',');
	if (!rgb)
		return (0);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free_matrix(rgb);
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	extract_floor_ceiling_color(t_data *game)
{
	char	*color;

	color = game->map.content[4];
	game->map.floor_color = extract_color(color);
	color = game->map.content[5];
	game->map.ceiling_color = extract_color(color);
}
