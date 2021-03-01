/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:06:03 by walethea          #+#    #+#             */
/*   Updated: 2020/11/14 02:33:18 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	if (!n || (dst == src))
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((char*)dst);
}
