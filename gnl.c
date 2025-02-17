#include "cub3d.h"

char	*ft_rest(char *save)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		return (NULL);
	}
	rest = ft_calloc((ft_strlen(save) - i + 1), sizeof(char));
	if (!rest)
	{
		ft_error('a');
	}
	i++;
	j = 0;
	while (save[i])
		rest[j++] = save[i++];
	return (rest);
}

char	*ft_line(char *save)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
	{
		ft_error('a');
	}
	i = 0;
	while (save[i] && save[i] != '\n')
		line[j++] = save[i++];
	if (save[i] && save[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_manip(int fd, char *save)
{
	char	*buffer;
	int		nb;

	if (!save)
		save = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!save || !buffer)
		ft_error('a');
	nb = 1;
	while (nb > 0)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
		{
			return (NULL);
		}
		buffer[nb] = '\0';
		save = ft_strjoin(save, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > 1024)
		return (NULL);
	save = ft_manip(fd, save);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_rest(save);
	return (line);
}