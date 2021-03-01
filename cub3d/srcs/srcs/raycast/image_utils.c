/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 05:00:12 by walethea          #+#    #+#             */
/*   Updated: 2021/03/02 01:16:50 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		get_color(t_img *tex, int x, int y)
{
	char	*dst;
	int		color;

	dst = tex->addr + (y * tex->line_l + x * (tex->bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	get_texture(t_all *all, int side)
{
	if (side == 0)
	{
		if (all->step_x > 0)
			all->color = get_color(&all->tex.so, all->tex_x, all->tex_y);
		else
			all->color = get_color(&all->tex.no, all->tex_x, all->tex_y);
	}
	else
	{
		if (all->step_y > 0)
			all->color = get_color(&all->tex.we, all->tex_x, all->tex_y);
		else
			all->color = get_color(&all->tex.ea, all->tex_x, all->tex_y);
	}
}

void	my_mlx_pixel_put(t_all *app, int x, int y, int color)
{
	char	*dst;

	dst = app->img.addr + (y * app->img.line_len + x * (app->img.bpp / 8));
	*(unsigned int*)dst = color;
}
