#include "cub3d.h"
int skip_beg_spaces(char *row)
{
	int i = 0;
	while(row[i] && row[i] == ' ')
		i++;
	return (i);
}
int skip_end_spaces(char *row)
{
	int i = ft_strlen(row) - 1;
	while(i && row[i] == ' ')
		i--;
	return (i);
}
int surrounded_by_walls(char **map)
{
    int i;
	int j;
	int k;

    i = skip_beg_spaces(map[0]);
    while(map[0][i])
    {
        if (map[0][i] != '1' && map[0][i] != ' ' && map[0][i] != '\n')
            return (0);
        i++;
    }
	i = skip_beg_spaces(map[sizeof_array(map) - 1]);
	while(map[sizeof_array(map) - 1][i])
    {
        if (map[sizeof_array(map) - 1][i] != '1' && map[sizeof_array(map) - 1][i] != ' ')
            return (0);
        i++;
    }
	i = 1;
	while(map[i + 1])
	{
		j = skip_beg_spaces(map[i]);
		k = skip_end_spaces(map[i]);
		if (map[i][j] != '1' || map[i][k] != '1')
			return (0);
		i++;
	}
	return (1);
}

int check_for_top_row(char **map)
{
	int j;
	int k;

	j = skip_beg_spaces(map[0]);
	k = skip_end_spaces(map[0]);
	while(map[0][j] && j <= k)
	{
		if (map[0][j] == ' '
		&& ((map[0 + 1][j] != '1' && map[0 + 1][j] != ' ')
		|| (map[0][j - 1] != '1' && map[0][j - 1] != ' ')
		|| (map[0][j + 1] != '1' && map[0][j + 1] != ' ')))
			return (0);
		j++;
	}
	return (1);
}

int check_for_last_row(char **map)
{
	int j;
	int k;
	int i;

	i = sizeof_array(map) - 1;
	j = skip_beg_spaces(map[i]);
	k = skip_end_spaces(map[i]);
	while(map[i][j] && j <= k)
	{
		if (map[i][j] == ' '
		&& ((map[i - 1][j] != '1' && map[i - 1][j] != ' ')
		|| (map[i][j - 1] != '1' && map[i][j - 1] != ' ')
		|| (map[i][j + 1] != '1' && map[i][j + 1] != ' ')))
			return (0);
		j++;
	}
	return (1);
}


int space_btw_walls(char **map)
{
	int i;
	int j;
	int k;

	i = 1;
	if(!check_for_top_row(map)
		|| !check_for_last_row(map))
		return (0);
	while(map[i + 1])
	{
		j = skip_beg_spaces(map[i]);
		k = skip_end_spaces(map[i]);
		while(map[i][j] && j <= k)
		{
			if (map[i][j] == ' ' &&
            ((map[i - 1][j] != '1' && map[i - 1][j] != ' ') ||
            (map[i + 1][j] != '1' && map[i + 1][j] != ' ') ||
            (map[i][j - 1] != '1' && map[i][j - 1] != ' ') ||
            (map[i][j + 1] != '1' && map[i][j + 1] != ' ')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
//todo check for the map size and assign it's width and lenght

int	composition_checker(t_data *data, int i, int j)
{
	int p_counter;

	p_counter = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
					&& data->map[i][j] != ' ' && data->map[i][j] != 'N'
					&& data->map[i][j] != 'S' && data->map[i][j] != 'E'
					&& data->map[i][j] != 'W' && data->map[i][j] != '\n')
				return (0);
			if (data->map[i][j] == 'S' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
				{
					p_counter++;
					data->x_player = i;
					data->y_player = j;
					data->direction = data->map[i][j];
				}
			j++;
		}
		j = 0;
		i++;
	}
	if (p_counter != 1)
		return (0);
	return (1);
}
