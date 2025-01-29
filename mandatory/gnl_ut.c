#include "cub3d.h"

char	*ft_strchr(const char *string, int c )
{
	char	*str;

	str = (char *)string;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;

	res = c_malloc(size * count, 1);
	if (!res)
		return (NULL);
	ft_bzero(res, size * count);
	return (res);
}