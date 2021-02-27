void  cast_sprite(t_all *app, double *sprite_dist)
{
 int  x;
 int  y;
 int  i;
 t_sprite  arr_sprite[app->tex.count_sprite];
 
 y = 0;
 i = 0;
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

 i = -1;
 while(++i <= app->tex.count_sprite)
 {
      double spriteX = arr_sprite[i].x - app->plr.x;
      double spriteY = arr_sprite[i].y - app->plr.y;
      double invDet = 1.0 / (app->plr.plane_x * app->plr.dir_y - app->plr.dir_x * app->plr.plane_y);
      double transformX = invDet * (app->plr.dir_y * spriteX - app->plr.dir_x * spriteY);
      double transformY = invDet * (-app->plr.plane_y * spriteX + app->plr.plane_x * spriteY);
      int spriteScreenX = (int)((app->map_ptr.r[0] / 2) * (1 + transformX / transformY));
      double spriteHeight = fabs((double)(app->map_ptr.r[0] / (transformY)));
      int drawStartY = -spriteHeight / 2 +app->map_ptr.r[1] / 2;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 +app->map_ptr.r[1] / 2;
      if(drawEndY >=app->map_ptr.r[1]) drawEndY =app->map_ptr.r[1] - 1;
      double spriteWidth = fabs(app->map_ptr.r[0] / (transformY));
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= app->map_ptr.r[0]) drawEndX = app->map_ptr.r[0] - 1;
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * app->tex.s.w / spriteWidth) / 256;
        if(transformY > 0 && stripe > 0 && stripe < app->map_ptr.r[0] && transformY < sprite_dist[stripe])
        for(int y = drawStartY; y < drawEndY; y++)
        {
          int d = (y) * 256 - app->map_ptr.r[1] * 128 + spriteHeight * 128;
           int texY = ((d * app->tex.s.h) / spriteHeight) / 256;
     int color = get_color(&app->tex.s, texX, texY);
         if((color & 0x00FFFFFF) != 0)
    my_mlx_pixel_put(app, stripe, y, color);
        }
      }
    }
}