NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx -g -fsanitize=address

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

MLX_ARCHIVE = .MLX42/build/libmlx42.a

SRCS = mandatory/cub3d.c mandatory/gnl_ut.c mandatory/gnl.c mandatory/parse.c \
mandatory/utiles.c mandatory/parse_colors.c mandatory/parse_textures.c mandatory/valid_map.c \
mandatory/allocate_free.c mandatory/raycasting.c mandatory/player.c mandatory/moves.c \
mandatory/window.c mandatory/initgame.c 

HEADS = mandatory/cub3d.h

OBJS = $(SRCS:.c=.o)

all : mlx $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX_ARCHIVE) -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $^ -o $@

$(OBJS) : %.o: %.c $(HEADS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@
mlx :
	@cd MLX42 && cmake -B build && cmake --build build -j4

clean :
	rm	-f $(OBJS) $(OBJSB)

fclean : clean
	rm	-f $(NAME) $(BONUS)

re : fclean all

.PHONY : clean
