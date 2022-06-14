/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2022/06/14 16:47:38 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_entry_keyboard(int key, void *p)
{
	w_point *win;

	win = p;
	ft_printf("key : %d\nPos_X : %d\nPos_Y : %d\nX : %d\nY : %d\nD : %d\n", key, win->pos_x, win->pos_y, win->x, win->y, (int) win->d);
	// ft_printf("test : %s\n", win->map->no);
	if (key == KEY_ECHAP)
	{
		ft_exit_free_all(win, 0);
		exit(0);
	}
	if (key == KEY_MOVE_FRONT || key == KEY_MOVE_LEFT || key == KEY_MOVE_RIGHT || key == KEY_MOVE_BACK || key == KEY_ROTATE_LEFT || key == KEY_ROTATE_RIGHT)
	{
		ft_move_zqsd(key, win);
		mlx_clear_window(win->mlx, win->win1);
		ft_reset_ca(win);
		ft_screen(win); // affiche les déplacements
	}
	return (0);
}
