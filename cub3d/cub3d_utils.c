#include "cub3d.h"

int		ft_isdigit_str(char *str)
{
	while(*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	init_values(t_all *app)
{
	app->map_ptr.R_init = 0;
	app->map_ptr.F_init = 0;
    app->map_ptr.count_mod = 0;
}

void		print_error(int errnum)
{
	(errnum == 1) ? ft_putendl_fd("fd is not available", 1)
	: (errnum == 2) ? ft_putendl_fd("R twice init", 1)
    : (errnum == 3) ? ft_putendl_fd("Modificator more or less 8", 1)
    : (errnum == 4) ? ft_putendl_fd("parse error with F", 1) : 0;
	exit(0);
}

int	press_key(int keycode, void* win_ptr)
{
	if (keycode == 53 || keycode == 12)
	{
		exit(0);
	}
	// printf("%d\n", keycode);
	return (0);
}

// char	*to_word(char **str, char sym, int num)
// {
// 	int			i;
// 	int			count;

// 	i = 0;
// 	count = 0;
// 	// if (sym == 0)
// 	// 	return (1);
// 	while (**str && count < num)
// 	{
// 		if (**str != sym && i == 0)
// 		{
// 			count++;
// 			i = 1;
// 		}
// 		if (**str == sym && i == 1)
// 			i = 0;
// 		*str++;
// 	}
// 	if (count == num)
// 		str--;
// 	return (str);
// }