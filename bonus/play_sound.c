/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_sound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:26:06 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/10 11:30:17 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	play_s1(char *path)
{
	char	**args;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args = ft_split(path, ' ');
		execv("/usr/bin/afplay", args);
	}
}

void	play_s2(t_data *data)
{
	if (data->is_play == true)
	{
		play_s1("afplay bonus/hamas.m4a");
		data->is_play = false;
	}
}
