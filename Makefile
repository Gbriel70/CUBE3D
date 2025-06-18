#=================================SETS====================================#

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -ldl -lglfw -pthread -lm
HEADERS = $(wildcard includes/*.h)

#=================================FILES====================================#

SRC_PATH = srcs
SRCS = $(wildcard $(SRC_PATH)/*.c)
OBJS = $(SRCS:.c=.o)

PARSER_SRC_PATH = $(SRC_PATH)/parser
PARSER_SRC = $(wildcard $(PARSER_SRC_PATH)/*.c)
PARSER_OBJS = $(PARSER_SRC:.c=.o)

CLOSE_GAME_SRC_PATH = $(SRC_PATH)/close
CLOSE_GAME_SRC = $(wildcard $(CLOSE_GAME_SRC_PATH)/*.c)
CLOSE_GAME_OBJS = $(CLOSE_GAME_SRC:.c=.o)

VALIDATE_SRC_PATH = $(SRC_PATH)/validate_map
VALIDATE_SRC = $(wildcard $(VALIDATE_SRC_PATH)/*.c)
VALIDATE_OBJS = $(VALIDATE_SRC:.c=.o)

ACTIONS_SRC_PATH = $(SRC_PATH)/actions
ACTIONS_SRC = $(wildcard $(ACTIONS_SRC_PATH)/*.c)
ACTIONS_OBJS = $(ACTIONS_SRC:.c=.o)

START_SRC_PATH = $(SRC_PATH)/start
START_SRC = $(wildcard $(START_SRC_PATH)/*.c)
START_OBJS = $(START_SRC:.c=.o)

DRAW_SRC_PATH = $(SRC_PATH)/draw
DRAW_SRC = $(wildcard $(DRAW_SRC_PATH)/*.c)
DRAW_OBJS = $(DRAW_SRC:.c=.o)

LIBFT = libs/libft/libft.a

MLX_PATH = libs/MLX42
MLX_INCLUDES = $(MLX_PATH)/include/MLX42
MLX = $(MLX_PATH)/build/libmlx42.a

INCLUDES = -I includes -I $(MLX_INCLUDES)

#=================================COLORS====================================#

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
RESET = \033[0m

#=================================RULES====================================#

all: $(NAME)

$(NAME): $(OBJS) $(VALIDATE_OBJS) $(CLOSE_GAME_OBJS) $(ACTIONS_OBJS) $(START_OBJS) $(PARSER_OBJS) $(DRAW_OBJS) $(LIBFT) $(MLX)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(CC) $(filter %.o, $^) $(CFLAGS) $(filter %.a, $^) $(MLX_FLAGS) -o $@
	@echo "$(GREEN)Compilation of $(NAME) complete!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	@$(MAKE) -C libs/libft
	@echo "$(YELLOW)Compilation of libft complete!$(RESET)"

$(MLX):
	@echo "$(YELLOW)Compiling MLX42...$(RESET)"
	@cmake $(MLX_PATH) -B $(MLX_PATH)/build > /dev/null 2>&1
	@make -C $(MLX_PATH)/build -j4 > /dev/null 2>&1
	@echo "$(YELLOW)Compilation of MLX42 complete!$(RESET)"

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning up...$(RESET)"
	@$(MAKE) clean -C libs/libft
	@rm -f $(OBJS) $(VALIDATE_OBJS) $(CLOSE_GAME_OBJS) $(ACTIONS_OBJS) $(START_OBJS) $(PARSER_OBJS) $(DRAW_OBJS)
	@rm -f $(MLX_PATH)/build/*.o
	@echo "$(RED)Cleanup complete!$(RESET)"

fclean: clean
	@echo "$(MAGENTA)Cleaning up...$(RESET)"
	@$(MAKE) fclean -C libs/libft
	@rm -f $(MLX_PATH)/build/*.a
	@rm -f $(NAME)
	@echo "$(MAGENTA)Cleanup complete!$(RESET)"

re: fclean all

#=================================VALGRIND====================================#

leak: $(NAME)
	@echo "$(GREEN)Running Valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
	@echo "$(GREEN)Valgrind complete!$(RESET)"

#=================================PUSH LIB====================================#

push:
	@echo "$(YELLOW)Pushing to libft...$(RESET)"
	@git submodule update --init --recursive
	@echo "$(YELLOW)Push to libft complete!$(RESET)"

#=================================PHONY===================================#

.PHONY: all clean fclean re