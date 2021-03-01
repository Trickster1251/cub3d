/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:59:59 by walethea          #+#    #+#             */
/*   Updated: 2021/03/01 19:48:30 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_valid_file(int argc, char **argv, t_all *app)
{
	int		fd;

	fd = 0;
	if (argc == 2 || argc == 3)
	{
		if ((ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0))
			print_error("Wrong map extension");
		if ((fd = open(argv[1], O_DIRECTORY)) < 0)
		{
			if ((fd = open(argv[1], O_RDONLY)) < 0)
				print_error("This map is not exist");
		}
		else
			print_error("This is a directory, dumb litty!");
	}
	return (fd);
}

int		close_window(t_all *app)
{
	exit(0);
}

void	make_screenshot(int argc, char **argv, t_all *app)
{
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 7) == 0))
	{
		init_textures(app);
		raycaster(app);
		render_bmp(app);
	}
	else if (argc == 3)
		print_error("wrong flag argument, may be u mean \"--save\"");
}

int		main(int argc, char **argv)
{
	t_all	app;
	char	*line;
	int		fd;

	line = NULL;
	fd = is_valid_file(argc, argv, &app);
	init_player_values(&app);
	init_parser_values(&app);
	parser(fd, line, &app);
	app.mlx = mlx_init();
	(argc == 3) ? (app.srcsht = 1) : (0);
	if (argc == 3)
		make_screenshot(argc, argv, &app);
	app.win = mlx_new_window(app.mlx, app.m.r[0], app.m.r[1], "cub3d");
	init_textures(&app);
	mlx_hook(app.win, 2, 0, press_key, &app);
	mlx_hook(app.win, 3, 0, keep_key, &app);
	mlx_hook(app.win, 17, 0, close_window, &app);
	mlx_loop_hook(app.mlx, raycaster, &app);
	mlx_loop(app.mlx);
	return (0);
}
