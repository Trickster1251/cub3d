/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:54:06 by walethea          #+#    #+#             */
/*   Updated: 2020/11/14 02:48:30 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	char	*s;
	size_t	len;

	s = (char *)str;
	len = 0;
	while (*str++)
		len++;
	if (symbol == '\0')
		return (&s[len]);
	while (len--)
	{
		if (s[len] == symbol)
			return (&s[len]);
	}
	return (NULL);
}
