/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 22:00:16 by walethea          #+#    #+#             */
/*   Updated: 2021/03/05 19:29:38 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	is_side_0(t_all *a)
{
	if (a->step_x > 0)
	{
		a->tex.w = a->tex.so.w;
		a->tex.h = a->tex.so.h;
	}
	else
	{
		a->tex.w = a->tex.no.w;
		a->tex.h = a->tex.no.h;
	}
}

void	what_side(t_all *a)
{
	if (a->side == 0)
		is_side_0(a);
	else
	{
		if (a->step_y > 0)
		{
			a->tex.w = a->tex.we.w;
			a->tex.h = a->tex.we.h;
		}
		else
		{
			a->tex.w = a->tex.ea.w;
			a->tex.h = a->tex.ea.h;
		}
	}
}

void	is_hit(t_all *a)
{
	while (a->hit == 0)
	{
		if (a->side_dst_x < a->side_dist_y)
		{
			a->side_dst_x += a->dlt_dst_x;
			a->map_x += a->step_x;
			a->side = 0;
		}
		else
		{
			a->side_dist_y += a->dlt_dst_y;
			a->map_y += a->step_y;
			a->side = 1;
		}
		// ft_putendl_fd(&a->map[a->map_y][a->map_x], 1);
		if (a->map[a->map_y][a->map_x] == '1')
			a->hit = 1;
	}
}

void	calculate_step(t_all *a)
{
	if ((a->ray_dir_x) < 0)
	{
		a->step_x = -1;
		a->side_dst_x = (a->plr.x - a->map_x) * a->dlt_dst_x;
	}
	else
	{
		a->step_x = 1;
		a->side_dst_x = (a->map_x + 1.0 - a->plr.x) * a->dlt_dst_x;
	}
	if (a->ray_dir_y < 0)
	{
		a->step_y = -1;
		a->side_dist_y = (a->plr.y - a->map_y) * a->dlt_dst_y;
	}
	else
	{
		a->step_y = 1;
		a->side_dist_y = (a->map_y + 1.0 - a->plr.y) * a->dlt_dst_y;
	}
}

void	draw_wall(t_all *a, int i)
{
	int y;

	y = -1;
	while (++y < a->m.r[1])
	{
		if (y < a->ds_w)
			my_mlx_pixel_put(a, i, y, a->m.c);
		else if (y >= a->ds_w && y < a->de_w)
		{
			a->tex_y = (int)a->tex_pos & (a->tex.h - 1);
			a->tex_pos += a->step;
			get_texture(a, a->side);
			my_mlx_pixel_put(a, i, y, a->color);
		}
		else if (y > a->de_w && y < a->m.r[1])
			my_mlx_pixel_put(a, i, y, a->m.f);
	}
}
