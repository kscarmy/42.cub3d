/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2022/07/30 13:07:58 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_entry_keyboard(int key, void *p)
{
	w_point	*win;

	win = p;
	printf("key : %d\nPos_X : %d\nPos_Y : %d\nX : %d\nY : %d\nD : %d\n",
		key, win->pos_x, win->pos_y, win->x, win->y, (int) win->d);
	if (key == KEY_ECHAP || key == MAC_KEY_ECHAP)
	{
		exit(0);
	}
	if (key == KEY_MOVE_FRONT || key == KEY_MOVE_LEFT
		|| key == KEY_MOVE_RIGHT || key == KEY_MOVE_BACK
		|| key == KEY_ROTATE_LEFT || key == KEY_ROTATE_RIGHT
		|| key == MAC_KEY_MOVE_FRONT || key == MAC_KEY_MOVE_LEFT
		|| key == MAC_KEY_MOVE_RIGHT || key == MAC_KEY_MOVE_BACK
		|| key == MAC_KEY_ROTATE_LEFT || key == MAC_KEY_ROTATE_RIGHT)
	{
		ft_move_zqsd(key, win);
		mlx_clear_window(win->mlx, win->win1);
		ft_screen(win);
	}
	return (0);
}
