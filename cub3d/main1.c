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

void	make_map(t_all *app,t_list **head, int size)
{
	app->map = calloc(size + 1,sizeof(char*));
	int		i = 0;
	int		j;
	t_list	*tmp = *head;

	while(tmp)
	{
			if (!(ft_strncmp(tmp->content, "1",1) || ft_strncmp(tmp->content, "2",1) ||
			ft_strncmp(tmp->content, " ",1) || ft_strncmp(tmp->content, "N",1) ||
			ft_strncmp(tmp->content, "W",1) || ft_strncmp(tmp->content, "S",1) ||
			ft_strncmp(tmp->content, "E",1) || ft_strncmp(tmp->content, "0",1)))
				print_error("parse error");
		app->map[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while(app->map[i++])
		ft_putendl_fd(app->map[i], 1);
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

int main(int argc, char **argv)
{
    t_all   app;
    int     len;
	char	*line = NULL;
	int fd;

	if (argc == 2 || argc == 3)
		if (!(fd = open(argv[1], O_RDONLY)))
			print_error("Wrong fd");
	init_values(&app);
	len = parser(fd, line, &app);
//    app.mlx = mlx_init();
//    app.win = mlx_new_window(app.mlx, app.map_ptr.R[0], app.map_ptr.R[1], "cub3d");
//    mlx_key_hook(app.win, press_key, app.mlx);
//    mlx_loop(app.mlx);
	return(0);
}
