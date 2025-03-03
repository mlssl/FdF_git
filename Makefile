NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./includes -I./minilibx_macos -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

RM      = rm -f

SRCS = main.c \
		get_next_line.c \
		utils/ft_split.c

OBJS = $(SRCS:.c=.o)

HEADER = ./includes/push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re make