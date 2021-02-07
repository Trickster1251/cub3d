/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:04:41 by walethea          #+#    #+#             */
/*   Updated: 2020/11/14 02:24:06 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *buff;

	buff = (void*)malloc(count * size);
	if (!buff)
		return (NULL);
	ft_bzero(buff, count * size);
	return (buff);
}
