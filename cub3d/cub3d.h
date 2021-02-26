#ifndef CUB3D
# define CUB3D
# define SCALE 10
# define MOVE_SPEED 0.1
# define MAX_RES_WIDTH 5120
# define MAX_RES_HEIGHT 2880

typedef struct	s_img //структура для окна
{
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			endian;
	char		*path;
	int			w;
	int			h;
}				  t_img;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			dist;
}					t_sprite;

typedef struct	s_texture //структура для окна
{
	t_img		no;
	t_img		we;
	t_img		ea;
	t_img		so;
	t_img		s;
	int			h;
	int			w;
	int			count_sprite;
}				  t_texture;


typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				  t_point;

typedef struct	s_key // структура для точки
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			e;
	int			q;
	int			esc;
}				  t_key;

typedef struct	s_plr //структура для игрока и луча
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		start;
	double		end;
}				  t_plr;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bpp;
    int         line_len;
    int         endian;
}               t_data;

typedef struct	s_map
{
	int		r_i;
	int		f_i;
	int		c_i;
	int		n_i;
	int		w_i;
	int		e_i;
	int		s_i;
	int		so_i;
	int		r[2];
	int		f;
	int		c;
    int     count_mod;
}				  t_map;




typedef struct	s_all // структура для всего вместе
{
	t_img		*win;
	t_plr		plr;
	t_key		key;
	t_data		img;
    void		*mlx;
	void		*win_ptr;
	t_map		map_ptr;
	char		**map;
	t_texture	tex;
	double 		camera_x;
    double 		ray_dir_x;
    double 		ray_dir_y;
	unsigned int	color;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			map_x;
    int			map_y;
    //length of ray from current position to next x or y-side
    double 		side_dist_x;
    double		side_dist_y;
	int			line_h;

     //length of ray from one x or y-side to next x or y-side
    double		delta_dist_x;
    double		delta_dist_y;
    double		perp_wall_dist;

    //what direction to step in x or y-direction (either +1 or -1)
    int 		step_x;
    int 		step_y;

 	int 		hit; //was there a wall hit?
    int 		side; //was a NS or a EW wall hit?
}				  t_all;

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include "../mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line/get_next_line.h"

void		print_error(char *string);
void		ft_is_plr(t_all *app, char dir, int i, int j);
int			parser(int fd, char *line, t_all *app);
void		validator_map(t_all *app,t_list **head, int size);
int			press_key(int keycode, t_all* app);
int			release_key(t_all* a);
char	    *to_word(char **str, char sym, int num);
void		my_mlx_pixel_put(t_all *app, int x, int y, int color);
void        init_values(t_all *app);
int		    ft_parse_r(char **arr, t_all *app);
int		    ft_parse_f_c(char **arr, t_all *app);
int			ft_parse_sprite(char **arr, t_all *app, int type);
int			array_len(char **arr, int num);
int			ft_isdigit_str(char *str);
int 		validator(t_all *app ,t_list **head);
char		**free_arr(char **str);
void    	init_textures(t_all *app);
void    	get_texture(t_all *all, int side);
int         get_color(t_img *tex, int x, int y);
void		cast_sprite(t_all *app, double *sprite_dist);

#endif