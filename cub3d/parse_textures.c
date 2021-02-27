#include "cub3d.h"

void    parse_no_tex(t_all *app, char **arr)
{
        (app->map_ptr.n_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.n_i = 1);
		!((open((app->tex.no.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong NO fd") : 0;
}
void    parse_we_tex(t_all *app, char **arr)
{
    (app->map_ptr.w_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.w_i = 1);
	!((open((app->tex.we.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong WE fd") : 0;
}

void    parse_ea_tex(t_all *app, char **arr)
{
    (app->map_ptr.e_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.e_i = 1);
	!((open((app->tex.ea.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong EA fd") : 0;
}

void    parse_so_tex(t_all *app, char **arr)
{
    (app->map_ptr.so_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.so_i = 1);
    !((open((app->tex.so.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong SO fd") : 0;
}

void    parse_s_tex(t_all *app, char **arr)
{
    (app->map_ptr.s_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.s_i = 1);
	!((open((app->tex.s.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong S fd") : 0;
}