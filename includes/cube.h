#ifndef CUBE_H
#define CUBE_H

//LIBFT
#include "../libs/libft/includes/not_in_standard_includes/ft_printf_bonus.h"
#include "../libs/libft/includes/not_in_standard_includes/get_next_line.h"
#include "../libs/libft/includes/ft_string_functions.h"
#include "../libs/libft/includes/ft_stdlib.h"

//MINILIBX
#include "../libs/MLX42/include/MLX42/MLX42.h"
#include "../libs/MLX42/include/MLX42/MLX42_Int.h"

//LIBS
#include <fcntl.h>
#include <unistd.h>

//MACROS
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m"

#define TRUE 1
#define FALSE 0

//MAP VALIDATION
void validate_map(int ac, char **av);
int valid_map_count(char *filename);

//MAP VALIDATION UTILS
void replace_char(char *str, char old, char new);
int is_empty_line(char *line);

#endif