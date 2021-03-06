/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_colon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:10:43 by walethea          #+#    #+#             */
/*   Updated: 2021/03/02 01:17:02 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int		count_word(char *str, char sym, char sym1)
{
	int		i;
	int		count;

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

static char		**free_all(char **str)
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

static char		*malloc_word(const char *src, char sym, char sym1)
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

static char		**ft_split_new(char const *s, char c, char c1, char **words)
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

char			**ft_split_colon(char const *s, char c, char c1)
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
