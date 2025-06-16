/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:04:08 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 15:04:09 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	hash_element_exit(char *line, int *array)
{
	if (is_empty_line(line) && array[6] != 0)
		return (9);
	else if (!is_empty_line(line) && array[9] != 0)
		return (10);
	else
		return (11);
}

int	hash_element(char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (0);
	else if (!ft_strncmp(line, "SO", 2))
		return (1);
	else if (!ft_strncmp(line, "EA", 2))
		return (2);
	else if (!ft_strncmp(line, "WE", 2))
		return (3);
	else if (!ft_strncmp(line, "F", 1))
		return (4);
	else if (!ft_strncmp(line, "C", 1))
		return (5);
	else if (is_empty_line(line))
		return (7);
	else if (ft_strchr("01NSEW", line[0]))
		return (6);
	else
		return (8);
}

static void	count_file_element_exit(char *line, int *array)
{
	char	*new_line;

	replace_char(line, '\t', ' ');
	new_line = ft_strtrim(line, " \n");
	array[hash_element(new_line)]++;
	array[hash_element_exit(new_line, array)]++;
	free(new_line);
}

static int	*count_file_elements(char *file)
{
	int		fd;
	int		*array;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	array = ft_calloc(20, sizeof(int));
	if (!array)
	{
		ft_printf("%sError\nMemory allocation failed\n%s", RED, RESET);
		close(fd);
		return (FALSE);
	}
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count_file_element_exit(line, array);
		free(line);
	}
	close(fd);
	return (array);
}

int	valid_map_count(char *file)
{
	int	*array;

	array = count_file_elements(file);
	if (array[0] == 1 && array[1] == 1 && array[2] == 1 && array[3] == 1
		&& array[4] == 1 && array[5] == 1 && array[6] >= 3 && array[8] == 0
		&& array[10] == 0)
	{
		free(array);
		return (TRUE);
	}
	free(array);
	return (FALSE);
}
