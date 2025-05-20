#include "cube.h"

static short valid_map_name(char *filename)
{
	int len;
	int exit_len;
	
	len = ft_strlen(filename);
	exit_len = ft_strlen(".cub");
	if (len <= exit_len || ft_strncmp(&filename[len - 4], ".cub", exit_len) != 0)
	{
		ft_printf("%dError\nInvalid map name. Map name must end with .cub\n%d", RED, RESET);
		return (FALSE);
	}
	return (TRUE);
}

void validate_map(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("%dError\nUsage: ./cub3D <map.cub>\n%d", RED, RESET);
		exit(1);
	}
	if (valid_map_name(av[1]) == FALSE)
		exit(1);
	if (valid_map_count(av[1]) == FALSE)
		exit(1);
	if (validate_map_content(av[1]) == FALSE)
		exit(1);
}
