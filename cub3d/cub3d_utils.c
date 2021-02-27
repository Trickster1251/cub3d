#include "cub3d.h"

int		ft_atoi_cube(char *str)
{
	unsigned long long	res;
	int					i;
	int					minus;

	res = 0;
	minus = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
    (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
    while(str[i] == '0')
        i++;
	if (str[i] == '-' && (minus = -1))
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	if (res > 9223372036854775807 && minus == 1)
		return (-1);
	if (res > 9223372036854775807 && minus == -1)
		return (0);
	return (res * minus);
}


int             get_color(t_img *tex, int x, int y)
{
    char    *dst;
    int     color;
    dst = tex->addr + (y * tex->line_l + x * (tex->bpp / 8));
    color =	*(unsigned int*)dst;
    return (color);
}

void    get_texture(t_all *all, int side)
{
    // 1 = so 0 = no 2 = ea 3 = we
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
// void	ft_cast_ray(t_all *all)
// {
// 	t_plr	ray = *all->plr;

// 	while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
// 	{
// 		ray.x += cos(ray.dir);
// 		ray.y += sin(ray.dir);
// 		mlx_pixel_put(all->mlx, all->win, ray.x, ray.y, 0x990099);
// 	}
// }

// void draw_map(t_all *app, t_point point, int color)
// {
//     int end_x;
//     int end_y;
//     end_x = (point.x + 1) * SCALE;
//     end_y = (point.y + 1) * SCALE;
//     point.x *= SCALE;
//     point.y *= SCALE;
//     while (point.y < end_y)
//     {
//         while (point.x < end_x)
//         {
//             mlx_pixel_put(app->mlx, app->win, point.x, point.y, app->map_ptr.F);
//             point.x++;
//         }
//         point.y++;
//         point.x -= SCALE;
//     }
// }

void            my_mlx_pixel_put(t_all *app, int x, int y, int color)
{
    char    *dst;
    dst = app->img.addr + (y * app->img.line_len + x * (app->img.bpp / 8));
    *(unsigned int*)dst = color;
}

int		ft_isdigit_str(char *str)
{
	while(*str)
	{ 
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

char	**free_arr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void		print_error(char *string)
{
    ft_putendl_fd("Error:", 1);
	ft_putendl_fd(string, 1);
	exit(0);
}
int		array_len(char **arr, int num)
{
	while(*(arr++) && *arr != '\0')
		num--;
	return (num == 0) ? (1) : (0);
}