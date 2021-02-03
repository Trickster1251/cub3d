#include "cub3d.h"

// int		ft_is_modificator(char **arr, t_all *app)
// {

// 	if ((ft_strncmp(*arr, "R ", 2)) == 0)
// 	{
// 		ft_parse_R(arr, app);
// 		// printf("%d",app->map_ptr.count_mod);
// 	}
// 	else if ((ft_strncmp(*arr, "F ", 2) || ft_strncmp(*arr, "C ", 2)) == 0)
// 		ft_parse_F(arr, app);
// 	return(0);
// }

int		ft_is_modificator(char **arr, t_all *app)
{
	if ((ft_strncmp(*arr, "R", 1)) == 0)
	{
		printf("modigicator is R\n");
		ft_parse_R(arr, app);
	}
	else if ((ft_strncmp(*arr, "F", 1) == 0) || (ft_strncmp(*arr, "C", 1)) == 0)
	{
		printf("modigicator is F or C\n");
		ft_parse_F(arr, app);
	}
	else if ((ft_strncmp(*arr, "NO", 2) == 0) ||
	(ft_strncmp(*arr, "WE", 2) == 0) ||
	(ft_strncmp(*arr, "EA", 2) == 0) ||
	(ft_strncmp(*arr, "S", 2) == 0))
	{
		printf("modigicator is sprite\n");
		ft_parse_sprite(arr, app);
	}
	return(0);
}

int		parse_map(int fd, char *line, t_all *app)
{
	int		len;
	int		i = 0;
	char	**arr;
	
	while ((len = get_next_line(fd ,&line)))
	{
		// printf("-------------%s------------\n", line);
		if (line[0] != '\0')
		{
			arr = ft_split(line, ' ');
			ft_is_modificator(arr, app);
			printf("%d", app->map_ptr.count_mod);
		}
		free(line);
	}
	return (len);
}

int main(int argc, char **argv)
{
    t_all   app;
    int     len;
	char	*line;
	int fd;

	if (argc == 2 || argc == 3)
		if (!(fd = open(argv[1], O_RDONLY)))
			print_error(1);
	init_values(&app);
	len = parse_map(fd, line, &app);
//    app.mlx = mlx_init();
//    app.win = mlx_new_window(app.mlx, app.map_ptr.R[0], app.map_ptr.R[1], "cub3d");
//
//    mlx_key_hook(app.win, press_key, app.mlx);
//    mlx_loop(app.mlx);

}
