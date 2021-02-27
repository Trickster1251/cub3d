#include "cub3d.h"


  // while(app.map[++i])
	// {
	//     while(app.map[i][++j])
	//     {
	//         point.x = j;
	//         point.y = i;
	//         if (app.map[i][j] == '1')
	//             draw_map(&app, point, app.map_ptr.F);
	//     }
	//     j = -1;
	// }
	// ft_cast_ray(&app);
int    keep_key(int keycode, t_all *a)
{   
	(keycode == 13) ? (a->key.w = 0) :
	(keycode == 12) ? (a->key.q = 0) :
	(keycode == 1) ? (a->key.s = 0) :
	(keycode == 0) ? (a->key.a = 0) :
	(keycode == 2) ? (a->key.d = 0) :
	(keycode == 14) ? (a->key.e = 0) : 0;
	return (0);
}

int     press_key(int keycode, t_all *a)
{   
	(keycode == 13) ? (a->key.w = 1) :
	(keycode == 12) ? (a->key.q = 1) :
	(keycode == 1) ? (a->key.s = 1) :
	(keycode == 14) ? (a->key.e = 1) :
	(keycode == 0) ? (a->key.a = 1) :
	(keycode == 2) ? (a->key.d = 1) :
	(keycode == 53) ? exit(0) : (0);
	return (0);
}

int     raycaster(t_all *app)
{


	int   tex_h;
	int   tex_w;
	double     sprite_dist[app->map_ptr.r[0]];

	tex_h = 0;
	tex_w = 0;
	tex_h = 0;
	release_key(app);
	if (!(app->img.img = mlx_new_image(app->mlx, app->map_ptr.r[0], app->map_ptr.r[1])))
		print_error("Something wrong with image in raycaster");
	app->img.addr = mlx_get_data_addr(app->img.img, &app->img.bpp, &app->img.line_len, &app->img.endian);

	int i = -1;
	while(++i < app->map_ptr.r[0])
	{
		app->hit = 0;
		app->camera_x = 2 * i / (double)(app->map_ptr.r[0]) - 1;
		app->ray_dir_x = app->plr.dir_x + app->plr.plane_x * app->camera_x;
		app->ray_dir_y = app->plr.dir_y + app->plr.plane_y * app->camera_x;

		app->delta_dist_x = fabs(1/ app->ray_dir_x);
		app->delta_dist_y = fabs(1/ app->ray_dir_y);

		app->map_x = (int)(app->plr.x);
		app->map_y = (int)(app->plr.y);

		//calculate step and initial sideDist
	  if ((app->ray_dir_x) < 0)
	  {
		app->step_x = -1;
		app->side_dist_x = (app->plr.x - app->map_x) * app->delta_dist_x;
	  }
	  else
	  {
		app->step_x = 1;
		app->side_dist_x = (app->map_x + 1.0 - app->plr.x) * app->delta_dist_x;
	  }
	  if (app->ray_dir_y < 0)
	  {
		app->step_y = -1;
		app->side_dist_y = (app->plr.y - app->map_y) * app->delta_dist_y;
	  }
	  else
	  {
		app->step_y = 1;
		app->side_dist_y = (app->map_y + 1.0 - app->plr.y) * app->delta_dist_y;
	  }
  

	  while (app->hit == 0)
	  {
		//jump to next map square, OR in x-direction, OR in y-direction
		if (app->side_dist_x < app->side_dist_y)
		{
		  app->side_dist_x += app->delta_dist_x;
		  app->map_x += app->step_x;
		  app->side = 0;
		}
		else
		{
		  app->side_dist_y += app->delta_dist_y;
		  app->map_y += app->step_y;
		  app->side = 1;
		}
		//Check if ray has hit a wall
		if (app->map[app->map_y][app->map_x] == '1')
			app->hit = 1;
	  }

	if (app->side == 0)
	   app->perp_wall_dist = ((int)app->map_x - app->plr.x + (1 - (int)app->step_x) / 2) / app->ray_dir_x;
	else
		app->perp_wall_dist = ((int)app->map_y - app->plr.y + (1 - (int)app->step_y) / 2) / app->ray_dir_y;

	sprite_dist[i] = app->perp_wall_dist;

	  app->line_h = (int)(app->map_ptr.r[0] / app->perp_wall_dist);
	  
	  int drawStart = -app->line_h / 2 + app->map_ptr.r[1] / 2;

	  if (drawStart < 0)
		drawStart = 0;
	  int drawEnd = app->line_h / 2 + app->map_ptr.r[1] / 2;
		if (drawEnd >= app->map_ptr.r[1]) drawEnd = app->map_ptr.r[1] - 1;
  
	/////////////
	if (app->side == 0) app->wall_x = app->plr.y + app->perp_wall_dist * app->ray_dir_y;
	  else           app->wall_x = app->plr.x + app->perp_wall_dist * app->ray_dir_x;
	  app->wall_x -= floor((app->wall_x));

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
	
	  //x coordinate on the texture
	  app->tex_x = (int)(app->wall_x * (double)(app->tex.w));
	  if(app->side == 0 && app->ray_dir_x > 0) app->tex_x = app->tex.w - app->tex_x - 1;
	  if(app->side == 1 && app->ray_dir_y < 0) app->tex_x = app->tex.w - app->tex_x - 1;


	  app->step = 1.0 * app->tex.h / app->line_h;
	  app->tex_pos = (drawStart - app->map_ptr.r[1] / 2 + app->line_h / 2) * app->step;

	int y = -1;
	while(++y < app->map_ptr.r[1])
	{
		if (y < drawStart)
		  my_mlx_pixel_put(app, i, y, app->map_ptr.c);
		else if (y >= drawStart && y< drawEnd)
		{
		  app->tex_y = (int)app->tex_pos & (app->tex.h - 1);
		  app->tex_pos += app->step;
		  get_texture(app, app->side);
		  my_mlx_pixel_put(app, i, y, app->color);
		}
		else if (y > drawEnd && y < app->map_ptr.r[1])
		  my_mlx_pixel_put(app, i, y, app->map_ptr.f);
	}
	}
	cast_sprite(app, sprite_dist);
	if (app->srcsht != 1)
	{
	  mlx_put_image_to_window(app->mlx, app->win, app->img.img, 0, 0);
	  mlx_destroy_image(app->mlx, app->img.img);
	}
	return (0);
}

int   close_window(t_all *app)
{
  exit(0);
}

int main(int argc, char **argv)
{
	t_all   app;
	int     len;
	char	*line = NULL;
	int fd;
	int i = -1, j = -1;

	if (argc == 2 || argc == 3)
		if (!(fd = open(argv[1], O_RDONLY)))
			print_error("Wrong fd");
	init_values(&app);
	len = parser(fd, line, &app);
	app.mlx = mlx_init();
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 7) == 0))
	{
	  app.srcsht = 1;
	  init_textures(&app);
	  raycaster(&app);
	  render_bmp(&app);
	}
	else if (argc == 3)
	  print_error("wrong flag argument, may be u mean \"--save\"");
	app.win = mlx_new_window(app.mlx, app.map_ptr.r[0], app.map_ptr.r[1], "cub3d");
	init_textures(&app);
	mlx_hook(app.win, 2, 0, press_key, &app);
	mlx_hook(app.win, 3, 0, keep_key, &app);
	mlx_hook(app.win, 17, 0, close_window, &app);
	mlx_loop_hook(app.mlx, raycaster, &app);
	mlx_loop(app.mlx);
	return(0);
}