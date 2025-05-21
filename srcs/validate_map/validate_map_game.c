#include "../../includes/cube.h"

void flood_fill(char **file, int x, int y, int *open_map)
{
	int m;
	int n;

	m = ft_strlen(file[x]);
	n = ft_mtxlen(file);
	if (file[x][y] == ' ')
		(*open_map)++;
	if (x < 0 || x >= n || y < 0 || y >= m)
		return ;
	if (file[x][y] != '0')
		return ;
	if (x == 6 || x == n - 1 || y == 0 || y == m - 1)
		(*open_map)++;
	file[x][y] = '.';
	if (x + 1 < n)
		flood_fill(file, x + 1, y, open_map);
	if (x - 1 >= 0)
		flood_fill(file, x - 1, y, open_map);
	if (y + 1 < m)
		flood_fill(file, x, y + 1, open_map);
	if (y - 1 >= 0)
		flood_fill(file, x, y - 1, open_map);
}

int validate_map_game(char *file)
{
	char **file;
	int *player;
	int open_map;

	file = load_file(file);
	player = load_player(file);
	open_map = 0;
	if (player[0] != 1)
		return (FALSE);
	else
	{
		flood_fill(file, player[1], player[2], &open_map);
		if (open_map != 0)
		{
			ft_free_array(file);
			return (FALSE);
		}
	}
	ft_free_array(file);
	free(player);
	return (TRUE);
}
