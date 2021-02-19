#include "cub3d.h"

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

int		ft_is_modificator(char **arr, t_all *app)
{
    (app->map_ptr.count_mod >= 8) ? print_error("More modificators") : 0;
    if ((ft_strncmp(*arr, "R\0", 2)) == 0)
        ft_parse_R(arr, app);
    else if ((ft_strncmp(*arr, "F\0", 2) == 0) || (ft_strncmp(*arr, "C\0", 2)) == 0)
        ft_parse_F_C(arr, app);
    else if (ft_strncmp(*arr, "NO\0", 3) == 0)
        ft_parse_sprite(arr, app, 'N');
    else if (ft_strncmp(*arr, "WE\0", 3) == 0)
        ft_parse_sprite(arr, app, 'W');
    else if (ft_strncmp(*arr, "EA\0", 3) == 0)
        ft_parse_sprite(arr, app, 'E');
    else if (ft_strncmp(*arr, "SO\0", 3) == 0)
        ft_parse_sprite(arr, app, 's');
    else if (ft_strncmp(*arr, "S\0", 2) == 0)
        ft_parse_sprite(arr, app, 'S');
    return(0);
}

int		is_valid_sym(char str)
{
    return ((str == '1' || str == '0' || str == 'N' ||
     str == 'S' || str == 'E' || str == 'W' || str == '2') ? (1) : (0));
}

int		is_valid_space(char str)
{
    return ((str == '1' || str == ' ') ? (1) : (0));
}

int     skip_space(char *str)
{
    int     i = 0;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    return(i);
}

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

void	validator_map(t_all *app,t_list **head, int size)
{
    app->map = calloc(size + 1,sizeof(char*));
    int		i = -1;
    int		j = 0;
    int     x;
    int     y;
    t_list	*tmp = *head;

    while(tmp)
    {
        app->map[++i] = tmp->content;
        if (!(ft_strncmp(app->map[i], "1",1) || ft_strncmp(app->map[i], "2",1) ||
            ft_strncmp(app->map[i], " ",1) || ft_strncmp(app->map[i], "N",1) ||
            ft_strncmp(app->map[i], "W",1) || ft_strncmp(app->map[i], "S",1) ||
            ft_strncmp(app->map[i], "E",1) || ft_strncmp(app->map[i], "0",1)))
                print_error("parse error");
        tmp = tmp->next;
    }
    i = -1;
    while(app->map[++i])
        ft_putendl_fd(app->map[i], 1);
    i = 0;
    while(app->map[i])
    {
        j = skip_space(app->map[i]);
        while(app->map[i][j])
        {
            if (i == 0 && app->map[i][j] == '0')
                print_error("parse error, zero no lock on first line");
            else if (i == (size - 1) && app->map[i][j] == '0')
                print_error("parse error, zero no lock on last line");
            else if (i == (size - 1) && app->map[i][j] == ' ')
                break;
            else if (app->map[i][j] == ' ' &&
            !(is_valid_space(app->map[i - 1][j]) &&
            is_valid_space(app->map[i + 1][j]) && 
            is_valid_space(app->map[i][j - 1]) &&
            is_valid_space(app->map[i + 1][j + 1]) &&
            is_valid_space(app->map[i + 1][j - 1]) &&
            is_valid_space(app->map[i - 1][j - 1]) &&
            is_valid_space(app->map[i - 1][j + 1]) &&
            is_valid_space(app->map[i][j + 1])
            ))
            {
                printf("\n%s\n", app->map[i]);
                printf("---->%c%i\n", app->map[i][j], j);
                print_error("parse error, space no lock");
            }
            else if (app->map[i][j] == '0' &&
            !(is_valid_sym(app->map[i - 1][j]) &&
            is_valid_sym(app->map[i + 1][j]) && 
            is_valid_sym(app->map[i][j - 1]) &&
            is_valid_sym(app->map[i + 1][j + 1]) &&
            is_valid_sym(app->map[i + 1][j - 1]) &&
            is_valid_sym(app->map[i - 1][j - 1]) &&
            is_valid_sym(app->map[i - 1][j + 1]) &&
            is_valid_sym(app->map[i][j + 1])
            ))
            {
                 printf("\n%s\n", app->map[i]);
                printf("---->%c%i\n", app->map[i][j], j);
                print_error("parse error, zero no lock");
            }
            j++;
        }
        j = 0;
        i++;
    }
    ft_putendl_fd("---->SUCCESS<----\n", 1);
    ft_lstclear(head, &free);
}

void            my_mlx_pixel_put(t_all *app, int x, int y, int color)
{
    char    *dst;
    dst = app->img.addr + (y * app->img.line_len + x * (app->img.bpp / 8));
    *(unsigned int*)dst = color;
}

