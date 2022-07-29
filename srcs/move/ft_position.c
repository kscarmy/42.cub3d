/* ************************************************************************** */
<<<<<<< HEAD
/*																			*/
/*														:::	  ::::::::   */
/*   ft_position.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: guderram <guderram@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/06/14 13:30:43 by guderram		  #+#	#+#			 */
/*   Updated: 2022/07/18 17:14:34 by guderram		 ###   ########.fr	   */
/*																			*/
=======
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:30:43 by guderram          #+#    #+#             */
/*   Updated: 2022/07/19 23:20:40 by mourdani         ###   ########.fr       */
/*                                                                            */
>>>>>>> moves
/* ************************************************************************** */

#include "../../includes/cub3d.h"

<<<<<<< HEAD
void	ft_map_disp_pos(w_point *win)
{
	int	a;
	int	c;

	a = 0;
	c = 0;
	printf("pos : \n");
=======
// prints map.cub
void    ft_map_disp_pos(w_point *win)
{
	int a;
	int c;
	
	a = 0;
	c = 0;
	ft_printf("pos : \n");
>>>>>>> moves
	while (win->map->map[a] != NULL)
	{
		while (win->map->map[a][c] != '\0')
		{
<<<<<<< HEAD
			printf("\033[0m%c", win->map->map[a][c]);
			c++;
		}
		printf("\n");
=======
			ft_printf("\033[0m%c", win->map->map[a][c]);
			c++;
		}
		ft_printf("\n");
>>>>>>> moves
		c = 0;
		a++;
	}
}

void	ft_move_in_casa(w_point *win)
{
	if (win->pos_x >= 100)
	{
		win->pos_x = 0;
		win->x = win->x + 1;
	}
	if (win->pos_x < 0)
	{
		win->pos_x = 100 - MOVE_SIZE;
		win->x = win->x - 1;
	}
	if (win->pos_y >= 100)
	{
		win->pos_y = 0;
		win->y = win->y + 1;
	}
	if (win->pos_y < 0)
	{
		win->pos_y = 64 - MOVE_SIZE;
		win->y = win->y - 1;
	}
}

int	ft_move_zqsd(int key, w_point *win)
{
<<<<<<< HEAD
	if (key == KEY_MOVE_FRONT || key == MAC_KEY_MOVE_FRONT)
		win->pos_x = win->pos_x - MOVE_SIZE;
	if (key == KEY_MOVE_LEFT || key == MAC_KEY_MOVE_LEFT)
		win->pos_y = win->pos_y - MOVE_SIZE;
	if (key == KEY_MOVE_RIGHT || key == MAC_KEY_MOVE_RIGHT)
		win->pos_y = win->pos_y + MOVE_SIZE;
	if (key == KEY_MOVE_BACK || key == MAC_KEY_MOVE_BACK)
		win->pos_x = win->pos_x + MOVE_SIZE;
	if (win->pos_x > 100 || win->pos_x < 0
		|| win->pos_y > 100 || win->pos_y < 0)
		ft_move_in_casa(win);
	if (key == KEY_ROTATE_LEFT || key == MAC_KEY_ROTATE_LEFT)
		win->d = win->d - ANG_SIZE;
	if (key == KEY_ROTATE_RIGHT || key == MAC_KEY_ROTATE_RIGHT)
=======
	if (key == KEY_ROTATE_LEFT)
		win->d = win->d - ANG_SIZE;
	else if (key == KEY_ROTATE_RIGHT)
>>>>>>> moves
		win->d = win->d + ANG_SIZE;
	if (win->d < 0)
		win->d = 360 - ANG_SIZE;
	else if (win->d >= 360)
		win->d = 0;
<<<<<<< HEAD
	return (0);
=======
	if (win->d == 0)
	{
		if (key == KEY_MOVE_FRONT)
			win->pos_y = win->pos_y + MOVE_SIZE;
		else if (key == KEY_MOVE_BACK)
			win->pos_y = win->pos_y - MOVE_SIZE;
		else if (key == KEY_MOVE_RIGHT)
			win->pos_x = win->pos_x + MOVE_SIZE;
		else if (key == KEY_MOVE_LEFT)
			win->pos_x = win->pos_x - MOVE_SIZE;
		if (win->pos_y > 100 || win->pos_y < 0 || win->pos_x > 100 || win->pos_x < 0)
			ft_move_in_casa(win);
	}
	else
	{
		if (key == KEY_MOVE_FRONT)
		{
			win->pos_y += find_y(win->d, MOVE_SIZE);
			win->pos_x += find_x(win->d, MOVE_SIZE);
		}
		else if (key == KEY_MOVE_BACK)
		{
			win->pos_y -= find_y(win->d, MOVE_SIZE);
			win->pos_x -= find_x(win->d, MOVE_SIZE);
		}
		else if (key == KEY_MOVE_LEFT)
		{
			win->pos_y += find_x(win->d, MOVE_SIZE);
			win->pos_x += find_y(win->d, MOVE_SIZE);
		}
		else if (key == KEY_MOVE_RIGHT)
		{
			win->pos_y -= find_x(win->d, MOVE_SIZE);
			win->pos_x -= find_y(win->d, MOVE_SIZE);
		}
		if (win->pos_y > 100 || win->pos_y < 0 || win->pos_x > 100 || win->pos_x < 0)
			ft_move_in_casa(win);
	}
	ft_printf("================\nkey : %d\nPos_X : %d\nPos_Y : %d\nX : %d\nY : %d\nD : %d\n"
		, key, win->pos_x, win->pos_y, win->x, win->y, (int) win->d);
	return(0);
>>>>>>> moves
}
