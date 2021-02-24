#include "cub3d.h"

int		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		ft_255_or_0(int num)
{
	if (num > 255)
		print_error("color is error");
	else if (num < 0)
		print_error("color is error");
	return (num);
}

int		ft_parse_r(char **arr, t_all *app)
{
	(!array_len(arr, 2)) ? print_error("More array len") : (0);
	(app->map_ptr.r_i == 1) ?
	(print_error("R twice init")) : (app->map_ptr.r_i = 1);
	((app->map_ptr.r[0] = ft_atoi(*(arr + 1))) < 400) ? (app->map_ptr.r[0] = 400) : (0);
	((app->map_ptr.r[1] = ft_atoi(*(arr + 2))) < 400) ? (app->map_ptr.r[1] = 400) : (0);
	(ft_strlen(*(arr + 1)) > 4 || (app->map_ptr.r[0] > 2560)) ? (app->map_ptr.r[0] = 2560) : (0);
	(ft_strlen(*(arr + 2)) > 4 || (app->map_ptr.r[1] > 1920)) ? (app->map_ptr.r[1] = 1920) : (0);
	app->map_ptr.count_mod += 1;
	printf("%s %d %d", *arr, app->map_ptr.r[0] , app->map_ptr.r[1]);
	return (0);
}

int		ft_parse_f_c(char **arr, t_all *app)
{	
	(!array_len(arr, 1)) ? print_error("More array len") : 0;
	if (**arr == 'F')
	{
		(app->map_ptr.f_i == 1) ? (print_error("F twice init")) : (app->map_ptr.f_i = 1);
    	arr = ft_split(*(arr+1), ',');
		if (!ft_isdigit_str(*arr) && !ft_isdigit_str(*(arr+1)) && !ft_isdigit_str(*(arr+2)))
			print_error("F modificator with space on argumetns\n");
    	app->map_ptr.f = create_rgb(ft_255_or_0(ft_atoi(*arr)), ft_255_or_0(ft_atoi(*(arr+1))),ft_255_or_0(ft_atoi(*(arr+2))));
		printf("\n%d\n", app->map_ptr.f);
	}
	else
	{
		(app->map_ptr.c_i == 1) ? (print_error("C twice init")) : (app->map_ptr.c_i = 1);
    	arr = ft_split(*(arr+1), ',');
		if (!ft_isdigit_str(*arr) && !ft_isdigit_str(*(arr+1)) && !ft_isdigit_str(*(arr+2)))
			print_error("C modificator with space on arguments");
    	app->map_ptr.c = create_rgb(ft_255_or_0(ft_atoi(*arr)), ft_255_or_0(ft_atoi(*(arr+1))),ft_255_or_0(ft_atoi(*(arr+2))));
		printf("%d\n", app->map_ptr.c);
	}
	app->map_ptr.count_mod += 1;
	return (0);
}

int		ft_parse_sprite(char **arr, t_all *app, int type)
{
	(!array_len(arr, 1)) ? print_error("More array len") : 0;
	if (type == 'N')
	{
		(app->map_ptr.n_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.n_i = 1);
		!((open((app->tex.no.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong fd") : 0;
	}
	else if (type == 'W')
	{
		(app->map_ptr.w_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.w_i = 1);
		!((open((app->tex.we.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong fd") : 0;
	}
	else if (type == 'E')
	{
		(app->map_ptr.e_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.e_i = 1);
		!((open((app->tex.ea.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong fd") : 0;
	}
	else if (type == 'S')
	{
		(app->map_ptr.so_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.so_i = 1);
		!((open((app->tex.so.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong fd") : 0;
	}
	else if (type == 's')
	{
		(app->map_ptr.s_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.s_i = 1);
		!((open((app->tex.s.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong fd") : 0;
	}
	app->map_ptr.count_mod += 1;
	printf("%s %s\n", *arr, *(arr+1));
	return (0);
}