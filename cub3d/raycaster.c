/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 05:00:50 by walethea          #+#    #+#             */
/*   Updated: 2021/03/01 19:44:42 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	what_side(t_all *app)
{
	if (app->side == 0)
	{
		if (app->step_x > 0)
		{
			app->tex.w = app->tex.so.w;
			app->tex.h = app->tex.so.h;
		}
		else
		{
			app->tex.w = app->tex.no.w;
			app->tex.h = app->tex.no.h;
		}
	}
	else
	{
		if (app->step_y > 0)
		{
			app->tex.w = app->tex.we.w;
			app->tex.h = app->tex.we.h;
		}
		else
		{
			app->tex.w = app->tex.ea.w;
			app->tex.h = app->tex.ea.h;
		}
	}
}

int		 raycaster(t_all *app)
{
	double     sprite_dist[app->m.r[0]];
	release_key(app);
	if (!(app->img.img = mlx_new_image(app->mlx, app->m.r[0], app->m.r[1])))
		print_error("Something wrong with image in raycaster");
	app->img.addr = mlx_get_data_addr(app->img.img, &app->img.bpp, &app->img.line_len, &app->img.endian);

	int i = -1;
	while(++i < app->m.r[0])
	{
		app->hit = 0;
		app->camera_x = 2 * i / (double)(app->m.r[0]) - 1;
		app->ray_dir_x = app->plr.dir_x + app->plr.pln_x * app->camera_x;
		app->ray_dir_y = app->plr.dir_y + app->plr.pln_y * app->camera_x;
		app->dlt_dst_x = fabs(1/ app->ray_dir_x);
		app->dlt_dst_y = fabs(1/ app->ray_dir_y);
		app->map_x = (int)(app->plr.x);
		app->map_y = (int)(app->plr.y);
        
		if ((app->ray_dir_x) < 0)
		{
			app->step_x = -1;
			app->side_dst_x = (app->plr.x - app->map_x) * app->dlt_dst_x;
	  	}
		else
		{
			app->step_x = 1;
			app->side_dst_x = (app->map_x + 1.0 - app->plr.x) * app->dlt_dst_x;
		}
		if (app->ray_dir_y < 0)
		{
			app->step_y = -1;
			app->side_dist_y = (app->plr.y - app->map_y) * app->dlt_dst_y;
		}
		else
		{
			app->step_y = 1;
			app->side_dist_y = (app->map_y + 1.0 - app->plr.y) * app->dlt_dst_y;
		}
		while (app->hit == 0)
		{
		    if (app->side_dst_x < app->side_dist_y)
		    {
		    	app->side_dst_x += app->dlt_dst_x;
		    	app->map_x += app->step_x;
		    	app->side = 0;
		    }
		    else
		    {
		    	app->side_dist_y += app->dlt_dst_y;
		    	app->map_y += app->step_y;
		    	app->side = 1;
		    }
		    if (app->map[app->map_y][app->map_x] == '1')
		    	app->hit = 1;
	    }
	if (app->side == 0)
	   app->perp_wall_dist = ((int)app->map_x - app->plr.x + (1 - (int)app->step_x) / 2) / app->ray_dir_x;
	else
		app->perp_wall_dist = ((int)app->map_y - app->plr.y + (1 - (int)app->step_y) / 2) / app->ray_dir_y;
	sprite_dist[i] = app->perp_wall_dist;
	app->line_h = (int)(app->m.r[0] / app->perp_wall_dist) * 0.75;
	int drawStart = -app->line_h / 2 + app->m.r[1] / 2;
	if (drawStart < 0)
	    drawStart = 0;
	int drawEnd = app->line_h / 2 + app->m.r[1] / 2;
	if (drawEnd >= app->m.r[1]) drawEnd = app->m.r[1] - 1;
	if (app->side == 0)
        app->wall_x = app->plr.y + app->perp_wall_dist * app->ray_dir_y;
	else
        app->wall_x = app->plr.x + app->perp_wall_dist * app->ray_dir_x;
	app->wall_x -= floor((app->wall_x));
	what_side(app);
	app->tex_x = (int)(app->wall_x * (double)(app->tex.w));
	if(app->side == 0 && app->ray_dir_x > 0) app->tex_x = app->tex.w - app->tex_x - 1;
	if(app->side == 1 && app->ray_dir_y < 0) app->tex_x = app->tex.w - app->tex_x - 1;
	app->step = 1.0 * app->tex.h / app->line_h;
	app->tex_pos = (drawStart - app->m.r[1] / 2 + app->line_h / 2) * app->step;
	int y = -1;
	while(++y < app->m.r[1])
	{
		if (y < drawStart)
		  my_mlx_pixel_put(app, i, y, app->m.c);
		else if (y >= drawStart && y< drawEnd)
		{
		  app->tex_y = (int)app->tex_pos & (app->tex.h - 1);
		  app->tex_pos += app->step;
		  get_texture(app, app->side);
		  my_mlx_pixel_put(app, i, y, app->color);
		}
		else if (y > drawEnd && y < app->m.r[1])
		  my_mlx_pixel_put(app, i, y, app->m.f);
	}
}
	cast_sprite(app, sprite_dist);
	if (app->srcsht == 0)
	{
	  mlx_put_image_to_window(app->mlx, app->win, app->img.img, 0, 0);
	  mlx_destroy_image(app->mlx, app->img.img);
	}
	return (0);
}