/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:35:25 by walethea          #+#    #+#             */
/*   Updated: 2021/03/01 23:40:59 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10000
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char	**line);
char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);
size_t		ft_strlen_gnl(char *str);
char		*ft_strjoin_gnl(char *s1, const char *s2);
char		*ft_strdup_gnl(const char *src);
char		*ft_strchr_gnl(const char *str, int symbol);

#endif
