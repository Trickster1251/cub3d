/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:11:27 by walethea          #+#    #+#             */
/*   Updated: 2020/11/14 02:44:40 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str, const char *str1, size_t n)
{
	unsigned char	*s;
	unsigned char	*s1;
	size_t			i;

	s = (unsigned char*)str;
	s1 = (unsigned char*)str1;
	i = 0;
	while (i < n && (s[i] || s1[i]))
	{
		if (s[i] != s1[i])
			return (s[i] - s1[i]);
		i++;
	}
	return (0);
}
