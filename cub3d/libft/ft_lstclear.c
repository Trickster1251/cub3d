/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:42:39 by walethea          #+#    #+#             */
/*   Updated: 2020/11/23 23:53:58 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*prt;

	tmp = *lst;
	if (!lst || !(*del))
		return ;
	while (tmp != NULL)
	{
		prt = tmp->next;
		del(tmp);
		tmp = prt;
	}
	*lst = NULL;
}
