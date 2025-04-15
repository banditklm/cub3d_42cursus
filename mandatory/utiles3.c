/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:52:29 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/09 15:13:33 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_space(char c)
{
	if (!c || c == 32 || c == 9)
		return (1);
	return (0);
}

static int	ft_is_space(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (ft_is_space(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (result > 922337203685477580
			|| (result == 922337203685477580 && *str - '0' > 7))
			return (-1 * (sign == 1));
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result * sign);
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
