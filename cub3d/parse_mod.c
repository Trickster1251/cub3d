#include "cub3d.h"

int		create_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

int     ft_255_or_0(int num)
{
    if (num > 255)
        return (255);
    else if (num < 0)
        return (0);
    return (num);
}

int		ft_parse_R(char **arr, t_all *app)
{
	(!array_len(arr, 2)) ? print_error("More array len") : 0;
	(app->map_ptr.R_init == 1) ? (print_error("R twice init")) : (app->map_ptr.R_init = 1);
	((app->map_ptr.R[0] = ft_atoi(*(arr + 1))) < 400) ? (app->map_ptr.R[0] = 400) : (0);
	((app->map_ptr.R[1] = ft_atoi(*(arr + 2))) < 400) ? (app->map_ptr.R[1] = 400) : (0);
	(app->map_ptr.R[0] > 2560) ? (app->map_ptr.R[0] = 2560) : (0);
	(app->map_ptr.R[1] > 1920) ? (app->map_ptr.R[1] = 1920) : (0);
	app->map_ptr.count_mod += 1;
	printf("%s %d %d", *arr, app->map_ptr.R[0] , app->map_ptr.R[1]);
	return (0);
}

int		ft_parse_F_C(char **arr, t_all *app)
{	
	(!array_len(arr, 1)) ? print_error("More array len") : 0;
	if (**arr == 'F')
	{
		(app->map_ptr.F_init == 1) ? (print_error("F twice init")) : (app->map_ptr.F_init = 1);
    	arr = ft_split(*(arr+1), ',');
		if (!ft_isdigit_str(*arr) && !ft_isdigit_str(*(arr+1)) && !ft_isdigit_str(*(arr+2)))
			print_error("F modificator with space on argumetns\n");
    	app->map_ptr.F = create_rgb(ft_255_or_0(ft_atoi(*arr)), ft_255_or_0(ft_atoi(*(arr+1))),ft_255_or_0(ft_atoi(*(arr+2))));
		printf("\n%d\n", app->map_ptr.F);
	}
	else
	{
		(app->map_ptr.C_init == 1) ? (print_error("C twice init")) : (app->map_ptr.C_init = 1);
    	arr = ft_split(*(arr+1), ',');
		if (!ft_isdigit_str(*arr) && !ft_isdigit_str(*(arr+1)) && !ft_isdigit_str(*(arr+2)))
			print_error("C modificator with space on arguments");
    	app->map_ptr.C = create_rgb(ft_255_or_0(ft_atoi(*arr)), ft_255_or_0(ft_atoi(*(arr+1))),ft_255_or_0(ft_atoi(*(arr+2))));
		printf("\n%d\n", app->map_ptr.C);
	}
	app->map_ptr.count_mod += 1;
	return (0);
}

int		ft_parse_sprite(char **arr, t_all *app, int type)
{
	(!array_len(arr, 1)) ? print_error("More array len") : 0;
	if (type == 'N')
		(app->map_ptr.NO_init == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.NO_init = 1);
		!((open((app->map_ptr.NO = *(arr + 1)), O_RDONLY)) > 0) ? print_error("Wrong fd") : 0;
	if (type == 'W')
		(app->map_ptr.WE_init == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.WE_init = 1);
		!((open((app->map_ptr.WE = *(arr + 1)), O_RDONLY)) > 0) ? print_error("Wrong fd") : 0;
	if (type == 'E')
		(app->map_ptr.EA_init == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.EA_init = 1);
		!((open((app->map_ptr.EA = *(arr + 1)), O_RDONLY)) > 0) ? print_error("Wrong fd") : 0;
	if (type == 'S')
		(app->map_ptr.S_init == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.S_init = 1);
		!((open((app->map_ptr.S = *(arr + 1)), O_RDONLY)) > 0) ? print_error("Wrong fd") : 0;
	app->map_ptr.count_mod += 1;
	free_arr(arr);
	printf("%s %s\n", *arr, *(arr+1));
	return (0);
}