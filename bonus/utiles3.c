/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:16:12 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/09 15:13:33 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	map_lenght(t_data *data)
{
	int	i;

	i = 0;
	while (data->map && data->map[i])
		i++;
	data->map_lenght = i;
}

void	map_width(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map && data->map[i])
	{
		if (ft_strlen(data->map[i]) > j)
			j = ft_strlen(data->map[i]);
		i++;
	}
	data->map_width = j;
}

int	count_spaces(char *number)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (number[i])
	{
		if (number[i] == ' ' || number[i] == '\t')
		{
			counter++;
		}
		i++;
	}
	return (counter);
}

int	rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}
