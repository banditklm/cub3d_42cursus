/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:45:32 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/07 15:55:00 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_wordcounter(const char *str, char c)
{
	int	i;
	int	nword;

	i = 0;
	nword = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
		{
			nword++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (nword);
}

static int	ft_word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**ft_fillptr(char const *in, char **out, char c, int words)
{
	int		i;
	int		wlen;
	int		j;

	i = 0;
	wlen = 0;
	while (i < words)
	{
		while (*in == c)
			in++;
		wlen = ft_word_len(in, c);
		out[i] = c_malloc((wlen * sizeof(char)) + 1, 1);
		if (!out[i])
			ft_error('a');
		j = 0;
		while (j < wlen)
			out[i][j++] = *in++;
		out[i][j] = '\0';
		i++;
	}
	out[i] = NULL;
	return (out);
}

char	**ft_split(char *s, char c)
{
	int		words;
	char	**ptr;

	if (!s)
		return (NULL);
	words = ft_wordcounter(s, c);
	ptr = c_malloc((words + 1) * sizeof(char *), 1);
	if (!(ptr))
		ft_error('a');
	ptr = ft_fillptr(s, ptr, c, words);
	return (ptr);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
