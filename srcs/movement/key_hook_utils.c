/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <walethea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:20:43 by walethea          #+#    #+#             */
/*   Updated: 2021/02/28 21:28:40 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		keep_key(int keycode, t_all *a)
{
	(keycode == 13) ? (a->key.w = 0) : (0);
	(keycode == 123) ? (a->key.q = 0) : (0);
	(keycode == 1) ? (a->key.s = 0) : (0);
	(keycode == 0) ? (a->key.a = 0) : (0);
	(keycode == 2) ? (a->key.d = 0) : (0);
	(keycode == 124) ? (a->key.e = 0) : (0);
	return (0);
}

int		press_key(int keycode, t_all *a)
{
	(keycode == 13) ? (a->key.w = 1) : (0);
	(keycode == 123) ? (a->key.q = 1) : (0);
	(keycode == 1) ? (a->key.s = 1) : (0);
	(keycode == 124) ? (a->key.e = 1) : (0);
	(keycode == 0) ? (a->key.a = 1) : (0);
	(keycode == 2) ? (a->key.d = 1) : (0);
	(keycode == 53) ? exit(0) : (0);
	return (0);
}
