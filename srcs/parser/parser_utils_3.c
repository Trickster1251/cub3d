/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:17:26 by walethea          #+#    #+#             */
/*   Updated: 2021/03/05 03:22:15 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_modificator(char mod)
{
	if (!(mod == 'N' || mod == 'F' || mod == 'R' ||
	mod == 'W' || mod == 'S' || mod == 'C' || mod == 'E'))
		print_error("modificator wrong or spaces begining line");
	return (1);
}

int		ft_isdigit_str(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

char	**free_arr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	print_error(char *string)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(string, 1);
	exit(0);
}

int		array_len(char **arr, int num)
{
	while (*(arr++) && *arr != '\0')
		num--;
	return (num == 0) ? (1) : (0);
}
