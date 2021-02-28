/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:31:30 by walethea          #+#    #+#             */
/*   Updated: 2021/02/28 21:40:24 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_correct_num(char **arr, int i)
{
	while (arr[++i])
		if (!(ft_isdigit_str(arr[i])))
			return (0);
	return (1);
}

int		only_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int		is_valid_sym(char str)
{
	if (str == '1' || str == '0' || str == 'N' ||
	str == 'S' || str == 'E' || str == 'W' || str == '2')
		return (1);
	return (0);
}

int		is_valid_space(char str)
{
	if (str == '1' || str == '0' || str == 'N' || str == ' ' ||
	str == 'S' || str == 'E' || str == 'W' || str == '2')
		return (1);
	return (0);
}

int		skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int		ft_is_modificator(char **arr, t_all *app)
{
	(app->m.count_mod >= 8) ? print_error("More modificators") : 0;
	if ((ft_strncmp(*arr, "R\0", 2)) == 0)
		ft_parse_r(arr, app);
	else if ((ft_strncmp(*arr, "F\0", 2) == 0) ||
	(ft_strncmp(*arr, "C\0", 2)) == 0)
		ft_parse_f_c(arr, app);
	else if (ft_strncmp(*arr, "NO\0", 3) == 0)
		ft_parse_sprite(arr, app, 'N');
	else if (ft_strncmp(*arr, "WE\0", 3) == 0)
		ft_parse_sprite(arr, app, 'W');
	else if (ft_strncmp(*arr, "EA\0", 3) == 0)
		ft_parse_sprite(arr, app, 'E');
	else if (ft_strncmp(*arr, "SO\0", 3) == 0)
		ft_parse_sprite(arr, app, 'S');
	else if (ft_strncmp(*arr, "S\0", 2) == 0)
		ft_parse_sprite(arr, app, 's');
	else
		print_error("No modificator type, enter correct data");
	return (0);
}
