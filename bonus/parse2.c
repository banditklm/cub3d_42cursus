/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:12:43 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/09 12:13:24 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*extract_content(char *line)
{
	int		end;
	int		start;
	char	*content;

	end = ft_strlen(line) - 1;
	while (end >= 0 && (line[end] == ' '
			|| line[end] == '\t' || line[end] == '\n'))
		end--;
	start = 0;
	if (start >= end)
		ft_error('t');
	while (line[start] && (line[start] == ' ' || line[start] == '\t'))
		start++;
	content = c_malloc(sizeof(char) * (end - start + 2), 1);
	if (!content)
		ft_error('a');
	ft_strncpy(content, &line[start], end - start + 1);
	content[end - start + 1] = '\0';
	return (content);
}

int	manip_line2(t_data *data, char *line, int *nb)
{
	if (!ft_strncmp(line + skip_beg_spaces(line), "NO ", 3)
		|| !ft_strncmp(line + skip_beg_spaces(line), "SO ", 3)
		|| !ft_strncmp(line + skip_beg_spaces(line), "EA ", 3)
		|| !ft_strncmp(line + skip_beg_spaces(line), "WE ", 3)
		|| !ft_strncmp(line + skip_beg_spaces(line), "D ", 2)
		|| !ft_strncmp(line + skip_beg_spaces(line), "SP ", 3))
	{
		set_texture(data, line);
		(*nb)++;
		return (1);
	}
	return (0);
}

int	manip_line(t_data *data, char *line, int *nb, char **joined)
{
	if (manip_line2(data, line, nb))
		return (1);
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

void	manip_file(t_data *data, int fd, int valid_infonumber)
{
	char	*line;
	char	*joined;

	data->order.line_order = 0;
	data->end_map = 0;
	joined = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strcmp(joined, "") && !ft_strcmp(line, "\n"))
			data->end_map = 1;
		if (!ft_strcmp(line, "\n"))
			continue ;
		if (!manip_line(data, line, &valid_infonumber, &joined))
			ft_error('f');
		data->order.line_order++;
	}
	data->map = ft_split(joined, '\n');
	if (data->map[0])
		valid_infonumber++;
	if (valid_infonumber != 9 || !data->no || !data->so
		|| !data->ea || !data->we || !data->doo || !data->sp)
		ft_error('f');
}
