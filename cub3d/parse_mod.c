/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 05:01:00 by walethea          #+#    #+#             */
/*   Updated: 2021/02/28 18:56:47 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_rgb(int r, int g, int b)
{
	(r < 0 || g < 0 || b < 0)
	? (print_error("Color modificator less then 0")) : (0);
	(r > 255 || g > 255 || b > 255)
	? (print_error("Color modificator more then 255")) : (0);
	return (r << 16 | g << 8 | b);
}

void	set_size_window(char **arr, t_all *app, int max_res, int i)
{
	if (((**(arr + i)) == '0') || (ft_strlen(*(arr + i)) <= 4))
	{
		if ((app->m.r[i - 1] = ft_atoi(*(arr + i))) < max_res)
		{
			if ((app->m.r[i - 1] < 300))
				app->m.r[i - 1] = 300;
		}
		else
			app->m.r[i - 1] = max_res;
	}
	else
		app->m.r[i - 1] = max_res;
}

int		is_correct_num(char **arr, int i)
{
	while (arr[++i])
		if (!(ft_isdigit_str(arr[i])))
			return (0);
	return (1);
}

int		ft_parse_r(char **arr, t_all *app)
{
	(!array_len(arr, 2)) ? print_error("More array len") : (0);
	(app->m.r_i == 1) ?
	(print_error("R twice init")) : (app->m.r_i = 1);
	if (!is_correct_num(arr, 0))
		print_error("Enter correct symbols at resolution");
	if (app->srcsht == 0)
	{
		
		set_size_window(arr, app, 2560, 1);
		set_size_window(arr, app, 1440, 2);
	}
	app->m.count_mod += 1;
	return (0);
}

int		ft_parse_f_c(char **arr, t_all *app)
{
	(!array_len(arr, 3)) ? print_error("More array len") : 0;
	if (**arr == 'F')
	{
		(app->m.f_i == 1)
		? (print_error("F twice init")) : (app->m.f_i = 1);
		if (!is_correct_num((arr), 0))
			print_error("Enter correct symbols at F");
		app->m.f = create_rgb(ft_atoi(*(arr + 1)),
		ft_atoi(*(arr + 2)), ft_atoi(*(arr + 3)));
		// printf("F %d\n", app->map_ptr.f);
	}
	else
	{
		(app->m.c_i == 1) ?
		(print_error("C twice init")) : (app->m.c_i = 1);
		if (!is_correct_num((arr), 0))
			print_error("Enter correct symbols at C");
		app->m.c = create_rgb(ft_atoi(*(arr + 1)),
		ft_atoi(*(arr + 2)), ft_atoi(*(arr + 3)));
		// printf("C %d\n", app->map_ptr.c);
	}
	app->m.count_mod += 1;
	return (0);
}

int		ft_parse_sprite(char **arr, t_all *app, int type)
{
	(!array_len(arr, 1)) ? print_error("More array len") : 0;
	if (type == 'N')
		parse_no_tex(app, arr);
	else if (type == 'W')
		parse_we_tex(app, arr);
	else if (type == 'E')
		parse_ea_tex(app, arr);
	else if (type == 'S')
		parse_so_tex(app, arr);
	else if (type == 's')
		parse_s_tex(app, arr);
	app->m.count_mod += 1;
	// printf("%s %s\n", *arr, *(arr+1));
	return (0);
}