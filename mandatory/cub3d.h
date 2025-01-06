#ifndef CUB_H
#define CUB_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
# include <mlx.h>
# include <math.h>
# define pi M_PI
# define BUFFER_SIZE 10

typedef struct s_player
{
    double x_pos;
    double y_pos;
    double x_dir;
    double y_dir;
    double fov;
}   t_player;

typedef struct s_line
{
    int line_order;
    int NO_line;
    int SO_line;
    int WE_line;
    int EA_line;
    int F_line;
    int C_line;
    int map_line;
} t_line;

typedef struct s_data
{
     t_player   player;
    void        *mlx_ptr;
    void        *mlx_win;
    char        **map;
    t_line      order;
    char        *NO;
    char        *WE;
    char        *EA;
    char        *SO;
    int         floor_color[3];
    int         ceiling_color[3];
    int         map_width;
    int         map_lenght;
    int         x_player;
    int         y_player;
    char        direction;
    int         end_map;
} t_data;

typedef struct s_coll
{
	void			*ptr;
	struct s_coll	*next;
}	t_coll;

char	*ft_strchr(const char *string, int c );
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
int	ft_strlen(char *s);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s);
int	ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2);
void parse(t_data *file_data, char *file_name);
int	isonly_spaces(char *input);
int sizeof_array(char **str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int skip_beg_spaces(char *row);
int skip_end_spaces(char *row);
void ft_error(char type);
void set_texture(t_data *data, char *line);
void set_colors(t_data *data, char *line);
int	open_cub_file(char *str);
int surrounded_by_walls(char **map);
int space_btw_walls(char **map);
int	composition_checker(t_data *data, int i, int j);
char *extract_content(char *line);
int	ft_isdigit(int c);
void	*c_malloc(size_t size, int flag);

#endif