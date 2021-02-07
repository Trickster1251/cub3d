/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:05:14 by walethea          #+#    #+#             */
/*   Updated: 2020/11/14 02:32:22 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str, const void *str1, size_t n)
{
	unsigned char	*s;
	unsigned char	*s1;
	size_t			i;

	s = (unsigned char*)str;
	s1 = (unsigned char*)str1;
	i = 0;
	while (i < n)
	{
		if (s[i] != s1[i])
			return (s[i] - s1[i]);
		i++;
	}
	return (0);
}
