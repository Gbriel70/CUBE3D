#==================================SETS========================================#

NAME = validate_tests
C = cc
CC_FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -ldl -lglfw -pthread -lm

TESTS_PATH = .
TESTS = $(wildcard $(TESTS_PATH)/*.c)
OBJS = $(TESTS:.c=.o)

MAIN_PATH = ..
MLX_PATH = $(MAIN_PATH)/libs/MLX42

MLX_PATH = libs/MLX42
MLX_INCLUDES = -I $(MLX_PATH)/include
MLX = $(MLX_PATH)/build/libmlx42.a

VALIDATE_SRC_PATH = ../srcs/validate_map
VALIDATE_SRC = $(wildcard $(VALIDATE_SRC_PATH)/*.c)
VALIDATE_OBJS = $(VALIDATE_SRC:.c=.o)

INCLUDES = -I $(MAIN_PATH)/includes -I $(MLX_PATH)/include

#==================================COLORS========================================#

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

#==================================RULES========================================#

all: libft $(NAME)

$(NAME): $(OBJS) $(VALIDATE_OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(C) $(CC_FLAGS) -o $(NAME) $(OBJS) $(VALIDATE_OBJS)  $(INCLUDES)
	@echo "$(GREEN)Compilation of $(NAME) complete!$(RESET)"

%.o: %.c
	@$(C) $(CC_FLAGS) -c $< -o $@

libft:
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	@$(MAKE) -C ../libs/libft
	@echo "$(YELLOW)Compilation of libft complete!$(RESET)"

mlx:
	@echo "$(YELLOW)Compiling MLX42...$(RESET)"
	@cmake $(MLX_PATH) -B $(MLX_PATH)/build > /dev/null 2>&1
	@make $(MLX_PATH)/build -j4 > /dev/null 2>&1
	@echo "$(YELLOW)Compilation of MLX42 complete!$(RESET)"

clean:
	@echo "$(RED)Cleaning $(NAME) objects...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(RED)Cleaning of $(NAME) objects complete!$(RESET)"

fclean: clean
	@echo "$(RED)Cleaning $(NAME) binary...$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)Cleaning of $(NAME) binary complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re main_lib