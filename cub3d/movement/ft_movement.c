#include "../cub3d.h"

void    ft_is_plr(t_all *app, char dir, int i, int j)
{
    app->plr.x = j + 0.5;
    app->plr.y = i + 0.5;
    if (dir == 'S')
    {
        app->plr.dir_y = 1;
        app->plr.plane_x = -0.66;
    }
    else if (dir == 'E')
    {
        app->plr.dir_x = 1;
	    app->plr.plane_y = 0.66;
    }
    else if (dir == 'N')
    {
        app->plr.dir_y = -1;
        app->plr.plane_x = 0.66;
    }
    else if (dir == 'W')
    {
        app->plr.dir_x = -1;
	    app->plr.plane_y = -0.66;
    }
}

int	release_key(t_all* a)
{

	if (a->key.s == 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x - a->plr.plane_y * MOVE_SPEED)] != '1')
		    a->plr.x -= a->plr.plane_y * MOVE_SPEED;
        if (a->map[(int)(a->plr.y + a->plr.plane_x * MOVE_SPEED)][(int)a->plr.x] != '1')
            a->plr.y += a->plr.plane_x * MOVE_SPEED;
        printf("plr.x=%f\nplr.y=%f\nplr.plane.x=%f\nplr.plane.y=%f\n-----------------------\n", a->plr.x, a->plr.y, a->plr.plane_x, a->plr.plane_y);
	}	
	else if (a->key.w == 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.plane_y * MOVE_SPEED)] != '1')
		    a->plr.x += a->plr.plane_y * MOVE_SPEED;
        if (a->map[(int)(a->plr.y - a->plr.plane_x * MOVE_SPEED)][(int)a->plr.x] != '1')
            a->plr.y -= a->plr.plane_x * MOVE_SPEED;
	}
    else if (a->key.a == 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x - a->plr.plane_x * MOVE_SPEED)] != '1')
		    a->plr.x -= a->plr.plane_x * MOVE_SPEED;
        if (a->map[(int)(a->plr.y - a->plr.plane_y * MOVE_SPEED)][(int)a->plr.x] != '1')
            a->plr.y -= a->plr.plane_y * MOVE_SPEED;
	}
    else if (a->key.d== 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.plane_x * MOVE_SPEED)] != '1')
		    a->plr.x += a->plr.plane_x * MOVE_SPEED;
        if (a->map[(int)(a->plr.y + a->plr.plane_y * MOVE_SPEED)][(int)a->plr.x] != '1')
            a->plr.y += a->plr.plane_y * MOVE_SPEED;
	}
	else if (a->key.q == 1)
	{
		double	old_dir_x = a->plr.dir_x;
		a->plr.dir_x = a->plr.dir_x * cos(-0.1) - a->plr.dir_y * sin(-0.1);
		a->plr.dir_y = old_dir_x * sin(-0.1) + a->plr.dir_y * cos(-0.1);
		double	old_plane_x = a->plr.plane_x;
		a->plr.plane_x = a->plr.plane_x * cos(-0.1) - a->plr.plane_y * sin(-0.1);
		a->plr.plane_y = old_plane_x * sin(-0.1) + a->plr.plane_y * cos(-0.1);
	}
	else if (a->key.e == 1)
	{
		double	old_dir_x = a->plr.dir_x;
		a->plr.dir_x = a->plr.dir_x * cos(0.1) - a->plr.dir_y * sin(0.1);
		a->plr.dir_y = old_dir_x * sin(0.1) + a->plr.dir_y * cos(0.1);
		double	old_plane_x = a->plr.plane_x;
		a->plr.plane_x = a->plr.plane_x * cos(0.1) - a->plr.plane_y * sin(0.1);
		a->plr.plane_y = old_plane_x * sin(0.1) + a->plr.plane_y * cos(0.1);
	}
	return (0);
}