/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:05:05 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/17 10:53:09 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	main(int ac, char **av)
{
	t_data	*game;

	validate_map(ac, av);
	game = ft_calloc(1, sizeof(t_data));
	game->map.path = av[1];
	parse_map(game);
	start_game(game);
	return (0);
}
