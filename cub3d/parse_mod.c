#include "cub3d.h"

int		ft_parse_R(char **arr, t_all *app)
{
	if (app->map_ptr.R_init == 1)
		print_error(2);
	else
		app->map_ptr.R_init = 1;
	app->map_ptr.R[0] = ft_atoi(*(arr + 1));
	app->map_ptr.R[1] = ft_atoi(*(arr + 2));
	(app->map_ptr.R[0] < 200) ? app->map_ptr.R[0] = 400 : 0;
	(app->map_ptr.R[1] < 200) ? app->map_ptr.R[1] = 400 : 0;
	app->map_ptr.count_mod += 1;
	// printf("%s %s %s", *arr, *(arr+1), *(arr+2));
	return (0);
}