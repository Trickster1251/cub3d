/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 05:00:05 by walethea          #+#    #+#             */
/*   Updated: 2021/03/04 23:46:09 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MS 0.1
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"
# include "../minilibx_mms/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"

typedef struct			s_draw_sprite
{
	double		spr_x;
	double		spr_y;
	double		inv_det;
	double		trn_x;
	double		trn_y;
	int			spr_scrn_x;
	int			spr_h;
	int			dr_end_y;
	int			spr_w;
	int			dr_srt_x;
	int			dr_end_x;
	int			tx_x;
	int			tx_y;
	int			stripe;
	int			i;
	int			y;
	int			color;
	int			dr_srt_y;
}						t_draw_spr;

typedef struct			s_img
{
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			endian;
	char		*path;
	int			w;
	int			h;
}						t_img;

typedef struct			s_sprite
{
	double			x;
	double			y;
	double			dist;
}						t_sprite;

typedef struct			s_texture
{
	t_img		no;
	t_img		we;
	t_img		ea;
	t_img		so;
	t_img		s;
	int			h;
	int			w;
	int			c_spr;
}						t_texture;

typedef struct			s_key
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			e;
	int			q;
	int			esc;
}						t_key;

typedef struct			s_plr
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		pln_x;
	double		pln_y;
	double		start;
	double		end;
	int			apple;
}						t_plr;

typedef struct			s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}						t_data;

typedef struct			s_map
{
	int			r_i;
	int			f_i;
	int			c_i;
	int			n_i;
	int			w_i;
	int			e_i;
	int			s_i;
	int			so_i;
	long		r[2];
	int			f;
	int			c;
	int			count_mod;
	int			c_colon;
}						t_map;

typedef struct			s_all
{
	t_img		*win;
	t_plr		plr;
	t_key		key;
	t_data		img;
	t_map		m;
	t_sprite	*ar_spr;
	t_texture	tex;
	t_draw_spr	ds;
	void		*mlx;
	int			ds_w;
	int			de_w;
	void		*win_ptr;
	char		**map;
	int			plr_init;
	int			srcsht;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			color;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			map_x;
	int			map_y;
	double		side_dst_x;
	double		side_dist_y;
	int			line_h;
	double		dlt_dst_x;
	double		dlt_dst_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}						t_all;

void					print_error(char *string);
void					ft_is_plr(t_all *app, char dir, int i, int j);
int						parser(int fd, char *line, t_all *app);
void					validator_map(t_all *app, t_list **head, int size);
int						press_key(int keycode, t_all *app);
int						keep_key(int keycode, t_all *a);
int						release_key(t_all *a);
char					*to_word(char **str, char sym, int num);
void					my_mlx_pixel_put(t_all *app, int x, int y, int color);
void					init_player_values(t_all *app);
int						ft_parse_r(char **arr, t_all *app);
int						ft_parse_f_c(char **arr, t_all *app);
int						ft_parse_sprite(char **arr, t_all *app, int type);
int						array_len(char **arr, int num);
int						ft_isdigit_str(char *str);
int						validator(t_all *app, t_list **head);
char					**free_arr(char **str);
void					init_textures(t_all *app);
void					get_texture(t_all *all, int side);
int						get_color(t_img *tex, int x, int y);
void					cast_sprite(t_all *app, double *sprite_dist);
void					render_bmp(t_all *all);
int						only_spaces(char *str);
char					**ft_split_colon(char const *s, char c, char c1);
void					parse_no_tex(t_all *app, char **arr);
void					parse_we_tex(t_all *app, char **arr);
void					parse_ea_tex(t_all *app, char **arr);
void					parse_so_tex(t_all *app, char **arr);
void					parse_s_tex(t_all *app, char **arr);
int						raycaster(t_all *app);
int						is_valid_sym(char str);
int						is_valid_space(char str);
int						ft_is_modificator(char **arr, t_all *app);
int						skip_space(char *str);
int						is_correct_num(char **arr, int i);
void					set_size_scrnsht(char **arr,
t_all *app, int max_res, int i);
int						is_valid_octa(t_all *app, int i, int j, char sym);
void					is_valid_0_2(t_all *app, int i, int j);
void					is_valid_map(t_all *app, int size);
void					validator_map(t_all *app, t_list **head, int size);
void					init_parser_values(t_all *app);
void					ft_qsort(t_sprite *arr,
int left, int right);
void					draw_sprite(t_all *app,
double *sprite_dist, t_sprite *arr_sprite);
void					calculate_step(t_all *a);
void					is_hit(t_all *a);
void					is_side_0(t_all *a);
void					what_side(t_all *a);
void					draw_wall(t_all *a, int i);
void					drawing(t_all *a);
void					init_ray_values(t_all *a, int i);
void					set_ds_de(t_all *a);

#endif
