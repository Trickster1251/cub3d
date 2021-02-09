#ifndef CUB3D
# define CUB3D
# define SCALE 10

typedef struct	s_win //структура для окна
{
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
}				  t_win;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				  t_point;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				  t_plr;

typedef struct	s_map
{
	int		R_init;
	int		F_init;
	int		C_init;
	int		NO_init;
	int		WE_init;
	int		EA_init;
	int		S_init;
	int		SO_init;
	int		R[2];
	int		F;
	int		C;
    char    *NO;
	char    *WE;
	char    *EA;
	char    *S;
	char    *SO;
    int     count_mod;
}				  t_map;


typedef struct	s_all // структура для всего вместе
{
	t_win		*win;
	t_plr		*plr;
    void		*mlx;
	void		*win_ptr;
	t_map		map_ptr;
	char		**map;
}				  t_all;

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include "../mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

void		print_error(char *string);
int         press_key(int keycode, void* win_ptr);
char	    *to_word(char **str, char sym, int num);
void		free_arr(char **arr);
void        init_values(t_all *app, t_point *point);
int		    ft_parse_R(char **arr, t_all *app);
int		    ft_parse_F_C(char **arr, t_all *app);
int		ft_parse_sprite(char **arr, t_all *app, int type);
int		array_len(char **arr, int num);
int		ft_isdigit_str(char *str);
void	make_map(t_all *app,t_list **head, int size);
int 	validator(t_all *app ,t_list **head);
#endif