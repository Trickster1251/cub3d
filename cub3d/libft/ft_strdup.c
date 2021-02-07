/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:56:52 by walethea          #+#    #+#             */
/*   Updated: 2020/11/20 20:14:33 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int			i;
	int			len;
	char		*str;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (src && (i < len))
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
