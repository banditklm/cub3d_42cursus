/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:45:59 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/15 22:28:38 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <sys/time.h>
# define BUFFER_SIZE 10
# define INF INFINITY
# define SCREEN_WIDTH 1500
# define SCREEN_HEIGHT 1000
# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200
# define CELL_SIZE 32
# define SPEED_MOVE 0.3
# define SPEED_ROT 0.1
# define SPEED_MOS 0.1
# define TEXTURE_SIZE 32
# define DOOR_OPEN_DIST 1.5

typedef struct s_player
{
	double	x_pos;
	double	y_pos;
	double	x_dir;
	double	y_dir;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	rayd_x;
	double	rayd_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
}	t_ray;

typedef struct s_weapon
{
	int			height;
	int			width;
	int			start_x;
	int			start_y;
	double		tex_x;
	double		tex_y;
	uint32_t	tmp_value;
	int			index;
	int			color;
}	t_weapon;

typedef struct s_mini
{
	int	player_x;
	int	player_y;
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	tile_x;
	int	tile_y;
}	t_mini;

typedef struct s_key
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
	bool	space;
	bool	enter;
}	t_key;

typedef struct s_line
{
	int	line_order;
	int	no_line;
	int	so_line;
	int	we_line;
	int	ea_line;
	int	f_line;
	int	c_line;
	int	do_line;
	int	sp_line;
	int	map_line;
}	t_line;

typedef struct s_sprite
{
	double			sprite_x;
	double			sprite_y;
}	t_sprite;

typedef struct s_door
{
	int	is_open;
	int	x;
	int	y;
}	t_door;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		player;
	void			*mlx_ptr;
	void			*mlx_win;
	int				screen_width;
	int				screen_height;
	t_ray			ray;
	double			pwd;
	int				pixel_x;
	int				pixel_y;
	int				line_h;
	char			**map;
	t_line			order;
	int				start_line;
	int				end_line;
	char			*no;
	char			*we;
	char			*ea;
	char			*so;
	char			*doo;
	char			*sp;
	int				floor_color[3];
	int				ceiling_color[3];
	int				map_width;
	int				map_lenght;
	int				x_player;
	int				y_player;
	char			direction;
	int				end_map;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	mlx_texture_t	*door;
	mlx_texture_t	*sprite;
	mlx_texture_t	*frames[30];
	int				side_wall;
	int				wall_x;
	int				wall_start;
	double			tex_pos_x;
	double			tex_pos_y;
	int				n_of_doors;
	t_door			*doors;
	int				hit_d;
	int				hit_s;
	t_sprite		*sprites;
	int				sprite_n;
	t_key			key;
	bool			is_animating;
	t_weapon		weapon;
	t_mini			m;
	int				color;
	bool			is_play;
}	t_data;

typedef struct s_coll
{
	void			*ptr;
	struct s_coll	*next;
}	t_coll;

char			*ft_strchr(const char *string, int c );
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*get_next_line(int fd);
int				ft_strlen(char *s);
char			**ft_split(char *s, char c);
char			*ft_strdup(char *s);
int				ft_strcmp(char *s1, char *s2);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strjoin(char *s1, char *s2);
void			parse(t_data *file_data, char *file_name);
int				isonly_spaces(char *input);
int				s_array(char **str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				skip_beg_spaces(char *row);
int				skip_end_spaces(char *row);
void			ft_error(char type);
void			set_texture(t_data *data, char *line);
int				out_bounds(int i, char **map);
void			set_colors(t_data *data, char *line);
int				open_cub_file(char *str);
int				surrounded_by_walls(char **map, int i, int j, int k);
int				deep_surr_walls(char **map, int i, int j);
int				composition_checker(t_data *data, int i, int j);
char			*extract_content(char *line);
int				ft_isdigit(int c);
int				check_spaces(char *splited);
int				ft_atoi(const char *str);
void			*c_malloc(size_t size, int flag);
void			map_lenght(t_data *data);
void			map_width(t_data *data);
int				is_space(char c);
void			manip_file(t_data *data, int fd, int valid_infonumber);
int				count_spaces(char *number);
void			load_all_text(t_data *data);
void			destroy_text(t_data *data);
void			check_file_ext(char *str);
int				rgb(int r, int g, int b);
mlx_texture_t	*get_wall_texture(t_data *data);
void			put_texture(t_data *data, int start_line, int end_line, int x);
void			fill_text(t_data *data, int i);
void			where_doors(t_data *data);
void			check_doors(t_data *data);
void			where_sprites(t_data *data);
void			put_pixel_to_image(t_data *data, int x, int y, int color);
double			distance(int x1, int y1, int x2, int y2);
void			check_doors(t_data *data);
t_door			*find_which_door(t_data *data, int x, int y);
void			check_dr_or_sp(t_data *data, int map_x, int map_y, int *hit_w);

//
void			init_data(t_data *data);
void			init_player(t_data *data);
void			raycast(t_data *data);
void			raytrace(t_data *data, int map_x, int map_y, int x);
void			draw_ceiling(t_data *data, int start_line, int x, int color);
void			draw_floor(t_data *data, int end_line, int x, int color);
void			draw_line(t_data *data, double pwd, int x);
void			init_dist(t_data *data, int x);
void			init_steps(t_data *data, int map_x, int map_y);
void			check_steps(t_data *data, int *map_x, int *map_y, int *sid_w);
void			put_pixel_to_image(t_data *data, int x, int y, int color);
void			render_frame(void *param);
void			ft_destroy_win(void *param);
void			mouse_move(double x, double y, void *param);
int				rot_left(t_data *data, double rot_speed);
int				rot_right(t_data *data, double rot_speed);
int				move_up(t_data *data, double move_speed);
int				move_down(t_data *data, double move_speed);
int				move_right(t_data *data, double move_speed);
int				move_left(t_data *data, double move_speed);
void			move_to(void *param);
void			mini_map(t_data *data);
void			key_hook(mlx_key_data_t keydata, void *param);
void			key_release(mlx_key_data_t keydata, void *param);
void			init_keys(t_data *data);
int				color_from_pixel(mlx_texture_t *texture, int index);
void			load_frames(t_data *data);
char			*ft_itoa(int n);
void			put_weapon(t_data *data);
void			play_s2(t_data *data);
void			play_s1(char *path);


#endif