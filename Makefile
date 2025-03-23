NAME = pipex
SRCS = ./src/pipex.c \
./src/take_path.c \
./src/utils.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
MY_LIB_PATH = ./src/my_lib
MY_LIB = $(MY_LIB_PATH)/my_lib.a

all : $(NAME)

$(NAME): $(MY_LIB) $(SRCS)
	$(CC) $(SRCS) $(MY_LIB) -o $(NAME)
	@echo "✅ Build completed."

$(MY_LIB):
	@make -C $(MY_LIB_PATH) > /dev/null 2>&1

$(BUILD_DIR)/%.o: ./src/%.c | $(BUILD_DIR)/actions
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean :
	@make clean -C $(LIBFT_PATH) > /dev/null 2>&1
	@echo "$(COLOR_LIGHT_GREEN)🌿 Output files are Cleared"

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re