NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./minilibx_macos
LDFLAGS = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

RM = rm -f

SRCS = 	main.c \
		get_next_line.c \
		utils/ft_split.c \
		utils/ft_atoi.c

OBJS = $(SRCS:.c=.o)

HEADER = ./includes/fdf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
