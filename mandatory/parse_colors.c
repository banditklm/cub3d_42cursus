#include "cub3d.h"

int check_content(char *colors)
{
	int i;

	i = 0;
	while(colors && colors[i])
	{
		if (colors[i] != ' ' && colors[i] != '\n' && colors[i] != '\t' && colors[i] != ',' && !ft_isdigit(colors[i]))
			return (0);
		i++;
	}
	return (1);
}

void set_colors(t_data *data, char *line)
{
	char *colors;
    char **splited;
    int *color_array;
	int i;

	i = 0;
    while (*line == ' ' || *line == '\t')
        line++;
    if (ft_strncmp(line, "F ", 2) == 0)
	{
        color_array = data->floor_color;
		data->order.F_line = data->order.line_order;
	}
    else if (ft_strncmp(line, "C ", 2) == 0)
	{
        color_array = data->ceiling_color;
		data->order.C_line = data->order.line_order;
	}
    colors = extract_content(line + 1);
    if (!check_content(colors))
        ft_error('c');
    splited = ft_split(colors, ',');
    if (!splited || sizeof_array(splited) != 3)
	{
        ft_error('c');
	}
	while (i < 3)
    {
        color_array[i] = atoi(splited[i]);
        if (color_array[i] < 0 || color_array[i] > 255)
		{
        	ft_error('c');
		}
		i++;
    }
}
