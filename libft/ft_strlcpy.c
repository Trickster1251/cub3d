/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:40:56 by walethea          #+#    #+#             */
/*   Updated: 2020/11/21 13:49:15 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*d;
	size_t	i;

	d = (char *)dst;
	i = 0;
	if (!d || !src)
		return (0);
	else if (size != 0)
	{
		while (src[i] && (i < (size - 1)))
		{
			d[i] = src[i];
			i++;
		}
		d[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
