#include "cub3d.h"

int		ft_isdigit_str(char *str)
{
	while(*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	free_arr(char **arr)
{
	free(*arr);
}

void	init_values(t_all *app)
{
	app->map_ptr.R_init = 0;
	app->map_ptr.F_init = 0;
	app->map_ptr.NO_init = 0;
    app->map_ptr.count_mod = 0;
}

void		print_error(int errnum)
{
	(errnum == 1) ? ft_putendl_fd("fd is not available", 1)
	: (errnum == 2) ? ft_putendl_fd("R twice init", 1)
	: (errnum == 5) ? ft_putendl_fd("C or F twice init", 1)
	: (errnum == 6) ? ft_putendl_fd("Sprite twice init", 1)
	: (errnum == 7) ? ft_putendl_fd("Not open sprite picture", 1)
	: (errnum == 8) ? ft_putendl_fd("Wrong count of array elements", 1)
	: (errnum == 9) ? ft_putendl_fd("Modificator more or less 8", 1)
    : (errnum == 3) ? ft_putendl_fd("Modificator more or less 8", 1)
    : (errnum == 4) ? ft_putendl_fd("parse error with F", 1) : 0;
	exit(0);
}

int		array_len(char **arr, int num)
{
	while(*(arr++) && *arr != '\0')
		num--;
	return (num == 0) ? (1) : (0);
}

int	press_key(int keycode, void* win_ptr)
{
	if (keycode == 53 || keycode == 12)
	{
		exit(0);
	}
	// printf("%d\n", keycode);
	return (0);
}