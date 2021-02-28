/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:59:47 by walethea          #+#    #+#             */
/*   Updated: 2021/02/28 18:40:25 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_values(t_all *app)
{
	app->m.r_i = 0;
	app->m.f_i = 0;
	app->m.n_i = 0;
	app->m.w_i = 0;
	app->m.e_i = 0;
	app->m.s_i = 0;
	app->m.so_i = 0;
	app->m.count_mod = 0;
	app->plr.x = 0;
	app->plr.y = 0;
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
	app->plr_init = 0;
	app->side = 0;
	app->tex.ea.path = 0;
	app->tex.no.path = 0;
	app->tex.we.path = 0;
	app->tex.so.path = 0;
	app->tex.s.path = 0;
	app->tex.count_sprite = 0;
	app->srcsht = 0;
}

int		only_spaces(char *str)
{
	while(*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int		is_valid_sym(char str)
{
	if (str == '1' || str == '0' || str == 'N' ||
	str == 'S' || str == 'E' || str == 'W' || str == '2')
		return (1);
	return (0);
}

int		is_valid_space(char str)
{
	if (str == '1' || str == '0' || str == 'N' || str == ' ' ||
	str == 'S' || str == 'E' || str == 'W' || str == '2')
		return (1);
	return (0);
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
	(app->m.count_mod >= 8) ? print_error("More modificators") : 0;
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
	else
		print_error("No modificator type, enter correct data");
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

int     is_valid_octa(t_all *app, int i, int j, char sym)
{
	if (i > 0 && !(is_valid_sym(app->map[i - 1][j]) &&
	is_valid_sym(app->map[i + 1][j]) && 
	is_valid_sym(app->map[i][j - 1]) &&
	is_valid_sym(app->map[i + 1][j + 1]) &&
	is_valid_sym(app->map[i + 1][j - 1]) &&
	is_valid_sym(app->map[i - 1][j - 1]) &&
	is_valid_sym(app->map[i - 1][j + 1]) &&
	is_valid_sym(app->map[i][j + 1])
	))
	{
		printf("%s--->%c<----", app->map[i], app->map[i][j]);
		if (sym == '0')
			print_error("parse error, zero not closed");
		else
			print_error("parse error, sprite not closed");
	}
	return (1);
}

void	validator_map(t_all *app,t_list **head, int size)
{
	app->map = ft_calloc(size + 1,sizeof(char*));
	int		i = -1;
	int		j = 0;
	t_list	*tmp;
	
	tmp = *head;
	while(tmp)
	{
		if (tmp->content[0] != '\0')
			app->map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	while(app->map[++i])
		ft_putendl_fd(app->map[i], 1);
	i = -1;
	while(app->map[++i])
	{
		j = skip_space(app->map[i]);
		while(app->map[i][j])
		{
			if (!is_valid_space(app->map[i][j]))
				print_error("Not valid character");
			if ((i == (size - 1) && app->map[i][j] == '0')
			|| (i == 0 && app->map[i][j] == '0'))
				print_error("parse error, map not closed");
			else if ((i == (size - 1) && app->map[i][j] == '2')
			|| (i == 0 && app->map[i][j] == '2'))
				print_error("parse error, sprite not closed");
			else if (app->map[i][j] == '0')
				is_valid_octa(app, i, j, '0');
			else if (app->map[i][j] == '2')
				is_valid_octa(app, i, j, '2');
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
			j++;
		}
	}
	if (app->plr_init == 0)
		print_error("None player");
	ft_putendl_fd("---->SUCCESS<----\n", 1);
	ft_lstclear(head, &free);
}

int             parser(int fd, char *line, t_all *app)
{
	int		len;
	int		i = 0;
	char	**arr;
	t_list	*head = NULL;
	int flag = 0;

	while ((len = get_next_line(fd ,&line) > 0) && (app->m.count_mod < 8))
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
	printf("\nThis is count-->%d\n", app->m.count_mod);
	if (*line != '\0')
		ft_lstadd_back(&head, ft_lstnew(line));
	else
		free(line);
	while ((len = get_next_line(fd ,&line)) > 0)
	{
		if (line[0] == '\0' && flag == 1 && only_spaces(line))
			print_error("Empty line at the map");
		else if ((line[0] != '\0' || flag == 1) && !only_spaces(line))
		{
			flag = 1;
			ft_lstadd_back(&head, ft_lstnew(line));
		}
		else
			free(line);
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	validator_map(app ,&head, ft_lstsize(head));
	return (len);
}