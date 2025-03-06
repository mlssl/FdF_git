CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./get_next_line -I./minilibx_macos
LDFLAGS = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
RM = rm -f

SRCS = 	main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		utils/ft_split.c \
		utils/ft_atoi.c \
		error/error.c \
		parsing/parsing.c \
		parsing/count.c \
		draw/draw.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME = fdf
HEADER = ./includes/fdf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
