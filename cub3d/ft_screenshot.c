/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:25:59 by walethea          #+#    #+#             */
/*   Updated: 2021/02/28 21:48:57 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_size_scrnsht(char **arr, t_all *app, int max_res, int i)
{
	if (((**(arr + i)) == '0') || (ft_strlen(*(arr + i)) <= 5))
	{
		if ((app->m.r[i - 1] = ft_atoi(*(arr + i))) > max_res)
			app->m.r[i - 1] = max_res;
	}
	else
		app->m.r[i - 1] = max_res;
}

void	write_while(int fd, unsigned int i)
{
	write(fd, &i, 4);
	write(fd, &i, 4);
	write(fd, &i, 4);
	write(fd, &i, 4);
	write(fd, &i, 4);
}

void	image_to_sreenshot(t_all *all, int fd)
{
	int y;

	y = all->m.r[1];
	while (y >= 0)
	{
		y--;
		write(fd, all->img.line_len * y + all->img.addr, all->img.line_len);
	}
	exit(0);
}

void	render_bmp(t_all *all)
{
	int fd;
	unsigned int	n;
	unsigned int	i;
	short			b;

	if ((fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666)) < 0)
		print_error("Fail with creating screenshot file");
	n = all->img.line_len * (all->m.r[1]) + 54;
	write(fd, "BM", 2);
	write(fd, &n, 4);
	i = 0;
	write(fd, &i, 4);
	i = 54;
	write(fd, &i, 4);
	i = 40;
	write(fd, &i, 4);
	write(fd, &all->m.r[0], 4);
	write(fd, &all->m.r[1], 4);
	b = 1;
	write(fd, &b, 2);
	b = all->img.bpp;
	write(fd, &b, 2);
	i = 0;
	write(fd, &i, 4);
	write(fd, &i, 4);
	write(fd, &i, 4);
	write(fd, &i, 4);
	write(fd, &i, 4);
	image_to_sreenshot(all, fd);
}
