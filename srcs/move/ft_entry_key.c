/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2022/08/12 14:04:40 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_cross_is_red(void *p)
{
	w_point	*win;

	win = p;
	ft_exit_free_all(win, 0);
	exit(0);
	return (0);
}

int	ft_entry_keyboard(int key, void *p)
{
	w_point	*win;

	win = p;
	printf("key : %d\n", key);
	if (key == KEY_ECHAP)
	{
		ft_exit_free_all(win, 0);
		exit(0);
	}
	if (key == KEY_MOVE_FRONT
		|| key == KEY_MOVE_LEFT
		|| key == KEY_MOVE_RIGHT
		|| key == KEY_MOVE_BACK
		|| key == KEY_ROTATE_LEFT
		|| key == KEY_ROTATE_RIGHT)
	{
		ft_move_zqsd(key, win);
		mlx_clear_window(win->mlx, win->win1);
		ft_screen(win);
	}
	return (0);
}
