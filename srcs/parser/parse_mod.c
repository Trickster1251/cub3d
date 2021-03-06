/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 05:01:00 by walethea          #+#    #+#             */
/*   Updated: 2021/03/06 03:26:18 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_size_window(char **arr, t_all *app, int max_res, int i)
{
	if (((**(arr + i)) == '0') || (ft_strlen(*(arr + i)) <= 4))
		if ((app->m.r[i - 1] = ft_atoi(*(arr + i))) < max_res)
		{
			if (app->m.r[i - 1] < 1)
				print_error("Wrong value R modificator");
		}
		else
			app->m.r[i - 1] = max_res;
	else
		app->m.r[i - 1] = max_res;
}

int		ft_parse_r(char **arr, t_all *a)
{
	(!array_len(arr, 2)) ? print_error("More array len") : (0);
	(a->m.r_i == 1) ?
	(print_error("R twice init")) : (a->m.r_i = 1);
	if (!is_correct_num(arr, 0))
		print_error("Enter correct symbols at resolution");
	mlx_get_screen_size(a->mlx, &a->max_w, &a->max_h);
	if (a->srcsht == 0)
	{
		set_size_window(arr, a, a->max_w, 1);
		set_size_window(arr, a, a->max_h, 2);
	}
	else
	{
		set_size_scrnsht(arr, a, 10000, 1);
		set_size_scrnsht(arr, a, 10000, 2);
	}
	a->m.count_mod += 1;
	return (0);
}

int		ft_parse_f_c(char **arr, t_all *a)
{
	(!array_len(arr, 1)) ? print_error("Wrong value color modificator")
	: (0);
	if (**arr == 'F')
	{
		color_parser_f(arr, a);
	}
	else
	{
		color_parser_c(arr, a);
	}
	a->m.count_mod += 1;
	return (0);
}

int		ft_parse_sprite(char **arr, t_all *app, int type)
{
	(!array_len(arr, 1)) ? print_error("Wrong value of textures/sprite") : 0;
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
	return (0);
}
