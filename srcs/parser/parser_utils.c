/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:31:30 by walethea          #+#    #+#             */
/*   Updated: 2021/03/01 22:57:40 by walethea         ###   ########.fr       */
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
