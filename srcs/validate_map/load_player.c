/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:04:02 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 15:04:03 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	update_player(int *player, int i, int j, char **file)
{
	player[0]++;
	player[1] = i;
	player[2] = j;
	player[3] = file[i][j];
	file[i][j] = '0';
}

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	*load_player(char **file)
{
	int	*player;
	int	i;
	int	j;

	player = ft_calloc(20, sizeof(int));
	i = 6;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (is_player(file[i][j]))
				update_player(player, i, j, file);
			j++;
		}
		i++;
	}
	return (player);
}
