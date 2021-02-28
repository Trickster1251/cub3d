#include "cub3d.h"

static int		count_word(char *str, char sym, char sym1)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	if (sym == 0)
		return (1);
	while (*str)
	{
		if (*str != sym && *str != sym1 && i == 0)
		{
			count++;
			i = 1;
		}
		if ((*str == sym || *str == sym1) && i == 1)
			i = 0;
		str++;
	}
	return (count);
}

static char	**free_all(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	*malloc_word(const char *src, char sym, char sym1)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (src[len] != sym && src[len] != sym1 && src[len] != '\0')
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (src[i] && i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_split_new(char const *s, char c, char c1, char **words)
{
	int		j;

	j = 0;
	while (*s)
	{
		while (*s && (*s == c || *s == c1))
			s++;
		if (*s && *s != c && *s != c1)
		{
			if (!(words[j] = malloc_word(s, c, c1)))
				return (free_all(words));
			j++;
			while (*s && (*s != c && *s != c1))
				s++;
		}
	}
	words[j] = NULL;
	return (words);
}

char	**ft_split_colon(char const *s, char c, char c1)
{
	char	**words;
	int		col_words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	col_words = count_word((char*)s, c, c1);
	if (!(words = (char**)malloc((sizeof(char*) * (col_words + 1)))))
		return (NULL);
	return (ft_split_new(s, c, c1, words));
}

int             get_color(t_img *tex, int x, int y)
{
    char    *dst;
    int     color;
    dst = tex->addr + (y * tex->line_l + x * (tex->bpp / 8));
    color =	*(unsigned int*)dst;
    return (color);
}

void    get_texture(t_all *all, int side)
{
    // 1 = so 0 = no 2 = ea 3 = we
    if (side == 0)
    {
        if (all->step_x > 0)
            all->color = get_color(&all->tex.so, all->tex_x, all->tex_y);
        else
            all->color = get_color(&all->tex.no, all->tex_x, all->tex_y);
    }
    else
    {
        if (all->step_y > 0)
            all->color = get_color(&all->tex.we, all->tex_x, all->tex_y);
        else
            all->color = get_color(&all->tex.ea, all->tex_x, all->tex_y);
    }

}

void            my_mlx_pixel_put(t_all *app, int x, int y, int color)
{
    char    *dst;
    dst = app->img.addr + (y * app->img.line_len + x * (app->img.bpp / 8));
    *(unsigned int*)dst = color;
}

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

char	**free_arr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void		print_error(char *string)
{
    ft_putendl_fd("Error:", 1);
	ft_putendl_fd(string, 1);
	exit(0);
}
int		array_len(char **arr, int num)
{
	while(*(arr++) && *arr != '\0')
		num--;
	return (num == 0) ? (1) : (0);
}