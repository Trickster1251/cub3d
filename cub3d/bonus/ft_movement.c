#include "../cub3d.h"

void    ft_is_plr(t_all *app, char dir, int i, int j)
{
    app->plr.x = j + 0.5;
    app->plr.y = i + 0.5;
    if (dir == 'S')
    {
        app->plr.dir_y = 1;
        app->plr.pln_x = -0.66;
    }
    else if (dir == 'E')
    {
        app->plr.dir_x = 1;
	    app->plr.pln_y = 0.66;
    }
    else if (dir == 'N')
    {
        app->plr.dir_y = -1;
        app->plr.pln_x = 0.66;
    }
    else if (dir == 'W')
    {
        app->plr.dir_x = -1;
	    app->plr.pln_y = -0.66;
    }
    app->map[i][j] = '0';
}

int	release_key(t_all* a)
{
    int     resp_x;
    int     resp_y;
	if (a->key.s == 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x - a->plr.pln_y * MS)] != '1')
        {
		    a->plr.x -= a->plr.pln_y * MS;
            if (a->map[(int)a->plr.y][(int)(a->plr.x - a->plr.pln_y * MS)] == '2')
            {
                a->map[(int)a->plr.y][(int)(a->plr.x -= a->plr.pln_y * MS)] = '0';
                a->plr.apple++;
            }
            if (a->map[(int)a->plr.y][(int)(a->plr.x - a->plr.pln_y * MS)] == 'T')
            {
                a->plr.x = a->t_x;
                a->plr.y = a->t_y;
            }
            if (a->map[(int)a->plr.y][(int)(a->plr.x - a->plr.pln_y * MS)] == 't')
            {
                a->plr.x = a->T_x;
                a->plr.y = a->T_y;
            }
        }
        if (a->map[(int)(a->plr.y + a->plr.pln_x * MS)][(int)a->plr.x] != '1')
        {
            a->plr.y += a->plr.pln_x * MS;
            if (a->map[(int)(a->plr.y + a->plr.pln_x * MS)][(int)a->plr.x] == '2')
            {
                a->map[(int)(a->plr.y += a->plr.pln_x * MS)][(int)a->plr.x] = '0';
                a->plr.apple++;
            }
            if (a->map[(int)(a->plr.y + a->plr.pln_x * MS)][(int)a->plr.x] == 't')
            {
                a->plr.x = a->T_x;
                a->plr.y = a->T_y;
            }
            if (a->map[(int)(a->plr.y + a->plr.pln_x * MS)][(int)a->plr.x] == 'T')
            {
                a->plr.x = a->t_x;
                a->plr.y = a->t_y;
            }
        }
	}	
	else if (a->key.w == 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.pln_y * MS)] != '1')
        {
		    a->plr.x += a->plr.pln_y * MS;
            if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.pln_y * MS)] == '2')
            {
                a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.pln_y * MS)] = '0';
                a->plr.apple++;
            }
            if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.pln_y * MS)] == 't')
            {
                a->plr.x = a->T_x;
                a->plr.y = a->T_y;
            }
            if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.pln_y * MS)] == 'T')
            {
                a->plr.x = a->t_x;
                a->plr.y = a->t_y;
            }

        }
        if (a->map[(int)(a->plr.y - a->plr.pln_x * MS)][(int)a->plr.x] != '1')
        {
            a->plr.y -= a->plr.pln_x * MS;
            if (a->map[(int)(a->plr.y - a->plr.pln_x * MS)][(int)a->plr.x] == '2')
            {
                a->map[(int)(a->plr.y - a->plr.pln_x * MS)][(int)a->plr.x] = '0';
                a->plr.apple++;
            }
            if (a->map[(int)(a->plr.y - a->plr.pln_x * MS)][(int)a->plr.x] == 't')
            {
                a->plr.x = a->T_x;
                a->plr.y = a->T_y;
            }
            if (a->map[(int)(a->plr.y - a->plr.pln_x * MS)][(int)a->plr.x] == 'T')
            {
                a->plr.x = a->t_x;
                a->plr.y = a->t_y;
            }
        }
	}
    else if (a->key.a == 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x - a->plr.pln_x * MS)] != '1')
		    a->plr.x -= a->plr.pln_x * MS;
        if (a->map[(int)(a->plr.y - a->plr.pln_y * MS)][(int)a->plr.x] != '1')
            a->plr.y -= a->plr.pln_y * MS;
	}
    else if (a->key.d== 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.pln_x * MS)] != '1')
		    a->plr.x += a->plr.pln_x * MS;
        if (a->map[(int)(a->plr.y + a->plr.pln_y * MS)][(int)a->plr.x] != '1')
            a->plr.y += a->plr.pln_y * MS;
	}
	else if (a->key.q == 1)
	{
		double	old_dir_x = a->plr.dir_x;
		a->plr.dir_x = a->plr.dir_x * cos(-0.1) - a->plr.dir_y * sin(-0.1);
		a->plr.dir_y = old_dir_x * sin(-0.1) + a->plr.dir_y * cos(-0.1);
		double	old_plane_x = a->plr.pln_x;
		a->plr.pln_x = a->plr.pln_x * cos(-0.1) - a->plr.pln_y * sin(-0.1);
		a->plr.pln_y = old_plane_x * sin(-0.1) + a->plr.pln_y * cos(-0.1);
	}
	else if (a->key.e == 1)
	{
		double	old_dir_x = a->plr.dir_x;
		a->plr.dir_x = a->plr.dir_x * cos(0.1) - a->plr.dir_y * sin(0.1);
		a->plr.dir_y = old_dir_x * sin(0.1) + a->plr.dir_y * cos(0.1);
		double	old_plane_x = a->plr.pln_x;
		a->plr.pln_x = a->plr.pln_x * cos(0.1) - a->plr.pln_y * sin(0.1);
		a->plr.pln_y = old_plane_x * sin(0.1) + a->plr.pln_y * cos(0.1);
	}
	return (0);
} 