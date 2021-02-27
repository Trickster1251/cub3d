#include "cub3d.h"

int		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		ft_255_or_0(int num)
{
	if (num > 255)
		print_error("Color modificator more then 255");
	else if (num < 0)
		print_error("Color modificator less then 0");
	return (num);
}

int		is_correct_num(char **arr, int i)
{
	while(arr[++i])
		if (!(ft_isdigit_str(arr[i])))
			return (0);
	return(1);
}

int		ft_parse_r(char **arr, t_all *app)
{
	(!array_len(arr, 2)) ? print_error("More array len") : (0);
	(app->map_ptr.r_i == 1) ?
	(print_error("R twice init")) : (app->map_ptr.r_i = 1);
	if (!is_correct_num(arr, 0))
		print_error("Enter correct symbols at resolution");
	((app->map_ptr.r[0] = ft_atoi(*(arr + 1))) < 400) ? (app->map_ptr.r[0] = 400) : (0);
	((app->map_ptr.r[1] = ft_atoi(*(arr + 2))) < 400) ? (app->map_ptr.r[1] = 400) : (0);
	((app->map_ptr.r[0] > 2560)) ? (app->map_ptr.r[0] = 2560) : (0);
	((app->map_ptr.r[1] > 1440)) ? (app->map_ptr.r[1] = 1440) : (0);
	app->map_ptr.count_mod += 1;
	printf("%s %d %d\n", *arr, app->map_ptr.r[0] , app->map_ptr.r[1]);
	return (0);
}

int		ft_parse_f_c(char **arr, t_all *app)
{	
	(!array_len(arr, 3)) ? print_error("More array len") : 0;
	if (**arr == 'F')
	{
		(app->map_ptr.f_i == 1) ? (print_error("F twice init")) : (app->map_ptr.f_i = 1);
		if (!is_correct_num((arr), 0))
			print_error("Enter correct symbols at F");
    	app->map_ptr.f = create_rgb(ft_255_or_0(ft_atoi(*(arr + 1))), ft_255_or_0(ft_atoi(*(arr + 2))), ft_255_or_0(ft_atoi(*(arr + 3))));
		printf("F %d\n", app->map_ptr.f);
	}
	else
	{
		(app->map_ptr.c_i == 1) ? (print_error("C twice init")) : (app->map_ptr.c_i = 1);
		if (!is_correct_num((arr), 0))
			print_error("Enter correct symbols at C");
		app->map_ptr.c = create_rgb(ft_255_or_0(ft_atoi(*(arr + 1))), ft_255_or_0(ft_atoi(*(arr + 2))), ft_255_or_0(ft_atoi(*(arr + 3))));
		printf("C %d\n", app->map_ptr.c);
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
		!((open((app->tex.no.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong NO fd") : 0;
	}
	else if (type == 'W')
	{
		(app->map_ptr.w_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.w_i = 1);
		!((open((app->tex.we.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong WE fd") : 0;
	}
	else if (type == 'E')
	{
		(app->map_ptr.e_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.e_i = 1);
		!((open((app->tex.ea.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong EA fd") : 0;
	}
	else if (type == 'S')
	{
		(app->map_ptr.so_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.so_i = 1);
		!((open((app->tex.so.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong SO fd") : 0;
	}
	else if (type == 's')
	{
		(app->map_ptr.s_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.s_i = 1);
		!((open((app->tex.s.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong S fd") : 0;
	}
	app->map_ptr.count_mod += 1;
	printf("%s %s\n", *arr, *(arr+1));
	return (0);
}