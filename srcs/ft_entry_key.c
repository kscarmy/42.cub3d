/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2020/01/31 12:45:33 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_entry_keyboard(int key, void *p)
{
	w_point *win;

	win = p;
	ft_printf("key : %d\nPos_X : %d\nPos_Y : %d\nX : %d\nY : %d\nD : %d\n", key, win->pos_x, win->pos_y, win->x, win->y, (int) win->d);
	// ft_printf("test : %s\n", win->map->no);
	if (key == 65307)
	{
		ft_exit_free_all(win, 0);
		exit(0);
	}
	if (key == 122 || key == 113 || key == 115 || key == 100 || key == 65361 || key == 65363)
		ft_move_zqsd(key, win);
	



	return(0);
}