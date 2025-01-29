#include "cub3d.h"
int check_order(t_data *data)
{
	if (data->order.map_line < data->order.C_line
		|| data->order.map_line < data->order.F_line
		|| data->order.map_line < data->order.NO_line
		|| data->order.map_line < data->order.SO_line
		|| data->order.map_line < data->order.EA_line
		|| data->order.map_line < data->order.WE_line)
		return (0);
	return (1);
}
char *extract_content(char *line)
{
	int end;
    int start;
    char *content;

    end = ft_strlen(line) - 1;
    while (end >= 0 && (line[end] == ' ' || line[end] == '\t' || line[end] == '\n'))
        end--;
    start = 0;
    while (line[start] && (line[start] == ' ' || line[start] == '\t'))
        start++;
    content = c_malloc(sizeof(char) * (end - start + 2), 1);
    if (!content)
        ft_error('a');
    ft_strncpy(content, &line[start], end - start + 1);
    content[end - start + 1] = '\0';
    return (content);
}


int manip_line(t_data *data, char *line, int *nb, char **joined)
{
	if (!ft_strncmp(line + skip_beg_spaces(line), "NO ", 3)
		|| !ft_strncmp(line + skip_beg_spaces(line), "SO ", 3)
		|| !ft_strncmp(line + skip_beg_spaces(line), "EA ", 3)
		|| !ft_strncmp(line + skip_beg_spaces(line), "WE ", 3))
	{
		set_texture(data, line);
		(*nb)++;
		return (1);
	}
	else if (!ft_strncmp(line + skip_beg_spaces(line), "F ", 2)
			|| !ft_strncmp(line + skip_beg_spaces(line), "C ", 2))
	{
		set_colors(data, line);
		(*nb)++;
		return (1);
	}
	else if (!ft_strncmp(line + skip_beg_spaces(line), "1", 1)
			|| !ft_strncmp(line + skip_beg_spaces(line), "0", 1))
	{
		if (data->end_map)
			return (0);
		data->order.map_line = data->order.line_order;
		*joined = ft_strjoin(*joined, line);
		return (1);
	}
	else 
	{
		if (isonly_spaces(line))
			return (1);
		return (0);
	}
}
void manip_file(t_data *file_data, int fd)
{
	int valid_infonumber;
	char *line;
	char *joined;
 
	file_data->order.line_order = 0;
	file_data->end_map = 0;
	joined = ft_strdup("");
	valid_infonumber = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strcmp(joined, "") && !ft_strcmp(line, "\n"))
		{
			file_data->end_map = 1;
		}
		if (!ft_strcmp(line, "\n"))
			continue ;
		
		if (!manip_line(file_data, line, &valid_infonumber, &joined))
		{
			ft_error('f');
		}
		file_data->order.line_order++;
	}
	file_data->map = ft_split(joined, '\n');
	if (file_data->map[0])
		valid_infonumber++;
	if (valid_infonumber != 7 || !file_data->NO || !file_data->SO
			|| !file_data->EA || !file_data->WE)
	{
		ft_error('f');
	}
}

void parse(t_data *file_data, char *file_name)
{
	int	fd;

	fd = open_cub_file(file_name);
	file_data->NO = NULL;
	file_data->SO = NULL;
	file_data->EA = NULL;
	file_data->WE = NULL;
	manip_file(file_data, fd);
	if (!check_order(file_data))
		ft_error('m');
	if (!surrounded_by_walls(file_data->map) || !space_btw_walls(file_data->map))
		ft_error('m');
	if (!composition_checker(file_data, 0, 0))
		ft_error('m');
	map_lenght(file_data);
	map_width(file_data);
	
}
