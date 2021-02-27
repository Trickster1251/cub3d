#include "../cub3d.h"

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
	app->plr.dir_x = 0;
	app->plr.dir_y = 0;
    app->plr.apple = 0;
	app->plr.pln_x = 0;
	app->plr.pln_y = 0;
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
    app->tex.ea.path = 0;
    app->tex.no.path = 0;
    app->tex.we.path = 0;
    app->tex.so.path = 0;
    app->tex.s.path = 0;
    app->tex.count_sprite = 0;
    app->srcsht = 0;
}

int		is_valid_sym(char str)
{
    return ((str == '1' || str == '0' || str == 'N' ||
     str == 'S' || str == 'E' || str == 'W' || str == '2' || str == 'T' || str == 't') ? (1) : (0));
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

int		ft_is_modificator(char **arr, t_all *app)
{
    (app->map_ptr.count_mod >= 8) ? print_error("More modificators") : 0;
    if ((ft_strncmp(*arr, "R\0", 2)) == 0)
        ft_parse_r(arr, app);
    else if ((ft_strncmp(*arr, "F\0", 2) == 0) || (ft_strncmp(*arr, "C\0", 2)) == 0)
        ft_parse_f_c(arr, app);
    else if (ft_strncmp(*arr, "NO\0", 3) == 0)
        ft_parse_sprite(arr, app, 'N');
    else if (ft_strncmp(*arr, "WE\0", 3) == 0)
        ft_parse_sprite(arr, app, 'W');
    else if (ft_strncmp(*arr, "EA\0", 3) == 0)
        ft_parse_sprite(arr, app, 'E');
    else if (ft_strncmp(*arr, "SO\0", 3) == 0)
        ft_parse_sprite(arr, app, 'S');
    else if (ft_strncmp(*arr, "S\0", 2) == 0)
        ft_parse_sprite(arr, app, 's');
    return(0);
}

void    init_textures(t_all *app)
{
    if (!(app->tex.no.img = mlx_xpm_file_to_image(app->mlx, app->tex.no.path, &app->tex.no.w, &app->tex.no.h)))
        print_error("cannot open NO tex");
    if (!(app->tex.we.img = mlx_xpm_file_to_image(app->mlx, app->tex.we.path, &app->tex.we.w, &app->tex.we.h)))
        print_error("cannot open WE tex");
    if (!(app->tex.ea.img = mlx_xpm_file_to_image(app->mlx, app->tex.ea.path, &app->tex.ea.w, &app->tex.ea.h)))
        print_error("cannot open EA tex");
    if (!(app->tex.so.img = mlx_xpm_file_to_image(app->mlx, app->tex.so.path, &app->tex.so.w, &app->tex.so.h)))
        print_error("cannot open SO tex");
    if (!(app->tex.s.img = mlx_xpm_file_to_image(app->mlx, app->tex.s.path, &app->tex.s.w, &app->tex.s.h)))
        print_error("cannot open Sprite tex");
    app->tex.ea.addr = mlx_get_data_addr(app->tex.ea.img, &app->tex.ea.bpp, &app->tex.ea.line_l, &app->tex.ea.endian);
    app->tex.no.addr = mlx_get_data_addr(app->tex.no.img, &app->tex.no.bpp, &app->tex.no.line_l, &app->tex.no.endian);
    app->tex.we.addr = mlx_get_data_addr(app->tex.we.img, &app->tex.we.bpp, &app->tex.we.line_l, &app->tex.we.endian);
    app->tex.so.addr = mlx_get_data_addr(app->tex.so.img, &app->tex.so.bpp, &app->tex.so.line_l, &app->tex.so.endian);
    app->tex.s.addr = mlx_get_data_addr(app->tex.s.img, &app->tex.s.bpp, &app->tex.s.line_l, &app->tex.s.endian);
}

void	validator_map(t_all *app,t_list **head, int size)
{
    app->map = calloc(size + 1,sizeof(char*));
    int		i = -1;
    int     l = -1;
    int		j = 0;
    int     x;
    int     y;
    t_list	*tmp = *head;


    while(tmp)
    {
        app->map[++i] = tmp->content;
        while(app->map[i][j])
        {
            if (!(ft_strncmp(&app->map[i][j], "1",1) || ft_strncmp(&app->map[i][j], "2",1) ||
                ft_strncmp(&app->map[i][j], " ",1) || ft_strncmp(&app->map[i][j], "N",1) ||
                ft_strncmp(&app->map[i][j], "W",1) || ft_strncmp(&app->map[i][j], "S",1) ||
                 ft_strncmp(&app->map[i][j], "E",1) || ft_strncmp(&app->map[i][j], "0",1)))
                    print_error("parse error");
            j++;
        }
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
            if (app->map[i][j] == 'N')
                ft_is_plr(app, 'N', i, j);
            else if (app->map[i][j] == 'E')
                ft_is_plr(app, 'E', i, j);
            else if (app->map[i][j] == 'W')
                ft_is_plr(app, 'W', i, j);
            else if (app->map[i][j] == 'S')
                ft_is_plr(app, 'S', i, j);
            else if (app->map[i][j] == '2')
                app->tex.count_sprite++;
            // else if (app->map[i][j] == 't')
            // {
            //     app->t_x = j;
            //     app->t_y = i;
            // }
            // else if (app->map[i][j] == 'T')
            // {
            //     app->T_x = j;
            //     app->T_y = i;
            // }
            j++;
        }
        j = 0;
        i++;
    }
    ft_putendl_fd("---->SUCCESS<----\n", 1);
    ft_lstclear(head, &free);
}

int             parser(int fd, char *line, t_all *app)
{
    int		len;
    int		i = 0;
    char	**arr;
    t_list	*head = NULL;


    while ((len = get_next_line(fd ,&line) > 0) && (app->map_ptr.count_mod < 8))
    {
        if (line[0] != '\0')
        {
            arr = ft_split_colon(line, ' ', ',');
            ft_is_modificator(arr, app);
            free_arr(arr);
        }
        free(line);
    }
    (len < 0) ? (print_error("Something wrong with .cub file")) : (0);
    printf("\nThis is count-->%d\n", app->map_ptr.count_mod);
    while ((len = get_next_line(fd ,&line)))
    {
        if (line[0] != '\0')
        {
            // printf("%s\n", line);
            ft_lstadd_back(&head, ft_lstnew(line));
        }
        // free(line);
    }
    ft_lstadd_back(&head, ft_lstnew(line));
    validator_map(app ,&head, ft_lstsize(head));
    return (len);
}