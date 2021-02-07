/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:14:05 by walethea          #+#    #+#             */
/*   Updated: 2020/11/20 20:15:37 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int symbol)
{
	char		*s;
	int			i;

	s = (char *)str;
	i = 0;
	while (s[i])
	{
		if (s[i] == symbol)
			return (&s[i]);
		i++;
	}
	if (symbol == '\0')
		return (&s[i]);
	return (NULL);
}
