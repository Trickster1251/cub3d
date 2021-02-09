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
    i = -1;
    j = -1;
    x = 10;
    y = 10;
    // while(app->map[0][++j])
    // {
    //     mlx_pixel_put(app->mlx, app->win, j, 0, app->map_ptr.F);
    // }
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
    int     len;
    char	*line = NULL;
    int fd;
    int i = -1, j = -1;

    if (argc == 2 || argc == 3)
        if (!(fd = open(argv[1], O_RDONLY)))
            print_error("Wrong fd");
    init_values(&app, &point);
    len = parser(fd, line, &app);
    app.mlx = mlx_init();
    app.win = mlx_new_window(app.mlx, app.map_ptr.R[0], app.map_ptr.R[1], "cub3d");
    mlx_key_hook(app.win, press_key, app.mlx);
    while(app.map[++i])
    {
        while(app.map[i][++j])
        {
            point.x = j;
            point.y = i;
            if (app.map[i][j] == '1')
                draw_map(&app, point, app.map_ptr.F);
        }
        j = -1;
    }
    mlx_loop(app.mlx);
    return(0);
}