int		parser(int fd, char *line, t_all *app)
{
    int		len;
    int		i = 0;
    char	**arr;
    t_list	*head = NULL;
    
    while ((len = get_next_line(fd ,&line)) && line[0] != '\0')
    {
            arr = ft_split(line, ' ');
            ft_is_modificator(arr, app);
            free_arr(arr);
            free(line);
    }
    printf("\nThis is count-->%d\n", app->map_ptr.count_mod);
    while ((len = get_next_line(fd ,&line))&& line[0] != '\0')
        ft_lstadd_back(&head, ft_lstnew(line));
    ft_lstadd_back(&head, ft_lstnew(line));
    validator_map(app ,&head, ft_lstsize(head));
    return (len);
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

void	free_arr(char **arr)
{
	free(*arr);
}

void	init_values(t_all *app)
{
	app->map_ptr.r_i = 0;
	app->map_ptr.f_i = 0;
	app->map_ptr.n_i = 0;
	app->map_ptr.w_i = 0;
	app->map_ptr.e_i = 0;
	app->map_ptr.s_i = 0;
	app->map_ptr.so_i = 0;
    app->map_ptr.count_mod = 0;
	// point->x = 0;
	// point->y = 0;
	app->plr.x = 4;
	app->plr.y = 4;
	app->plr.dir_x = -1;
	app->plr.dir_y = 0;
	app->plr.plane_x = 0;
	app->plr.plane_y = 0.66;
	app->side_dist_x = 0;
	app->side_dist_y = 0;
	app->delta_dist_x = 0;
	app->delta_dist_y = 0;
	app->perp_wall_dist = 0;
	app->step_x = 0;
	app->step_y = 0;
	app->hit = 0;
	app->side = 0;
	app->key.w = 0;
    app->key.a = 0;
    app->key.s = 0;
    app->key.d = 0;
    app->key.q = 0;
    app->key.e = 0;
    // app->key->esc = 0;
}

void		print_error(char *string)
{
	ft_putendl_fd(string, 1);
	exit(0);
}


int		array_len(char **arr, int num)
{
	while(*(arr++) && *arr != '\0')
		num--;
	return (num == 0) ? (1) : (0);
}

int	release_key(t_all* a)
{

	if (a->key.w == 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x - a->plr.plane_y * MOVE_SPEED)] != '1')
		    a->plr.x -= a->plr.plane_y * MOVE_SPEED;
        if (a->map[(int)(a->plr.y + a->plr.plane_x * MOVE_SPEED)][(int)a->plr.x] != '1')
            a->plr.y += a->plr.plane_x * MOVE_SPEED;
        printf("plr.x=%f\nplr.y=%f\nplr.plane.x=%f\nplr.plane.y=%f\n-----------------------\n", a->plr.x, a->plr.y, a->plr.plane_x, a->plr.plane_y);
	}	
	else if (a->key.s == 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.plane_y * MOVE_SPEED)] != '1')
		    a->plr.x += a->plr.plane_y * MOVE_SPEED;
        if (a->map[(int)(a->plr.y - a->plr.plane_x * MOVE_SPEED)][(int)a->plr.x] != '1')
            a->plr.y -= a->plr.plane_x * MOVE_SPEED;
	}
    else if (a->key.a == 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x + a->plr.plane_x * MOVE_SPEED)] != '1')
		    a->plr.x += a->plr.plane_x * MOVE_SPEED;
        if (a->map[(int)(a->plr.y - a->plr.plane_y * MOVE_SPEED)][(int)a->plr.x] != '1')
            a->plr.y -= a->plr.plane_y * MOVE_SPEED;
	}
    else if (a->key.d == 1)
	{
        if (a->map[(int)a->plr.y][(int)(a->plr.x - a->plr.plane_x * MOVE_SPEED)] != '1')
		    a->plr.x -= a->plr.plane_x * MOVE_SPEED;
        if (a->map[(int)(a->plr.y + a->plr.plane_y * MOVE_SPEED)][(int)a->plr.x] != '1')
            a->plr.y += a->plr.plane_y * MOVE_SPEED;
	}
	else if (a->key.e == 1)
	{
		double	old_dir_x = a->plr.dir_x;
		a->plr.dir_x = a->plr.dir_x * cos(-0.1) - a->plr.dir_y * sin(-0.1);
		a->plr.dir_y = old_dir_x * sin(-0.1) + a->plr.dir_y * cos(-0.1);
		double	old_plane_x = a->plr.plane_x;
		a->plr.plane_x = a->plr.plane_x * cos(-0.1) - a->plr.plane_y * sin(-0.1);
		a->plr.plane_y = old_plane_x * sin(-0.1) + a->plr.plane_y * cos(-0.1);
	}
	else if (a->key.q == 1)
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