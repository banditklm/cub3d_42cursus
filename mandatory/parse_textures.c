#include "cub3d.h"

void set_texture(t_data *data, char *line)
{
    while (*line == ' ' || *line == '\t')
        line++;

    if (ft_strncmp(line, "NO ", 3) == 0)
    {
        data->NO = extract_content(line + 2);
        data->order.NO_line = data->order.line_order;
    }
    else if (ft_strncmp(line, "SO ", 3) == 0)
    {
        data->SO = extract_content(line + 2);
        data->order.SO_line = data->order.line_order;
    }
    else if (ft_strncmp(line, "EA ", 3) == 0)
    {
        data->EA = extract_content(line + 2);
        data->order.EA_line = data->order.line_order;
    }
    else if (ft_strncmp(line, "WE ", 3) == 0)
    {
        data->WE = extract_content(line + 2);
        data->order.WE_line = data->order.line_order;
    }
}

