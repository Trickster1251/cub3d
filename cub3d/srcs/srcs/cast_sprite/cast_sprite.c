/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 05:00:08 by walethea          #+#    #+#             */
/*   Updated: 2021/03/02 01:15:33 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_var_sprite(t_all *a, t_sprite *ar)
{
	a->ds.spr_x = ar[a->ds.i].x - a->plr.x;
	a->ds.spr_y = ar[a->ds.i].y - a->plr.y;
	a->ds.inv_det = 1.0 /
	(a->plr.pln_x * a->plr.dir_y - a->plr.dir_x * a->plr.pln_y);
	a->ds.trn_x = a->ds.inv_det *
	(a->plr.dir_y * a->ds.spr_x - a->plr.dir_x * a->ds.spr_y);
	a->ds.trn_y = a->ds.inv_det *
	(-a->plr.pln_y * a->ds.spr_x + a->plr.pln_x * a->ds.spr_y);
	a->ds.spr_scrn_x = (int)((a->m.r[0] / 2) *
	(1 + a->ds.trn_x / a->ds.trn_y));
	a->ds.spr_h = fabs((int)(a->m.r[0] / (a->ds.trn_y)) * 0.75);
	a->ds.dr_srt_y = -a->ds.spr_h / 2 + a->m.r[1] / 2;
	if (a->ds.dr_srt_y < 0)
		a->ds.dr_srt_y = 0;
	a->ds.dr_end_y = a->ds.spr_h / 2 + a->m.r[1] / 2;
	if (a->ds.dr_end_y >= a->m.r[1])
		a->ds.dr_end_y = a->m.r[1] - 1;
	a->ds.spr_w = fabs((int)(a->m.r[0] / (a->ds.trn_y)) * 0.75);
	a->ds.dr_srt_x = -a->ds.spr_w / 2 + a->ds.spr_scrn_x;
	if (a->ds.dr_srt_x < 0)
		a->ds.dr_srt_x = 0;
	a->ds.dr_end_x = a->ds.spr_w / 2 + a->ds.spr_scrn_x;
	if (a->ds.dr_end_x >= a->m.r[0])
		a->ds.dr_end_x = a->m.r[0] - 1;
	a->ds.stripe = a->ds.dr_srt_x;
}

void		draw_sprite(t_all *a, double *s_dist, t_sprite *ar)
{
	int		d;

	a->ds.i = -1;
	while (++a->ds.i <= a->tex.c_spr)
	{
		init_var_sprite(a, ar);
		while ((a->ds.stripe < a->ds.dr_end_x))
		{
			a->ds.y = (a->ds.dr_srt_y - 1);
			a->ds.tx_x = (int)(256 * (a->ds.stripe - (-a->ds.spr_w /
			2 + a->ds.spr_scrn_x)) * a->tex.s.w / a->ds.spr_w) / 256;
			if (a->ds.trn_y > 0 && a->ds.stripe > 0 &&
			a->ds.stripe < a->m.r[0] &&
			a->ds.trn_y < s_dist[a->ds.stripe])
				while (++a->ds.y < a->ds.dr_end_y)
				{
					d = (a->ds.y) * 256 - a->m.r[1] * 128 + a->ds.spr_h * 128;
					a->ds.tx_y = ((d * a->tex.s.h) / a->ds.spr_h) / 256;
					a->ds.color = get_color(&a->tex.s, a->ds.tx_x, a->ds.tx_y);
					if ((a->ds.color & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(a, a->ds.stripe, a->ds.y, a->ds.color);
				}
			a->ds.stripe++;
		}
	}
}
