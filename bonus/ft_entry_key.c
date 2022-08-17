/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2022/08/17 16:51:04 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_cross_is_red(void *p)
{
	t_w_point	*win;

	win = p;
	ft_exit_free_all(win, 0);
	exit(0);
	return (0);
}

void	ft_bonus_key(int key, t_w_point *w)
{
	if (key == BONUS_KEY_ZOOM_IN
		|| key == BONUS_KEY_ZOOM_OUT)
	{
		if (key == BONUS_KEY_ZOOM_IN && w->zoom < 200.)
			w->zoom = w->zoom + 50.;
		else if (key == BONUS_KEY_ZOOM_OUT && w->zoom > 50.)
			w->zoom = w->zoom - 50.;
		ft_screen(w);
	}
	if (key == BONUS_KEY_TEXTURE_MORE
		|| key == BONUS_KEY_TEXTURE_LESS)
	{
		if (key == BONUS_KEY_TEXTURE_MORE && w->opti < 16)
			w->opti = w->opti + 1;
		else if (key == BONUS_KEY_TEXTURE_LESS && w->opti > 1)
			w->opti = w->opti - 1;
		ft_screen(w);
	}
}

int	ft_entry_keyboard(int key, void *p)
{
	t_w_point	*win;

	win = p;
	if (key == KEY_ECHAP)
	{
		ft_exit_free_all(win, 0);
		exit(0);
	}
	ft_bonus_key(key, win);
	if (key == KEY_MOVE_FRONT
		|| key == KEY_MOVE_LEFT
		|| key == KEY_MOVE_RIGHT
		|| key == KEY_MOVE_BACK
		|| key == KEY_ROTATE_LEFT
		|| key == KEY_ROTATE_RIGHT)
	{
		ft_move_zqsd(key, win);
		ft_screen(win);
	}
	return (0);
}
