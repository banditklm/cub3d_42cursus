/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:45:59 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/10 17:25:20 by kelmounj         ###   ########.fr       */
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
# define SCREEN_WIDTH 1800
# define SCREEN_HEIGHT 1000
# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200
# define CELL_SIZE 32
# define SPEED_MOVE 0.2
# define SPEED_ROT 0.1
# define TEXTURE_SIZE 32

typedef struct s_player
{
	double	x_pos;
	double	y_pos;
	double	x_dir;
	double	y_dir;
	double	plane_x;
	double	plane_y;
	double	fov;
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
}	t_ray;

typedef struct s_key
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
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
	int	map_line;
}	t_line;

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
	int				floor_color[3];
	int				ceiling_color[3];
	int				map_width;
	int				map_lenght;
	int				x_player;
	int				y_player;
	char			direction;
	uint32_t		*color;
	int				end_map;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	int				side_wall;
	int				wall_x;
	int				wall_start;
	double			tex_pos_x;
	double			tex_pos_y;
	t_key			key;
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
void			manip_file(t_data *file_data, int fd, int valid_infonumber);
int				isonly_spaces(char *input);
int				s_array(char **str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				skip_beg_spaces(char *row);
int				skip_end_spaces(char *row);
void			ft_error(char type);
void			set_texture(t_data *data, char *line);
void			set_colors(t_data *data, char *line, int i);
int				open_cub_file(char *str);
int				surrounded_by_walls(char **map, int i, int j, int k);
int				deep_surr_walls(char **map, int i, int j);
int				composition_checker(t_data *data, int i, int j, int p_counter);
char			*extract_content(char *line);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			*c_malloc(size_t size, int flag);
void			map_lenght(t_data *data);
void			map_width(t_data *data);
int				is_space(char c);
int				count_spaces(char *number);
void			load_all_text(t_data *data);
void			destroy_text(t_data *data);
void			check_file_ext(char *str);
int				rgb(int r, int g, int b);
mlx_texture_t	*get_wall_texture(t_data *data);
void			put_texture(t_data *data, int start_line, int end_line, int x);
void			fill_text(t_data *data, int i);
//
void			init_data(t_data *data);
void			init_player(t_data *data);
void			raycast(t_data *data);
void			init_dist(t_data *data, int x);
void			put_pixel_to_image(t_data *data, int x, int y, int color);
void			render_frame(void *param);
void			ft_destroy_win(void *param);
void			mouse_move(double x, double y, void *param);
void			mini_map(t_data *data);
void			key_hook(mlx_key_data_t keydata, void *param);
void			key_release(mlx_key_data_t keydata, void *param);
void			move_to(void *param);
int				move_up(t_data *data, double move_speed);
int				move_down(t_data *data, double move_speed);
int				move_right(t_data *data, double move_speed);
int				move_left(t_data *data, double move_speed);
void			init_keys(t_data *data);
void			draw_line(t_data *data, double pwd, int x);

#endif