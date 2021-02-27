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

char	**ft_split1(char const *s, char c, char c1)
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

int		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		ft_255_or_0(int num)
{
	if (num > 255)
		print_error("Color modificator more then 255");
	else if (num < 0)
		print_error("Color modificator less then 0");
	return (num);
}

int		is_correct_num(char **arr, int i)
{
	while(arr[++i])
		if (!(ft_isdigit_str(arr[i])))
			return (0);
	return(1);
}

int		ft_parse_r(char **arr, t_all *app)
{
	(!array_len(arr, 2)) ? print_error("More array len") : (0);
	(app->map_ptr.r_i == 1) ?
	(print_error("R twice init")) : (app->map_ptr.r_i = 1);
	if (!is_correct_num(arr, 0))
		print_error("Enter correct symbols at resolution");
	((app->map_ptr.r[0] = my_atoi(*(arr + 1))) < 400) ? (app->map_ptr.r[0] = 400) : (0);
	((app->map_ptr.r[1] = my_atoi(*(arr + 2))) < 400) ? (app->map_ptr.r[1] = 400) : (0);
	((app->map_ptr.r[0] > 2560)) ? (app->map_ptr.r[0] = 2560) : (0);
	((app->map_ptr.r[1] > 1440)) ? (app->map_ptr.r[1] = 1440) : (0);
	app->map_ptr.count_mod += 1;
	printf("%s %d %d\n", *arr, app->map_ptr.r[0] , app->map_ptr.r[1]);
	return (0);
}

int		ft_parse_f_c(char **arr, t_all *app)
{	
	(!array_len(arr, 3)) ? print_error("More array len") : 0;
	if (**arr == 'F')
	{
		(app->map_ptr.f_i == 1) ? (print_error("F twice init")) : (app->map_ptr.f_i = 1);
		if (!is_correct_num((arr), 0))
			print_error("Enter correct symbols at F");
    	app->map_ptr.f = create_rgb(ft_255_or_0(ft_atoi(*(arr + 1))), ft_255_or_0(ft_atoi(*(arr + 2))), ft_255_or_0(ft_atoi(*(arr + 3))));
		printf("F %d\n", app->map_ptr.f);
	}
	else
	{
		(app->map_ptr.c_i == 1) ? (print_error("C twice init")) : (app->map_ptr.c_i = 1);
		if (!is_correct_num((arr), 0))
			print_error("Enter correct symbols at C");
		app->map_ptr.c = create_rgb(ft_255_or_0(ft_atoi(*(arr + 1))), ft_255_or_0(ft_atoi(*(arr + 2))), ft_255_or_0(ft_atoi(*(arr + 3))));
		printf("C %d\n", app->map_ptr.c);
	}
	printf("%s -->%s<---->%s<---->%s<--\n", *arr, *(arr + 1) , *(arr + 2), *(arr + 3));
	app->map_ptr.count_mod += 1;
	return (0);
}

int		ft_parse_sprite(char **arr, t_all *app, int type)
{
	(!array_len(arr, 1)) ? print_error("More array len") : 0;
	if (type == 'N')
	{
		(app->map_ptr.n_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.n_i = 1);
		!((open((app->tex.no.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong NO fd") : 0;
	}
	else if (type == 'W')
	{
		(app->map_ptr.w_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.w_i = 1);
		!((open((app->tex.we.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong WE fd") : 0;
	}
	else if (type == 'E')
	{
		(app->map_ptr.e_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.e_i = 1);
		!((open((app->tex.ea.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong EA fd") : 0;
	}
	else if (type == 'S')
	{
		(app->map_ptr.so_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.so_i = 1);
		!((open((app->tex.so.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong SO fd") : 0;
	}
	else if (type == 's')
	{
		(app->map_ptr.s_i == 1) ? (print_error("Sprite twice init")) : (app->map_ptr.s_i = 1);
		!((open((app->tex.s.path = ft_strdup(arr[1])), O_RDONLY)) > 0) ? print_error("Wrong S fd") : 0;
	}
	app->map_ptr.count_mod += 1;
	printf("%s %s\n", *arr, *(arr+1));
	return (0);
}

void ft_qsort (t_sprite	*arr, int left, int right)
{
    int i = left;
	int j = right;
    t_sprite	temp;
	t_sprite	pivot = arr[ (left+right)/2 ];

    while (i <= j)
    {
        while (arr[i].dist > pivot.dist) i++;
        while (arr[j].dist < pivot.dist) j--;

        if (i <= j)
        {
            if (arr[i].dist < arr[j].dist)
            {
                temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
            }

            i++; j--;
        }

    };

    if (left < j) ft_qsort (arr, left, j);
    if (i < right) ft_qsort (arr, i, right);
}

void		cast_sprite(t_all *app, double *sprite_dist)
{
	int		x;
	int		y;
	int		i;
	t_sprite		arr_sprite[app->tex.count_sprite];
	
	y = 0;
	i = 0;
	while(app->map[y])
	{
		x = 0;
		while(app->map[y][x])
		{
			if (app->map[y][x] == '2')
			{
				arr_sprite[i].x = x + 0.5;
				arr_sprite[i].y = y + 0.5;
				arr_sprite[i].dist = (app->plr.x - arr_sprite[i].x) * (app->plr.x - arr_sprite[i].x) + (app->plr.y - arr_sprite[i].y) * (app->plr.y - arr_sprite[i].y);
				i++;
			}
			x++;
		}
		y++;
	}
	ft_qsort(arr_sprite, 0, app->tex.count_sprite - 1);

	i = -1;
	while(++i <= app->tex.count_sprite)
	{
      double spriteX = arr_sprite[i].x - app->plr.x;
      double spriteY = arr_sprite[i].y - app->plr.y;
      double invDet = 1.0 / (app->plr.plane_x * app->plr.dir_y - app->plr.dir_x * app->plr.plane_y);
      double transformX = invDet * (app->plr.dir_y * spriteX - app->plr.dir_x * spriteY);
      double transformY = invDet * (-app->plr.plane_y * spriteX + app->plr.plane_x * spriteY);
      int spriteScreenX = (int)((app->map_ptr.r[0] / 2) * (1 + transformX / transformY));
      double spriteHeight = fabs((double)(app->map_ptr.r[0] / (transformY)));
      int drawStartY = -spriteHeight / 2 +app->map_ptr.r[1] / 2;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 +app->map_ptr.r[1] / 2;
      if(drawEndY >=app->map_ptr.r[1]) drawEndY =app->map_ptr.r[1] - 1;
      double spriteWidth = fabs(app->map_ptr.r[0] / (transformY));
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= app->map_ptr.r[0]) drawEndX = app->map_ptr.r[0] - 1;
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * app->tex.s.w / spriteWidth) / 256;
        if(transformY > 0 && stripe > 0 && stripe < app->map_ptr.r[0] && transformY < sprite_dist[stripe])
        for(int y = drawStartY; y < drawEndY; y++)
        {
         	int d = (y) * 256 - app->map_ptr.r[1] * 128 + spriteHeight * 128;
          	int texY = ((d * app->tex.s.h) / spriteHeight) / 256;
		  	int color = get_color(&app->tex.s, texX, texY);
        	if((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(app, stripe, y, color);
        }
      }
    }
}