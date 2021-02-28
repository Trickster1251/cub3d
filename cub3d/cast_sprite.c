/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 05:00:08 by walethea          #+#    #+#             */
/*   Updated: 2021/02/28 05:00:08 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_qsort (t_sprite	*arr, int left, int right)
{
    int i = left;
	int j = right;
    t_sprite	temp;
	t_sprite	pivot = arr[ (left+right)/2 ];

    while (i <= j)
    {
        while (arr[i].dist > pivot.dist) i++;
        while (arr[j].dist < pivot.dist) j--;

        if (i <= j)
        {
            if (arr[i].dist < arr[j].dist)
            {
                temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
            }

            i++; j--;
        }

    };

    if (left < j) ft_qsort (arr, left, j);
    if (i < right) ft_qsort (arr, i, right);
}

void        print_sprite(t_all *app, double *sprite_dist, t_sprite *arr_sprite)
{
    int     i;

    i = -1;
    while(++i <= app->tex.count_sprite)
    {
      double spriteX = arr_sprite[i].x - app->plr.x;
      double spriteY = arr_sprite[i].y - app->plr.y;
      double invDet = 1.0 / (app->plr.pln_x * app->plr.dir_y - app->plr.dir_x * app->plr.pln_y);
      double transformX = invDet * (app->plr.dir_y * spriteX - app->plr.dir_x * spriteY);
      double transformY = invDet * (-app->plr.pln_y * spriteX + app->plr.pln_x * spriteY);
      int spriteScreenX = (int)((app->m.r[0] / 2) * (1 + transformX / transformY));
      double spriteHeight = fabs((double)(app->m.r[0] / (transformY)) * 0.75);
      int drawStartY = -spriteHeight / 2 +app->m.r[1] / 2;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 +app->m.r[1] / 2;
      if(drawEndY >=app->m.r[1]) drawEndY =app->m.r[1] - 1;
      double spriteWidth = fabs(app->m.r[0] / (transformY) * 0.75);
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= app->m.r[0]) drawEndX = app->m.r[0] - 1;
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * app->tex.s.w / spriteWidth) / 256;
        if(transformY > 0 && stripe > 0 && stripe < app->m.r[0] && transformY < sprite_dist[stripe])
        for(int y = drawStartY; y < drawEndY; y++)
        {
          int d = (y) * 256 - app->m.r[1] * 128 + spriteHeight * 128;
           int texY = ((d * app->tex.s.h) / spriteHeight) / 256;
     int color = get_color(&app->tex.s, texX, texY);
         if((color & 0x00FFFFFF) != 0)
    my_mlx_pixel_put(app, stripe, y, color);
        }
      }
    }
}

void		cast_sprite(t_all *app, double *sprite_dist)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
    t_sprite  arr_sprite[app->tex.count_sprite];
	while(app->map[y])
	{
		x = 0;
		while(app->map[y][x])
		{
			if (app->map[y][x] == '2')
			{
				arr_sprite[i].x = x + 0.5;
				arr_sprite[i].y = y + 0.5;
				arr_sprite[i].dist = (app->plr.x - arr_sprite[i].x) * (app->plr.x - arr_sprite[i].x) + (app->plr.y - arr_sprite[i].y) * (app->plr.y - arr_sprite[i].y);
				i++;
			}
			x++;
		}
		y++;
	}
	ft_qsort(arr_sprite, 0, app->tex.count_sprite - 1);

    print_sprite(app, sprite_dist, arr_sprite);
}