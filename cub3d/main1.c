#include "cub3d.h"

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

void	make_map(t_all *app,t_list **head, int size)
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
    {
        ft_lstadd_back(&head, ft_lstnew(line));
    }
    ft_lstadd_back(&head, ft_lstnew(line));
    make_map(app ,&head, ft_lstsize(head));


    return (len);
}

void draw_map(t_all *app, t_point point, int color)
{
    int end_x;
    int end_y;
    end_x = (point.x + 1) * SCALE;
    end_y = (point.y + 1) * SCALE;
    point.x *= SCALE;
    point.y *= SCALE;
    while (point.y < end_y)
    {
        while (point.x < end_x)
        {
            mlx_pixel_put(app->mlx, app->win, point.x, point.y, app->map_ptr.F);
            point.x++;
        }
        point.y++;
        point.x -= SCALE;
    }
}

int main(int argc, char **argv)
{
    t_all   app;
    t_point point;
    t_plr plr;
    int     len;
    char	*line = NULL;
    int fd;
    int i = -1, j = -1;

    if (argc == 2 || argc == 3)
        if (!(fd = open(argv[1], O_RDONLY)))
            print_error("Wrong fd");
    init_values(&app, &point, &plr);
    len = parser(fd, line, &app);
    app.mlx = mlx_init();
    app.win = mlx_new_window(app.mlx, app.map_ptr.R[0], app.map_ptr.R[1], "cub3d");
    mlx_key_hook(app.win, press_key, app.mlx);
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
    i = -1;
    while(++i <= app.map_ptr.R[0])
    {
        app.camera_x = 2 * i / (double)(app.map_ptr.R[0]) - 1;
        app.ray_dir_x = plr.dir_x + plr.plane_x * app.camera_x;
        app.ray_dir_y = plr.dir_y + plr.plane_y * app.camera_x;

        app.delta_dist_x = fabs(1/ app.ray_dir_x);
        app.delta_dist_y = fabs(1/ app.ray_dir_y);

        //calculate step and initial sideDist
      if ((app.ray_dir_x) < 0)
      {
        app.step_x = -1;
        app.side_dist_x = (plr.x - app.map_x) * app.delta_dist_x;
      }
      else
      {
        app.step_x = 1;
        app.side_dist_x = (app.map_x + 1.0 - plr.x) * app.delta_dist_x;
      }
      if (app.ray_dir_y < 0)
      {
        app.step_y = -1;
        app.side_dist_y = (plr.y - app.map_y) * app.delta_dist_y;
      }
      else
      {
        app.step_y = 1;
        app.side_dist_y = (app.map_y + 1.0 - plr.y) * app.delta_dist_y;
      }
      
      while (app.hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (app.side_dist_x < app.side_dist_y)
        {
          app.side_dist_x += app.delta_dist_x;
          app.map_x += app.step_x;
          app.side = 0;
        }
        else
        {
          app.side_dist_y += app.delta_dist_y;
          app.map_y += app.step_y;
          app.side = 1;
        }
        //Check if ray has hit a wall
        if (app.map[app.map_x][app.map_y] == '1')
            app.hit = 1;
      }

    if (app.side == 0) app.perp_wall_dist = (app.map_x - plr.x + (1 - app.step_x) / 2) / app.ray_dir_x;
      else           app.perp_wall_dist = (app.map_y - plr.y + (1 - app.step_y) / 2) / app.ray_dir_y;
    
    //Calculate height of line to draw on screen
      int lineHeight = (int)(app.map_ptr.R[1] / app.perp_wall_dist);
    //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + app.map_ptr.R[1] / 2;

        if(drawStart < 0)
            drawStart = 0;
      int drawEnd = lineHeight / 2 + app.map_ptr.R[1] / 2;
         if(drawEnd >= app.map_ptr.R[1])drawEnd = app.map_ptr.R[1] - 1;
    
    int y = -1;
    while(++y <= app.map_ptr.R[1])
    {
        if (y < drawStart)
        {
            mlx_pixel_put(app.mlx, app.win, i, y, app.map_ptr.C);
        }
        else if (y >= drawStart && y<= drawEnd)
        {
            mlx_pixel_put(app.mlx, app.win, i, y, 0x990091);
        }
        else if (y > drawEnd && y < app.map_ptr.R[1])
        {
            mlx_pixel_put(app.mlx, app.win, i, y, app.map_ptr.F);
        }
    }
    }
    mlx_loop(app.mlx);
    return(0);
}