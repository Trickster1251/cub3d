/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 02:06:57 by walethea          #+#    #+#             */
/*   Updated: 2021/02/28 10:22:16 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	unsigned long long	res;
	int					i;
	int					minus;

	res = 0;
	minus = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') || \
	(str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f') || (str[i] == '0'))
		i++;
	if (str[i] == '-' && (minus = -1))
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	if (res > 9223372036854775807 && minus == 1)
		return (-1);
	if (res > 9223372036854775807 && minus == -1)
		return (0);
	return (res * minus);
}
