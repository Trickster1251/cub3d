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

void		print_error(char *string)
{
	ft_putendl_fd(string, 1);
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