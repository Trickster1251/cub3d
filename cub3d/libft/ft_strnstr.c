/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:27:59 by walethea          #+#    #+#             */
/*   Updated: 2020/11/23 21:40:07 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find_str, size_t len)
{
	size_t	i;
	size_t	pos;

	pos = 0;
	if (!(*find_str))
		return ((char*)src);
	if (len == 0)
		return (0);
	while (src[pos] && pos < len)
	{
		i = 0;
		while (src[pos + i] == find_str[i] && find_str[i] && (pos + i) < len)
			i++;
		if (find_str[i] == '\0')
			return ((char*)&src[pos]);
		pos++;
	}
	return (NULL);
}
