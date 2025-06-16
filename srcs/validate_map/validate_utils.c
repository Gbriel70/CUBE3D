/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:04:35 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 15:04:52 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	ft_free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	ft_mtxlen(char **mtx)
{
	int	i;

	i = -1;
	while (mtx[++i])
		;
	return (i);
}

int	is_empty_line(char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] != ' ' && line[index] != '\t' && line[index] != '\n'
			&& line[index] != '\r' && line[index] != '\v'
			&& line[index] != '\f')
			return (FALSE);
		index++;
	}
	return (TRUE);
}

void	replace_char(char *str, char old, char new)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == old)
			str[index] = new;
		index++;
	}
}
