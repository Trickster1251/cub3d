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
	app->map_ptr.WE_init = 0;
	app->map_ptr.EA_init = 0;
	app->map_ptr.S_init = 0;
	app->map_ptr.SO_init = 0;
    app->map_ptr.count_mod = 0;
	// point->x = 0;
	// point->y = 0;
	app->plr.x = 4;
	app->plr.y = 4;
	app->plr.dir_x = -1;
	app->plr.dir_y = 0;
	app->plr.plane_x = 0;
	app->plr.plane_y = 0.66;
	app->side_dist_x = 0;
	app->side_dist_y = 0;
	app->delta_dist_x = 0;
	app->delta_dist_y = 0;
	app->perp_wall_dist = 0;
	app->step_x = 0;
	app->step_y = 0;
	app->hit = 0;
	app->side = 0;
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
	if (keycode == 53)
		exit(0);
	// printf("%d\n", keycode);
	return (0);
}