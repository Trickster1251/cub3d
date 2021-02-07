/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:59:44 by walethea          #+#    #+#             */
/*   Updated: 2020/11/23 22:34:48 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		mod;
	int		dif;
	int		chr;

	mod = 0;
	dif = 0;
	chr = 48;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	mod = n % 10;
	dif = n / 10;
	if (dif != 0)
		ft_putnbr_fd(dif, fd);
	chr += mod;
	write(fd, &chr, 1);
}
