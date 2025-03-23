NAME = pipex
SRCS = ./src/pipex.c \
       ./src/take_path.c \
       ./src/utils.c
CC = cc
BUILD_DIR = build
CFLAGS = -Wall -Wextra -Werror
MY_LIB_PATH = ./src/my_lib
MY_LIB = $(MY_LIB_PATH)/my_lib.a
OBJS = $(SRCS:./src/%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(MY_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MY_LIB) -o $(NAME)
	@echo "✅ Build completed."

$(MY_LIB):
	@make -C $(MY_LIB_PATH) > /dev/null 2>&1

$(BUILD_DIR)/%.o: ./src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	@make clean -C $(MY_LIB_PATH) > /dev/null 2>&1
	@rm -rf build
	@echo "🌿 Output files are Cleared"

fclean: clean
	@make fclean -C $(MY_LIB_PATH) > /dev/null 2>&1
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
