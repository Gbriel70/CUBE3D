#==================================SETS========================================#

NAME = validate_tests
C = cc
CC_FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -ldl -lglfw -pthread -lm

TESTS_PATH = .
TESTS = $(wildcard $(TESTS_PATH)/*.c)
OBJS = $(TESTS:.c=.o)

MLX_PATH = ../libs/MLX42
MLX_INCLUDES = $(MLX_PATH)/include/MLX42
MLX = $(MLX_PATH)/build/libmlx42.a

LIBFT = ../libs/libft/libft.a

VALIDATE_SRC_PATH = ../srcs/validate_map
VALIDATE_SRC = $(wildcard $(VALIDATE_SRC_PATH)/*.c)
VALIDATE_OBJS = $(VALIDATE_SRC:.c=.o)

CLOSE_SRC_PATH = ../srcs/close
CLOSE_SRC = $(wildcard $(CLOSE_SRC_PATH)/*.c)
CLOSE_OBJS = $(CLOSE_SRC:.c=.o)

PARSER_SRC_PATH = ../srcs/parser
PARSER_SRC = $(wildcard $(PARSER_SRC_PATH)/*.c)
PARSER_OBJS = $(PARSER_SRC:.c=.o)

ACTIONS_SRC_PATH = ../srcs/actions
ACTIONS_SRC = $(wildcard $(ACTIONS_SRC_PATH)/*.c)
ACTIONS_OBJS = $(ACTIONS_SRC:.c=.o)

START_SRC_PATH = ../srcs/start
START_SRC = $(wildcard $(START_SRC_PATH)/*.c)
START_OBJS = $(START_SRC:.c=.o)

INCLUDES = -I includes -I $(MLX_INCLUDES)

#==================================COLORS========================================#

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

#==================================RULES========================================#

all: libft mlx $(NAME)

$(NAME): $(OBJS) $(VALIDATE_OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(C) $(OBJS) $(VALIDATE_OBJS) $(CLOSE_OBJS) $(PARSER_OBJS) $(ACTIONS_OBJS) $(START_OBJS) $(CC_FLAGS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Compilation of $(NAME) complete!$(RESET)"

%.o: %.c
	@$(C) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

libft:
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	@$(MAKE) -C ../libs/libft
	@echo "$(YELLOW)Compilation of libft complete!$(RESET)"

mlx:
	@echo "$(YELLOW)Compiling MLX42...$(RESET)"
	@cmake $(MLX_PATH) -B $(MLX_PATH)/build > /dev/null 2>&1
	@make -C $(MLX_PATH)/build -j4 > /dev/null 2>&1
	@echo "$(YELLOW)Compilation of MLX42 complete!$(RESET)"

clean:
	@echo "$(RED)Cleaning $(NAME) objects...$(RESET)"
	@rm -f $(OBJS) $(VALIDATE_OBJS) $(CLOSE_OBJS) $(PARSER_OBJS) $(ACTIONS_OBJS) $(START_OBJS)
	@$(MAKE) clean -C ../libs/libft
	@$(MAKE) clean -C $(MLX_PATH)/build
	@echo "$(RED)Cleaning of $(NAME) objects complete!$(RESET)"

fclean: clean
	@echo "$(RED)Cleaning $(NAME) binary...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) fclean -C ../libs/libft
	@rm -rf $(MLX_PATH)/build
	@echo "$(RED)Cleaning of $(NAME) binary complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re main_lib