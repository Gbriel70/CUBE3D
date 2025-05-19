#=================================SETS====================================#

NAME = CUBE3D
CC = cc
CFLAGS = -Wall -Wextra -Werror

#=================================FILES====================================#

SRC_PATH = srcs
SRCS = $(wildcard $(SRC_PATH)/*.c)
OBJS = $(SRCS:.c=.o)
INCLUDES = -I includes
LIBFT = libs/libft/libft.a

#=================================COLORS====================================#

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m

#=================================VALGRIND====================================#

leak: all
	@echo "$(GREEN)Running Valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
	@echo "$(GREEN)Valgrind complete!$(RESET)"

#=================================RULES====================================#

all: libft $(NAME)

libft:
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	@$(MAKE) -C libs/libft
	@echo "$(YELLOW)Compilation of libft complete!$(RESET)"

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDES)
	@echo "$(GREEN)Compilation of $(NAME) complete!$(RESET)"

clean:
	@echo "$(RED)Cleaning up...$(RESET)"
	@$(MAKE) clean -C libs/libft
	@rm -f $(OBJS)
	@echo "$(RED)Cleanup complete!$(RESET)"

fclean: clean
	@echo "$(MAGENTA)Cleaning up...$(RESET)"
	@$(MAKE) fclean -C libs/libft
	@rm -f $(NAME)
	@echo "$(MAGENTA)Cleanup complete!$(RESET)"

re: fclean all

#=================================PHONY===================================#

.PHONY: all clean fclean re libft