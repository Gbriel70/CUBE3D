/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:58:18 by gabastos          #+#    #+#             */
/*   Updated: 2025/06/16 10:26:54 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

//LIBFT
# include "../libs/libft/includes/not_in_standard_includes/ft_printf_bonus.h"
# include "../libs/libft/includes/not_in_standard_includes/get_next_line.h"
# include "../libs/libft/includes/not_in_standard_includes/not_in_standard.h"
# include "../libs/libft/includes/ft_string_functions.h"
# include "../libs/libft/includes/ft_stdlib.h"
# include "../libs/libft/includes/ft_ctype.h"
// MINILIBX
# include "../libs/MLX42/include/MLX42/MLX42.h"
//LIBS
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

//MACROS
# define WIDTH 1200
# define HEIGHT 900
# define MINI_WIDTH 200
# define MINI_HEIGHT 200
# define SPEED 3.0
# define ROTATE_SPEED 3.0
# define WALL_OFFSET 0.3
# define WEAPON_FRAMES 4
# define REPEAT_FRAME 4
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define RESET "\033[0m"

# define TRUE 1
# define FALSE 0

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

//DRAW
void	draw_player_view(void *param);
void	raycast_walls(t_data *game);
void	render_wall_tex_to_screen(t_data *game, t_dda *ray);
void	draw_minimap(void *param);

// START
void	start_game(t_data *game);
void	create_mlx_images(t_data *game);

// PARSER
void	parse_map(t_data *game);
int		extract_color(char *color);
void	extract_floor_ceiling_color(t_data *game);
void	extract_map(t_data *game);
void	extract_weapon_texture(t_data *game);
void	extract_wall_texture(t_data *game);
void	player_initial_setup(t_data *game, int *player);

//CLOSE
void	close_game(void *param);
void	handle_error(char *message, t_data *game, int stage);
void	ft_free_matrix(char **mtx);

//ACTIONS
void	move_player(t_data *game, float speed);
void	move_left(t_data *game, float speed);
void	move_right(t_data *game, float speed);
void	rotate_player(t_data *game, float speed);
void	shoot(t_data *game);
void	key_press(void *param);
void	cursor_movement(double mouse_x, double mouse_y, void *param);
void	mouse_click(void *param);

//MAP VALIDATION
void	validate_map(int ac, char **av);
int		valid_map_count(char *filename);
int		validate_map_content(char *file);
short	valid_map_name(char *filename);
int		validate_map_game(char *file);
char	**load_file(char *filename);
int		*load_player(char **file);
int		hash_element(char *line);
int		file_rows(char *filename);

//MAP VALIDATION UTILS
void	replace_char(char *str, char old, char new);
int		is_empty_line(char *line);
int		ft_mtxlen(char **mtx);
void	ft_free_array(char **array);

#endif