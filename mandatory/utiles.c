#include "cub.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = c_malloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		size;
	char	*ptr;

	i = 0;
	size = ft_strlen(s);
	ptr = c_malloc(size + 1, 1);
	if (!ptr)
		return (0);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}
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

int	isonly_spaces(char *input)
{
	int	i;

	i = 0;
	while (input && input[i])
	{
		while ((input[i] >= 9 && input[i] <= 13) || input[i] == ' ' )
			i++;
		if (input[i])
			return (0);
	}
	return (1);
}

int sizeof_array(char **str)
{
	int i;

	i = 0;
	while(str && str[i])
		i++;
	return (i);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
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