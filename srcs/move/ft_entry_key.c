/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/23 10:34:50 by guderram         ###   ########.fr       */
=======
/*   Updated: 2022/07/19 23:17:51 by mourdani         ###   ########.fr       */
>>>>>>> moves
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_entry_keyboard(int key, void *p)
{
	w_point	*win;

	win = p;
<<<<<<< HEAD
	printf("key : %d\nPos_X : %d\nPos_Y : %d\nX : %d\nY : %d\nD : %d\n",
		key, win->pos_x, win->pos_y, win->x, win->y, (int) win->d);
	if (key == KEY_ECHAP || key == MAC_KEY_ECHAP)
=======
	if (key == KEY_ECHAP)
>>>>>>> moves
	{
		exit(0);
	}
<<<<<<< HEAD
	if (key == KEY_MOVE_FRONT || key == KEY_MOVE_LEFT
		|| key == KEY_MOVE_RIGHT || key == KEY_MOVE_BACK
		|| key == KEY_ROTATE_LEFT || key == KEY_ROTATE_RIGHT
		|| key == MAC_KEY_MOVE_FRONT || key == MAC_KEY_MOVE_LEFT
		|| key == MAC_KEY_MOVE_RIGHT || key == MAC_KEY_MOVE_BACK
		|| key == MAC_KEY_ROTATE_LEFT || key == MAC_KEY_ROTATE_RIGHT)
=======
	if (key == KEY_MOVE_FRONT
		|| key == KEY_MOVE_LEFT
		|| key == KEY_MOVE_RIGHT
		|| key == KEY_MOVE_BACK
		|| key == KEY_ROTATE_LEFT
		|| key == KEY_ROTATE_RIGHT)
>>>>>>> moves
	{
		ft_move_zqsd(key, win);
		mlx_clear_window(win->mlx, win->win1);
	}
	return (0);
}
