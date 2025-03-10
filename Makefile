CC = cc
# CFLAGS = -Wall -Wextra -Werror -I./includes -I./get_next_line -I./minilibx_macos
#LDFLAGS = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror -I./includes -I./get_next_line -I./minilibx
LDFLAGS = -L./minilibx -lmlx -lX11 -lXext -lGL -lm

SRCS = 	main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		utils/ft_split.c \
		utils/ft_atoi.c \
		error/error.c \
		parsing/parsing.c \
		parsing/count.c \
		draw/draw.c

OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
NAME = fdf
HEADER = ./includes/fdf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re make
