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

void		record_arr_sprites(t_all *app)
{
	int		x;
	int		y;
	int		i;
    app->ar_spr = (t_sprite*)malloc(sizeof(t_sprite) * app->tex.count_sprite);

	y = 0;
	i = 0;
	while(app->map[y])
	{
		x = 0;
		while(app->map[y][x])
		{
			if (app->map[y][x] == '2')
			{
				app->ar_spr[i].x = x + 0.5;
				app->ar_spr[i].y = y + 0.5;
				app->ar_spr[i].dist = (app->plr.x - app->ar_spr[i].x) * (app->plr.x - app->ar_spr[i].x) + (app->plr.y - app->ar_spr[i].y) * (app->plr.y - app->ar_spr[i].y);
				i++;
			}
			x++;
		}
		y++;
	}
}

void		cast_sprite(t_all *app, double *sprite_dist)
{
	int i;
	
	if (app->rec_flag == 1)
	{
		record_arr_sprites(app);
		app->rec_flag = 0;
	}
	ft_qsort(app->ar_spr, 0, app->tex.count_sprite - 1);
    printf ("-------------\n");
    for (int k = 0; k < app->tex.count_sprite; k++)
        printf("%f\n", app->ar_spr[k].dist);
	i = 0;    
	while(i <= (app->tex.count_sprite - 1))
	{
      double spriteX = app->ar_spr[i].x - app->plr.x;
      double spriteY = app->ar_spr[i].y - app->plr.y;
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
      i++;
    }
}