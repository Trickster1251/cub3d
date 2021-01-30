#ifndef CUB3D
# define CUB3D

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
	int		R[2];
	int		F[3];
    char    *NO;
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

# define SCALE 16 // условный размер каждого квадратика в карте
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

void		print_error(int errnum);
int         press_key(int keycode, void* win_ptr);
char	    *to_word(char **str, char sym, int num);
void        init_values(t_all *app);
int		ft_parse_R(char **arr, t_all *app);

#endif