/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:28:09 by walethea          #+#    #+#             */
/*   Updated: 2020/11/20 20:17:55 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		i;
	char		*cat_s;

	i = 0;
	if (!(s1 && s2))
		return (NULL);
	if (!(cat_s = (char*)malloc(sizeof(char) *
		(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		cat_s[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		cat_s[i] = *s2++;
		i++;
	}
	cat_s[i] = '\0';
	return (cat_s);
}
