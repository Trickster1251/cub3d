/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 03:16:47 by walethea          #+#    #+#             */
/*   Updated: 2021/03/05 03:22:21 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		create_rgb(int r, int g, int b)
{
	(r < 0 || g < 0 || b < 0)
	? (print_error("Wrong value color modificator")) : (0);
	(r > 255 || g > 255 || b > 255)
	? (print_error("Wrong value color modificator")) : (0);
	return (r << 16 | g << 8 | b);
}

int		valid_colon(char *str)
{
	int		i;

	i = 0;
	if (!str)
		print_error("Wrong value color modificator");
	while (*str)
	{
		if (*str == ',')
			i++;
		str++;
	}
	return ((i == 2) ? (1) : (0));
}

void	color_parser_f(char **arr, t_all *a)
{
	(a->m.f_i == 1)
	? (print_error("F twice init")) : (a->m.f_i = 1);
	if (!(valid_colon(*(arr + 1))))
		print_error("Wrong value color modificator");
	arr = ft_split(*(arr + 1), ',');
	(!array_len(arr, 2)) ? print_error("More array len") : 0;
	if (!is_correct_num((arr), -1))
		print_error("Enter correct symbols at F");
	a->m.f = create_rgb(ft_atoi(*(arr)),
	ft_atoi(*(arr + 1)), ft_atoi(*(arr + 2)));
	free_arr(arr);
}

void	color_parser_c(char **arr, t_all *a)
{
	(a->m.c_i == 1)
	? (print_error("C twice init")) : (a->m.c_i = 1);
	if (!(valid_colon(*(arr + 1))))
		print_error("Wrong value color modificator");
	arr = ft_split(*(arr + 1), ',');
	(!array_len(arr, 2)) ? print_error("More array len") : 0;
	if (!is_correct_num((arr), -1))
		print_error("Enter correct symbols at C");
	a->m.c = create_rgb(ft_atoi(*(arr)),
	ft_atoi(*(arr + 1)), ft_atoi(*(arr + 2)));
	free_arr(arr);
}
