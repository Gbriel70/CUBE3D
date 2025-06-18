/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:04:15 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/18 10:19:49 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	validate_map_content2(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01NSEW ", line[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	validate_color(char *line)
{
	char	**mtx_color;
	int		i;

	if (!line)
		return (FALSE);
	mtx_color = ft_split(line, ',');
	if (ft_mtxlen(mtx_color) != 3)
		return (FALSE);
	else
	{
		i = 0;
		while (mtx_color[i])
		{
			if (!ft_isdigit(mtx_color[i][0]) || (ft_atoi(mtx_color[i]) < 0
					|| ft_atoi(mtx_color[i]) > 255))
			{
				ft_free_array(mtx_color);
				return (FALSE);
			}
			i++;
		}
	}
	ft_free_array(mtx_color);
	return (TRUE);
}

static int	validate_texture(char *line)
{
	int				check;
	size_t			file_len;
	size_t			exit_len;
	mlx_texture_t	*texture;
	int				fd;

	check = 1;
	file_len = ft_strlen(line);
	exit_len = ft_strlen(".png");
	texture = mlx_load_png(line);
	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	if (file_len <= exit_len || ft_strncmp(&line[file_len - 4], ".png",
			exit_len) != 0)
	{
		ft_printf("%dError\nTexture name must end with .png\n%d", RED, RESET);
		check = 0;
	}
	if (texture)
		mlx_delete_texture(texture);
	return (check);
}

static void	validate_map_content_exit(char **file, int *array)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (i <= 3)
			array[0] += validate_texture(file[i]);
		else if (i == 4 || i == 5)
			array[1] += validate_color(file[i]);
		else
			array[2] += validate_map_content2(file[i]);
		i++;
	}
}

int	validate_map_content(char *file)
{
	char	**tmp_file;
	int		*array;

	tmp_file = load_file(file);
	if (!tmp_file)
		return (FALSE);
	array = ft_calloc(20, sizeof(int));
	if (!array)
	{
		ft_free_array(tmp_file);
		return (FALSE);
	}
	validate_map_content_exit(tmp_file, array);
	if (array[0] == 4 && array[1] == 2 && array[2] == 0)
	{
		free(array);
		ft_free_array(tmp_file);
		return (TRUE);
	}
	free(array);
	ft_free_array(tmp_file);
	return (FALSE);
}
