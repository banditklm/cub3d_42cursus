CC = cc

CFLAGS = -w#-Wall -Wextra -Werror 
# -g -fsanitize=address

NAME = cub3D

BONUS = cub3D_Bonus

MLX_ARCHIVE = MLX42/build/libmlx42.a

SRC = mandatory/cub3d.c mandatory/gnl_ut.c mandatory/gnl.c mandatory/initgame.c mandatory/parse.c mandatory/parse2.c\
mandatory/utiles.c mandatory/utiles2.c mandatory/utiles3.c mandatory/utiles4.c mandatory/parse_colors.c mandatory/parse_textures.c mandatory/valid_map.c mandatory/valid_map2.c\
mandatory/allocate_free.c mandatory/raycasting.c mandatory/moves.c mandatory/moves2.c mandatory/window.c \
mandatory/handle_keys.c mandatory/drawing.c mandatory/texture.c

HEADS = mandatory/cub.h

SRCB = bonus/cub3d.c bonus/gnl_ut.c bonus/gnl.c bonus/initgame.c bonus/parse.c bonus/parse2.c\
bonus/utiles.c bonus/utiles2.c bonus/utiles3.c bonus/utiles4.c bonus/parse_colors.c bonus/parse_textures.c \
bonus/valid_map.c bonus/valid_map2.c bonus/valid_map3.c bonus/allocate_free.c bonus/raycasting.c  bonus/moves.c \
bonus/window.c bonus/minimap.c bonus/handle_keys.c bonus/animation.c bonus/moves2.c \
bonus/mouse_move.c bonus/drawing.c bonus/checker.c bonus/init_param.c bonus/play_sound.c

HEADSB = bonus/cub.h

OBJS = $(SRC:.c=.o)

OBJSB = $(SRCB:.c=.o)

all: mlx $(NAME)

bonus: mlx $(BONUS)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(MLX_ARCHIVE) -Iinclude -lglfw -L/goinfre/kelmounj/.brew/Cellar/glfw/3.4/lib/ -lglfw -lm $^ -o $@
	@echo "\033[32mMaking Completed✅"

$(BONUS) : $(OBJSB)
	@$(CC) $(CFLAGS) $(MLX_ARCHIVE) -Iinclude -lglfw -L/goinfre/kelmounj/.brew/Cellar/glfw/3.4/lib/ -lglfw -lm $^ -o $@
	@echo "\033[32mBonus Completed🔻"

$(OBJS) : %.o: %.c $(HEADS) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSB) : %.o: %.c $(HEADSB) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

mlx:
	@cd MLX42 && cmake -B build && cmake --build build -j4

clean :
	@rm	-f $(OBJS) $(OBJSB)
	@if [ -d ".MLX42/build" ]; then \
		cd MLX42/build && make clean; \
    fi
	@echo "\033[0;33mCleaning Completed 🧼✨"

fclean : clean
	@rm	-f $(NAME) $(BONUS) .MLX42/build
	@echo "\033[0;31mRemoving Completed 🗑"

re : fclean all 

.PHONY : clean mlx