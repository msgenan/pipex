NAME = pipex
SRCS = ./src/pipex.c \
./src/take_path.c \
./src/utils.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./src/libft
LIBFT = $(LIBFT_PATH)/libft.a

COLOR_LIGHT_RED     =   \033[0;91m
COLOR_LIGHT_GREEN   =   \033[0;92m
COLOR_LIGHT_BLUE    =   \033[0;94m

all : $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(COLOR_LIGHT_GREEN)Make is done"

$(LIBFT):
	@if [ ! -d "$(LIBFT_PATH)" ]; then \
		echo "$(COLOR_LIGHT_BLUE)Cloning Libft..."; \
		git clone https://github.com/msgenan/Libft.git $(LIBFT_PATH); \
	fi
	@make -C $(LIBFT_PATH) > /dev/null 2>&1

clone : $(LIBFT)
	@echo "$(COLOR_BLUE)🌀 Cloned Eveything Necessary"

cclone :
	@rm -rf $(LIBFT_PATH)
	
clean :
	@make clean -C $(LIBFT_PATH) > /dev/null 2>&1
	@echo "$(COLOR_LIGHT_GREEN)🌿 Output files are Cleared"

fclean : clean
	@rm -rf $(NAME)

re : fclean all

gg : clean fclean cclone
	@clear
	@echo "$(COLOR_LIGHT_GREEN)🌿 Everthing Cleared"

.PHONY: all clean clone cclone fclean re gg