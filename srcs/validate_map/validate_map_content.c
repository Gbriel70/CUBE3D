#include "cube.h"

int validate_color(char *line)
{
	char **mtx_color;
}

int validate_texture(char *line)
{
	int check;
	size_t file_len;
	size_t exit_len;
	mlx_texture_t *texture;

	check = 1;
	file_len = ft_strlen(line);
	exit_len = ft_strlen(".png");
	texture = mlx_load_png(line);
	if (file_len <= exit_len || ft_strncmp(&line[file_len - 4], ".png", exit_len) != 0)
	{
		ft_printf("%dError\nTexture name must end with .png\n%d", RED, RESET);
		check = 0;
	}
	if (texture)
		mlx_delete_texture(texture);
	return (check);
}

void validate_map_content_exit(char **file, int *array)
{
	int i;

	i = 0;
	while (file[i])
	{
		if (i <= 3)
			array[0] += validate_texture(file[i]);
		else if (i == 4 || i == 5)
			array[1] += validate_color(file[i]);
		else
			array[2] += validate_map_content(file[i]);
		i++;
	}
}

int validate_map_content(char *file)
{
	char **file;
	int *array;

	file = load_file(file);
	array = ft_calloc(20, sizeof(int));
	validate_map_content_exit(file, array);
}