/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:59:47 by walethea          #+#    #+#             */
/*   Updated: 2021/03/01 23:59:10 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_is_modificator(char **arr, t_all *app)
{
	(app->m.count_mod >= 8) ? print_error("More modificators") : 0;
	if ((ft_strncmp(*arr, "R\0", 2)) == 0)
		ft_parse_r(arr, app);
	else if ((ft_strncmp(*arr, "F\0", 2) == 0) ||
	(ft_strncmp(*arr, "C\0", 2)) == 0)
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
	return (0);
}

void	init_parser_values(t_all *app)
{
	app->tex.ea.path = 0;
	app->tex.no.path = 0;
	app->tex.we.path = 0;
	app->tex.so.path = 0;
	app->tex.s.path = 0;
	app->tex.c_spr = 0;
	app->m.r_i = 0;
	app->m.f_i = 0;
	app->m.n_i = 0;
	app->m.w_i = 0;
	app->m.e_i = 0;
	app->m.s_i = 0;
	app->m.so_i = 0;
	app->m.count_mod = 0;
}

void	init_player_values(t_all *app)
{
	app->plr.x = 0;
	app->plr.y = 0;
	app->plr.dir_x = 0;
	app->plr.dir_y = 0;
	app->plr.apple = 0;
	app->plr.pln_x = 0;
	app->plr.pln_y = 0;
	app->side_dst_x = 0;
	app->side_dist_y = 0;
	app->dlt_dst_x = 0;
	app->dlt_dst_y = 0;
	app->perp_wall_dist = 0;
	app->step_x = 0;
	app->step_y = 0;
	app->hit = 0;
	app->plr_init = 0;
	app->side = 0;
	app->srcsht = 0;
	app->ds.y = 0;
	app->ds.i = 0;
	app->ds.color = 0;
}

int		read_map(char *line, int fd, t_list *head, t_all *app)
{
	int		flag;
	int		len;

	flag = 0;
	len = 0;
	if (*line != '\0')
		ft_lstadd_back(&head, ft_lstnew(line));
	else
		free(line);
	while ((len = get_next_line(fd, &line)) > 0)
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
	validator_map(app, &head, ft_lstsize(head));
	return (len);
}

int		parser(int fd, char *line, t_all *app)
{
	int		len;
	int		i;
	char	**arr;
	t_list	*head;

	i = 0;
	head = NULL;
	while ((len = get_next_line(fd, &line) > 0) && (app->m.count_mod < 8))
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
	len += read_map(line, fd, head, app);
	return (len);
}
