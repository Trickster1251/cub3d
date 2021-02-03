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
	else if (ft_strncmp(*arr, "S\0", 2) == 0)
		ft_parse_sprite(arr, app, 'S');
	else
		print_error("this modificator is not exist");
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
			// printf("\nThis is count-->%d\n", app->map_ptr.count_mod);
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
			print_error("Wrong fd");
	init_values(&app);
	len = parse_map(fd, line, &app);
//    app.mlx = mlx_init();
//    app.win = mlx_new_window(app.mlx, app.map_ptr.R[0], app.map_ptr.R[1], "cub3d");
//
//    mlx_key_hook(app.win, press_key, app.mlx);
//    mlx_loop(app.mlx);

}
