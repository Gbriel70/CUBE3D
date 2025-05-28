#include "../../includes/cube.h"

void	extract_map(t_data *game)
{
	size_t	rows;
	size_t	columns;

	game->map.layout = &game->map.content[6];
	rows = 0;
	columns = 0;
	while (game->map.layout[rows])
	{
		if (columns < ft_strlen(game->map.layout[rows]))
			columns = ft_strlen(game->map.layout[rows]);
		rows++;
	}
	game->map.layout_rows = rows;
	game->map.layout_columns = columns;
}