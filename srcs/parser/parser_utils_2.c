/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:16:10 by walethea          #+#    #+#             */
/*   Updated: 2021/03/06 02:29:52 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		this_is_plr(char str)
{
	if (str == 'N' || str == 'W' || str == 'S' || str == 'E')
		return (1);
	return (0);
}

int		is_valid_octa_plr(t_all *a, int i, int j, char t)
{
	if ((j >= (int)ft_strlen(a->map[i - 1])) || (j >= (int)ft_strlen(a->map[i + 1])))
		print_error("player not closed");
	if (!(is_valid_sym(a->map[i - 1][j]) &&
	is_valid_sym(a->map[i + 1][j]) &&
	is_valid_sym(a->map[i][j - 1]) &&
	is_valid_sym(a->map[i + 1][j + 1]) &&
	is_valid_sym(a->map[i + 1][j - 1]) &&
	is_valid_sym(a->map[i - 1][j - 1]) &&
	is_valid_sym(a->map[i - 1][j + 1]) &&
	is_valid_sym(a->map[i][j + 1])))
		print_error("Player not close1d");
	ft_is_plr(a, t, i, j);
	return (1);
}

int		is_valid_octa_0_2(t_all *a, int i, int j)
{
	if (a->map[i][j] == '2')
		a->tex.c_spr++;
	if ((j >= (int)ft_strlen(a->map[i - 1])) || (j >= (int)ft_strlen(a->map[i + 1])))
		print_error("symbol not closed");
	if (!(is_valid_sym(a->map[i - 1][j]) &&
	is_valid_sym(a->map[i + 1][j]) &&
	is_valid_sym(a->map[i][j - 1]) &&
	is_valid_sym(a->map[i + 1][j + 1]) &&
	is_valid_sym(a->map[i + 1][j - 1]) &&
	is_valid_sym(a->map[i - 1][j - 1]) &&
	is_valid_sym(a->map[i - 1][j + 1]) &&
	is_valid_sym(a->map[i][j + 1])))
		print_error("symbol not closed");

	return (1);
}

void	is_valid(t_all *app, int i, int j)
{
	if (this_is_plr(app->map[i][j]))
		is_valid_octa_plr(app, i, j, app->map[i][j]);
	else if (app->map[i][j] == '2' || app->map[i][j] == '0')
			is_valid_octa_0_2(app, i, j);
}

void	is_valid_map(t_all *a, int size)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (a->map[++i])
	{
		j = skip_space(a->map[i]);
		while (a->map[i][j])
		{
			if (!is_valid_space(a->map[i][j]))
				print_error("Not valid character");
			if ((i == 0) && a->map[i][j] != '1' && a->map[i][j] != ' ')
				print_error("parse error, map not closed");
			if ((i == size - 1) && a->map[i][j] != '1' && a->map[i][j] != ' ')
				print_error("parse error, map not closed");
			if (i > 0 && i < (size - 1) && (a->map[i][j] != '1') && (a->map[i][j] != ' '))
				is_valid(a, i, j);
			j++;
		}
	}
	size += 1;
}

void	validator_map(t_all *app, t_list **head, int size)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = *head;
	app->map = ft_calloc(size + 1, sizeof(char*));
	while (tmp)
	{
		if (tmp->content[0] != '\0')
			app->map[++i] = tmp->content;
		tmp = tmp->next;
	}
	is_valid_map(app, size);
	if (app->plr_init == 0)
		print_error("None player");
	ft_putendl_fd("---->SUCCESS<----\n", 1);
	ft_lstclear(head, &free);
}

void	init_textures(t_all *app)
{
	if (!(app->tex.no.img = mlx_xpm_file_to_image(app->mlx,
	app->tex.no.path, &app->tex.no.w, &app->tex.no.h)))
		print_error("cannot open NO tex");
	if (!(app->tex.we.img = mlx_xpm_file_to_image(app->mlx,
	app->tex.we.path, &app->tex.we.w, &app->tex.we.h)))
		print_error("cannot open WE tex");
	if (!(app->tex.ea.img = mlx_xpm_file_to_image(app->mlx,
	app->tex.ea.path, &app->tex.ea.w, &app->tex.ea.h)))
		print_error("cannot open EA tex");
	if (!(app->tex.so.img = mlx_xpm_file_to_image(app->mlx,
	app->tex.so.path, &app->tex.so.w, &app->tex.so.h)))
		print_error("cannot open SO tex");
	if (!(app->tex.s.img = mlx_xpm_file_to_image(app->mlx,
	app->tex.s.path, &app->tex.s.w, &app->tex.s.h)))
		print_error("cannot open Sprite tex");
	app->tex.ea.addr = mlx_get_data_addr(app->tex.ea.img,
	&app->tex.ea.bpp, &app->tex.ea.line_l, &app->tex.ea.endian);
	app->tex.no.addr = mlx_get_data_addr(app->tex.no.img,
	&app->tex.no.bpp, &app->tex.no.line_l, &app->tex.no.endian);
	app->tex.we.addr = mlx_get_data_addr(app->tex.we.img,
	&app->tex.we.bpp, &app->tex.we.line_l, &app->tex.we.endian);
	app->tex.so.addr = mlx_get_data_addr(app->tex.so.img,
	&app->tex.so.bpp, &app->tex.so.line_l, &app->tex.so.endian);
	app->tex.s.addr = mlx_get_data_addr(app->tex.s.img,
	&app->tex.s.bpp, &app->tex.s.line_l, &app->tex.s.endian);
}
