#include "cub3d.h"

int		ft_is_modificator(char **arr, t_all *app)
{

	if ((ft_strncmp(*arr, "R ", 2)))
	{
		ft_parse_R(arr, app);
		// printf("%d",app->map_ptr.count_mod);
	}
	else if ((ft_strncmp(*arr, "F ", 2) || ft_strncmp(*arr, "C ", 2)))
		return (2);
	return(0);
}

int		parse_map(int fd, char *line, t_all *app)
{
	int		len;
	int		i = 0;
	char	**arr;
	
	// while ((len = get_next_line(fd ,&line)))
	// {
		len = get_next_line(fd ,&line);
		arr = ft_split(line, ' ');
		ft_is_modificator(arr, app);
		// 	arr = ft_split(line, ',');
	// }
	return (len);
}

int main(int argc, char **argv)
{
    t_all   app;
    int     len;
	char	*line;
	int fd;

	if (argc >= 2 || argc <= 3)
	if (!(fd = open(argv[1], O_RDONLY)) && !(fd > 0))
		print_error(1);
	init_values(&app);
	len = parse_map(fd, line, &app);
    app.mlx = mlx_init();
    app.win = mlx_new_window(app.mlx, app.map_ptr.R[0], app.map_ptr.R[1], "cub3d");

    mlx_key_hook(app.win, press_key, app.mlx);
    mlx_loop(app.mlx);

}
