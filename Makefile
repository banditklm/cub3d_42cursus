NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx -g -fsanitize=address

MLX_PATH = MLX42/build
MLX_ARCHIVE = $(MLX_PATH)/libmlx42.a

SRCS = mandatory/cub3d.c mandatory/gnl_ut.c mandatory/gnl.c mandatory/parse.c \
mandatory/utiles.c mandatory/parse_colors.c mandatory/parse_textures.c mandatory/valid_map.c \
mandatory/allocate_free.c mandatory/raycasting.c mandatory/player.c mandatory/moves.c \
mandatory/window.c mandatory/initgame.c 

HEADS = mandatory/cub3d.h

OBJS = $(SRCS:.c=.o)

all: mlx $(NAME)

$(NAME): $(MLX_ARCHIVE) $(OBJS)
	$(CC) $(CFLAGS) $^ -Iinclude -L"/usr/lib/x86_64-linux-gnu/" -lglfw $(MLX_ARCHIVE) -lm -o $@

%.o: %.c $(HEADS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

mlx:
	@cd MLX42 && cmake -B build && cmake --build build -j4

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
