/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:59:59 by walethea          #+#    #+#             */
/*   Updated: 2021/02/28 20:27:47 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keep_key(int keycode, t_all *a)
{
	(keycode == 13) ? (a->key.w = 0) : (0);
	(keycode == 123) ? (a->key.q = 0) : (0);
	(keycode == 1) ? (a->key.s = 0) : (0);
	(keycode == 0) ? (a->key.a = 0) : (0);
	(keycode == 2) ? (a->key.d = 0) : (0);
	(keycode == 124) ? (a->key.e = 0) : (0);
	return (0);
}

int		press_key(int keycode, t_all *a)
{
	(keycode == 13) ? (a->key.w = 1) : (0);
	(keycode == 123) ? (a->key.q = 1) : (0);
	(keycode == 1) ? (a->key.s = 1) : (0);
	(keycode == 124) ? (a->key.e = 1) : (0);
	(keycode == 0) ? (a->key.a = 1) : (0);
	(keycode == 2) ? (a->key.d = 1) : (0);
	(keycode == 53) ? exit(0) : (0);
	return (0);
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
	int		i;
	int		j;

	i = -1;
	j = -1;
	line = NULL;
	if (argc == 2 || argc == 3)
	{
		if ((ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0))
			print_error ("Wrong map extension");
		if ((fd = open(argv[1], O_DIRECTORY)) < 0)
		{
			if ((fd = open(argv[1], O_RDONLY)) < 0)
				print_error("This map is not exist");
		}
		else
			print_error("This is a directory, dumb litty!");
	}
	init_values(&app);
	(argc == 3) ? (app.srcsht = 1) : (0);
	parser(fd, line, &app);
	app.mlx = mlx_init();
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
