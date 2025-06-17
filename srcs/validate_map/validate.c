/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:05:00 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/17 11:26:34 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

short	valid_map_name(char *filename)
{
	int	len;
	int	exit_len;

	len = ft_strlen(filename);
	exit_len = ft_strlen(".cub");
	if (len <= exit_len || ft_strncmp(&filename[len - 4], ".cub",
			exit_len) != 0)
	{
		ft_printf("%sError\nInvalid map name. Map name must end with .cub\n%s",
			RED, RESET);
		return (FALSE);
	}
	return (TRUE);
}

void	validate_map(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("%sError\nUsage: ./cub3D <map.cub>\n%s", RED, RESET);
		exit(1);
	}
	if (valid_map_name(av[1]) == FALSE)
	{
		ft_printf("%sError\n%s", RED, RESET);
		exit(1);
	}
	if (valid_map_count(av[1]) == FALSE)
	{
		ft_printf("%sError\n%s", RED, RESET);
		exit(1);
	}
	if (validate_map_content(av[1]) == FALSE)
	{
		ft_printf("%sError\n%s", RED, RESET);
		exit(1);
	}
	if (validate_map_game(av[1]) == FALSE)
	{
		ft_printf("%sError\n%s", RED, RESET);
		exit(1);
	}
}
