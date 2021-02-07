/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:17:14 by walethea          #+#    #+#             */
/*   Updated: 2020/11/20 20:45:44 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*start_more_len(unsigned char *sub_s)
{
	sub_s = (unsigned char*)malloc(sizeof(unsigned char) * 1);
	if (!sub_s)
		return (NULL);
	*sub_s = '\0';
	return ((char*)sub_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			l;
	unsigned char	*sub_s;

	i = 0;
	l = 0;
	sub_s = NULL;
	if (!s)
		return (NULL);
	while (s[start + l] != '\0')
		l++;
	if (l < len)
		len = l;
	if (start >= len)
		return (start_more_len(sub_s));
	sub_s = (unsigned char*)malloc(sizeof(unsigned char) * (len + 1));
	if (!sub_s)
		return (NULL);
	while (s[start + i] && len--)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return ((char*)&sub_s[0]);
}
