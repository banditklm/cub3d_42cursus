#include "cub.h"

void ft_error(char type)
{
	if (type == 'f')
		ft_putstr_fd("Error\nError in file structure\n", 2);
	else if (type == 'm')
		ft_putstr_fd("Error\nError in map\n", 2);
	else if (type == 'a')
		ft_putstr_fd("Error\nError in allocation\n", 2);
	else if (type == 'c')
		ft_putstr_fd("Error\nError in colors\n", 2);
	else if (type == 't')
		ft_putstr_fd("Error\nError in textures\n", 2);
	else if (type == 'o')
		ft_putstr_fd("Error\nError opening the file\n", 2);
	if (type != 'o')
		c_malloc(0, 0);
	exit(1);
}

int	open_cub_file(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_error('o');
	}
	return (fd);
}

void check_file_ext(char *str)
{
	while (*str)
	{
		if (*str == '.' && ft_strcmp(str, ".cub") == 0)
			return ;
		str++;
	}
	ft_putstr_fd("Error\nInvalid .cub extension\n", 2);
	exit(1);
}

int	main(int ac, char **av)
{

	t_data file_data;
	if (ac != 2)
	{
		printf("Error\nyou need 1 file , .cub file\n");
		return (1);
	}
	check_file_ext(av[1]);
	parse(&file_data, av[1]);

}