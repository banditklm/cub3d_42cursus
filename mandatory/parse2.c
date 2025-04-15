/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:26:15 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/10 15:57:42 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*extract_content(char *line)
{
	int		end;
	int		start;
	char	*content;

	end = ft_strlen(line) - 1;
	while (end >= 0 && (line[end] == ' ' || line[end] == '\t'
			|| line[end] == '\n'))
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

int	handle_directives(t_data *data, char *line, int *nb)
{
	char	*trimmed_line;

	trimmed_line = line + skip_beg_spaces(line);
	if (!ft_strncmp(trimmed_line, "NO ", 3)
		|| !ft_strncmp(trimmed_line, "SO ", 3)
		|| !ft_strncmp(trimmed_line, "EA ", 3)
		|| !ft_strncmp(trimmed_line, "WE ", 3))
	{
		set_texture(data, line);
		(*nb)++;
		return (1);
	}
	else if (!ft_strncmp(trimmed_line, "F ", 2)
		|| !ft_strncmp(trimmed_line, "C ", 2))
	{
		set_colors(data, line, 0);
		(*nb)++;
		return (1);
	}
	return (0);
}

int	handle_map_lines(t_data *data, char *line, char **joined)
{
	char	*trimmed_line;

	trimmed_line = line + skip_beg_spaces(line);
	if (!ft_strncmp(trimmed_line, "1", 1) || !ft_strncmp(trimmed_line, "0", 1))
	{
		if (data->end_map)
			return (0);
		data->order.map_line = data->order.line_order;
		*joined = ft_strjoin(*joined, line);
		return (1);
	}
	else
	{
		return (isonly_spaces(line));
	}
}

int	manip_line(t_data *data, char *line, int *nb, char **joined)
{
	if (handle_directives(data, line, nb))
		return (1);
	return (handle_map_lines(data, line, joined));
}

void	manip_file(t_data *file_data, int fd, int valid_infonumber)
{
	char	*line;
	char	*joined;

	file_data->order.line_order = 0;
	file_data->end_map = 0;
	joined = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strcmp(joined, "") && !ft_strcmp(line, "\n"))
			file_data->end_map = 1;
		if (!ft_strcmp(line, "\n"))
			continue ;
		if (!manip_line(file_data, line, &valid_infonumber, &joined))
			ft_error('f');
		file_data->order.line_order++;
	}
	file_data->map = ft_split(joined, '\n');
	if (file_data->map[0])
		valid_infonumber++;
	if (valid_infonumber != 7 || !file_data->no || !file_data->so
		|| !file_data->ea || !file_data->we)
		ft_error('f');
}
