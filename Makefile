NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = mandatory/cub3d.c mandatory/gnl_ut.c mandatory/gnl.c mandatory/main.c mandatory/parse.c mandatory/utiles.c mandatory/parse_colors.c mandatory/parse_textures.c mandatory/valid_map.c mandatory/allocate_free.c

HEADS = mandatory/cub3d.h

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $@

$(OBJS) : %.o: %.c $(HEADS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm	-f $(OBJS) $(OBJSB)

fclean : clean
	rm	-f $(NAME) $(BONUS)

re : fclean all

.PHONY : clean
