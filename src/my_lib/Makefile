NAME = my_lib.a
SRCS = ft_strlen.c \
ft_sttlcat.c \
ft_strlcpy.c \
ft_split.c \
ft_strdup.c \
ft_substr.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)


re: fclean all

.PHONY: all clean re fclean bonus