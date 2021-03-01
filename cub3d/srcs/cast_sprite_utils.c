/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 20:02:52 by walethea          #+#    #+#             */
/*   Updated: 2021/03/01 21:25:51 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_swap(t_sprite *arr, int i, int j)
{
	t_sprite	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void	ft_qsort(t_sprite *arr, int left, int right)
{
	int			i;
	int			j;
	t_sprite	opor_elem;

	j = right;
	i = left;
	opor_elem = arr[(left + right) / 2];
	while (i <= j)
	{
		while (arr[i].dist > opor_elem.dist)
			i++;
		while (arr[j].dist < opor_elem.dist)
			j--;
		if (i <= j)
		{
			if (arr[i].dist < arr[j].dist)
				ft_swap(arr, i, j);
			i++;
			j--;
		}
	}
	if (left < j)
		ft_qsort(arr, left, j);
	if (i < right)
		ft_qsort(arr, i, right);
}

void	cast_sprite(t_all *app, double *sprite_dist)
{
	int			x;
	int			y;
	int			i;
	t_sprite	arr_sprite[app->tex.c_spr];

	y = -1;
	i = 0;
	while (app->map[++y])
	{
		x = -1;
		while (app->map[y][++x])
		{
			if (app->map[y][x] == '2')
			{
				arr_sprite[i].x = x + 0.5;
				arr_sprite[i].y = y + 0.5;
				arr_sprite[i].dist = (app->plr.x - arr_sprite[i].x) *
				(app->plr.x - arr_sprite[i].x) + (app->plr.y - arr_sprite[i].y)
				* (app->plr.y - arr_sprite[i].y);
				i++;
			}
		}
	}
	ft_qsort(arr_sprite, 0, app->tex.c_spr - 1);
	draw_sprite(app, sprite_dist, arr_sprite);
}
