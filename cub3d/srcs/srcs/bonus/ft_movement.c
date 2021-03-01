/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:18:26 by walethea          #+#    #+#             */
/*   Updated: 2021/03/02 02:31:39 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	forward(t_all *a, double rtd_spd)
{
	if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.pln_y * MS)] != '1')
	{
		if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.pln_y * MS)] == '2')
		{
			a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.pln_y * MS)] = '0';
			a->plr.apple++;
		}
		a->plr.x += a->plr.pln_y * rtd_spd;
	}
	if (a->map[(int)(a->plr.y - a->plr.pln_x * MS)][(int)a->plr.x] != '1')
	{
		if (a->map[(int)(a->plr.y - a->plr.pln_x * MS)][(int)a->plr.x] == '2')
		{
			a->map[(int)(a->plr.y - a->plr.pln_x * MS)][(int)a->plr.x] = '0';
			a->plr.apple++;
		}
		a->plr.y -= a->plr.pln_x * rtd_spd;
	}
}

void	backward(t_all *a, double rtd_spd)
{
	if (a->map[(int)a->plr.y][(int)(a->plr.x - a->plr.pln_y * rtd_spd)] != '1')
	{
		if (a->map[(int)a->plr.y]
		[(int)(a->plr.x - a->plr.pln_y * rtd_spd)] == '2')
		{
			a->map[(int)a->plr.y]
			[(int)(a->plr.x - a->plr.pln_y * rtd_spd)] = '0';
			a->plr.apple++;
		}
		a->plr.x -= a->plr.pln_y * rtd_spd;
	}
	if (a->map[(int)(a->plr.y + a->plr.pln_x * rtd_spd)][(int)a->plr.x] != '1')
	{
		if (a->map[(int)(a->plr.y + a->plr.pln_x * rtd_spd)]
		[(int)a->plr.x] == '2')
		{
			a->map[(int)(a->plr.y + a->plr.pln_x * rtd_spd)]
			[(int)a->plr.x] = '0';
			a->plr.apple++;
		}
		a->plr.y += a->plr.pln_x * rtd_spd;
	}
}

void	rotate(t_all *a, double rtd_spd)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = a->plr.dir_x;
	old_plane_x = a->plr.pln_x;
	a->plr.dir_x = a->plr.dir_x * cos(rtd_spd) - a->plr.dir_y * sin(rtd_spd);
	a->plr.dir_y = old_dir_x * sin(rtd_spd) + a->plr.dir_y * cos(rtd_spd);
	a->plr.pln_x = a->plr.pln_x * cos(rtd_spd) - a->plr.pln_y * sin(rtd_spd);
	a->plr.pln_y = old_plane_x * sin(rtd_spd) + a->plr.pln_y * cos(rtd_spd);
}

int		release_key(t_all *a)
{
	if (a->key.s == 1)
		backward(a, MS);
	if (a->key.w == 1)
		forward(a, MS);
	if (a->key.a == 1)
	{
		if (a->map[(int)a->plr.y][(int)(a->plr.x - a->plr.pln_x * MS)] != '1')
			a->plr.x -= a->plr.pln_x * MS;
		if (a->map[(int)(a->plr.y - a->plr.pln_y * MS)][(int)a->plr.x] != '1')
			a->plr.y -= a->plr.pln_y * MS;
	}
	if (a->key.d == 1)
	{
		if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.pln_x * MS)] != '1')
			a->plr.x += a->plr.pln_x * MS;
		if (a->map[(int)(a->plr.y + a->plr.pln_y * MS)][(int)a->plr.x] != '1')
			a->plr.y += a->plr.pln_y * MS;
	}
	if (a->key.q == 1)
		rotate(a, -MS);
	if (a->key.e == 1)
		rotate(a, MS);
	return (0);
}

void	ft_is_plr(t_all *app, char dir, int i, int j)
{
	(app->plr_init == 1) ?
	(print_error("The player already exists")) : (app->plr_init = 1);
	app->plr.x = j + 0.5;
	app->plr.y = i + 0.5;
	if (dir == 'S')
	{
		app->plr.dir_y = 1;
		app->plr.pln_x = -0.66;
	}
	else if (dir == 'E')
	{
		app->plr.dir_x = 1;
		app->plr.pln_y = 0.66;
	}
	else if (dir == 'N')
	{
		app->plr.dir_y = -1;
		app->plr.pln_x = 0.66;
	}
	else if (dir == 'W')
	{
		app->plr.dir_x = -1;
		app->plr.pln_y = -0.66;
	}
}
