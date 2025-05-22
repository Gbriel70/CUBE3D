/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:58:18 by gabastos          #+#    #+#             */
/*   Updated: 2025/05/21 10:21:29 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libs/libft/includes/not_in_standard_includes/ft_printf_bonus.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>

/*Macros*/
# define WIDTH 800
# define HEIGHT 600
# define MINI_WIDTH 200
# define MINI_HEIGHT 200
# define SPEED 3.0
# define ROTATE_SPEED 3.0
# define WALL_OFFSET 0.3
# define WEAPON_FRAMES 4
# define REPEAT_FRAME 4

/*Structs*/
typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	char			*path;
	int				content_rows;
	char			**content;
	mlx_texture_t	*north_tex;
	mlx_texture_t	*south_tex;
	mlx_texture_t	*west_tex;
	mlx_texture_t	*east_tex;
	int32_t			floor_color;
	int32_t			ceiling_color;
	char			**layout;
	size_t			layout_rows;
	size_t			layout_columns;
}	t_map;

typedef struct s_wall
{
	int				height;
	int				line_start;
	int				line_end;
	mlx_texture_t	*texture;
	t_coord			tex;
	int				color;
}	t_wall;

typedef struct s_dda
{
	int			pixel_x;
	float		plane_ratio;
	t_vector	dir;
	t_vector	delta_dist;
	t_vector	dist_side;
	t_coord		map;
	t_coord		step;
	int			hit_side;
	float		perp_dist;
}	t_dda;

typedef struct s_data
{
	t_map			map;
	mlx_t			*mlx;
	mlx_image_t		*minimap_img;
	mlx_image_t		*playerview_img;
	mlx_image_t		*wand_img[WEAPON_FRAMES];
	mlx_texture_t	*wand_tex[WEAPON_FRAMES];
	bool			shoot;
	t_vector		player;
	t_vector		dir;
	t_vector		plane;
	t_dda			ray;
	float			plane_ratio;
	float			frame_time;
}	t_data;

// Parser

void	parse_map(t_data *game);
int		extract_color(char *color);
int		extract_floor_ceiling_color(t_data *game);
void	extract_map(t_data *game);
void	extract_weapon_texture(t_data *game);
void	extract_wall_texture(t_data *game);
void	player_initial_setup(t_data *game, int *player);

#endif