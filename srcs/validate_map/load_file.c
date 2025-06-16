/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:03:29 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 15:03:50 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	load_map(char **file, char *line)
{
	int	index;

	index = 6;
	while (file[index])
		index++;
	file[index] = ft_strdup(line);
	return ;
}

static void	load_surf(char **file, char **array)
{
	int	index;

	index = 0;
	while (index <= 5)
	{
		if (array[1] && hash_element(array[0]) == index)
			file[index] = ft_strdup(array[1]);
		index++;
	}
}

static void	load_file_ext(char *line, char **file)
{
	char	*new_line1;
	char	*new_line2;
	char	**array;

	new_line1 = ft_substr_replace(line, "\t", "   ");
	replace_char(new_line1, '\n', '\0');
	new_line2 = ft_strtrim(new_line1, " ");
	array = ft_split(new_line2, ' ');
	if (hash_element(new_line2) >= 0 && hash_element(new_line2) <= 5)
		load_surf(file, array);
	else if (hash_element(new_line2) == 6)
		load_map(file, new_line1);
	ft_free_array(array);
	free(new_line1);
	free(new_line2);
}

int	file_rows(char *filename)
{
	int		fd;
	char	*line;
	int		rows;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	rows = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!is_empty_line(line))
			rows++;
		free(line);
	}
	close(fd);
	return (rows);
}

char	**load_file(char *filename)
{
	int		fd;
	char	*line;
	char	**file;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%dError\nFailed to open file: %s\n%d", RED, filename, RESET);
		return (NULL);
	}
	file = ft_calloc(file_rows(filename) + 1, sizeof(char *));
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		load_file_ext(line, file);
		free(line);
	}
	close(fd);
	return (file);
}
