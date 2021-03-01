/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 05:00:50 by walethea          #+#    #+#             */
/*   Updated: 2021/03/02 02:30:25 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_perp_wall_dist(t_all *a)
{
	if (a->side == 0)
		a->perp_wall_dist = ((int)a->map_x - a->plr.x +
		(1 - (int)a->step_x) / 2) / a->ray_dir_x;
	else
		a->perp_wall_dist = ((int)a->map_y - a->plr.y +
		(1 - (int)a->step_y) / 2) / a->ray_dir_y;
}

void	set_ds_de(t_all *a)
{
	a->line_h = (int)(a->m.r[0] / a->perp_wall_dist) * 0.75;
	a->ds_w = -a->line_h / 2 + a->m.r[1] / 2;
	if (a->ds_w < 0)
		a->ds_w = 0;
	a->de_w = a->line_h / 2 + a->m.r[1] / 2;
	if (a->de_w >= a->m.r[1])
		a->de_w = a->m.r[1] - 1;
	if (a->side == 0)
		a->wall_x = a->plr.y + a->perp_wall_dist * a->ray_dir_y;
	else
		a->wall_x = a->plr.x + a->perp_wall_dist * a->ray_dir_x;
	a->wall_x -= floor((a->wall_x));
	what_side(a);
}

void	init_ray_values(t_all *a, int i)
{
	a->hit = 0;
	a->camera_x = 2 * i / (double)(a->m.r[0]) - 1;
	a->ray_dir_x = a->plr.dir_x + a->plr.pln_x * a->camera_x;
	a->ray_dir_y = a->plr.dir_y + a->plr.pln_y * a->camera_x;
	a->dlt_dst_x = fabs(1 / a->ray_dir_x);
	a->dlt_dst_y = fabs(1 / a->ray_dir_y);
	a->map_x = (int)(a->plr.x);
	a->map_y = (int)(a->plr.y);
}

void	drawing(t_all *a)
{
	int			i;
	double		sprite_dist[a->m.r[0]];

	i = -1;
	while (++i < a->m.r[0])
	{
		init_ray_values(a, i);
		calculate_step(a);
		is_hit(a);
		set_perp_wall_dist(a);
		sprite_dist[i] = a->perp_wall_dist;
		set_ds_de(a);
		a->tex_x = (int)(a->wall_x * (double)(a->tex.w));
		if (a->side == 0 && a->ray_dir_x > 0)
			a->tex_x = a->tex.w - a->tex_x - 1;
		if (a->side == 1 && a->ray_dir_y < 0)
			a->tex_x = a->tex.w - a->tex_x - 1;
		a->step = 1.0 * a->tex.h / a->line_h;
		a->tex_pos = (a->ds_w - a->m.r[1] / 2 + a->line_h / 2) * a->step;
		draw_wall(a, i);
	}
	cast_sprite(a, sprite_dist);
}

int		raycaster(t_all *a)
{
	release_key(a);
	if (!(a->img.img = mlx_new_image(a->mlx, a->m.r[0], a->m.r[1])))
		print_error("Something wrong with image in raycaster");
	a->img.addr = mlx_get_data_addr(a->img.img, &a->img.bpp,
	&a->img.line_len, &a->img.endian);
	drawing(a);
	if (a->srcsht == 0)
	{
		mlx_put_image_to_window(a->mlx, a->win, a->img.img, 0, 0);
		mlx_string_put(a->mlx, a->win, a->m.r[0] /
		2 - 5, a->m.r[1] / 2, 0xFFFFFF, ft_itoa(a->plr.apple));
		mlx_destroy_image(a->mlx, a->img.img);
	}
	return (0);
}
