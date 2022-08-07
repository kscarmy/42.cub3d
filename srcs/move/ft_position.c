/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:30:43 by guderram          #+#    #+#             */
/*   Updated: 2022/08/07 09:52:18 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_map_disp_pos(w_point *win)
{
	int	a;
	int	c;

	a = 0;
	c = 0;
	printf("pos : \n");
	while (win->map->map[a] != NULL)
	{
		while (win->map->map[a][c] != '\0')
		{
			printf("\033[0m%c", win->map->map[a][c]);
			c++;
		}
		printf("\n");
		c = 0;
		a++;
	}
}

void	ft_move_in_casa(w_point *win)
{
	if (win->pos_x >= WALL_SIZE)
	{
		win->pos_x = 0;
		win->x = win->x + 1;
	}
	else if (win->pos_x < 0)
	{
		win->pos_x = WALL_SIZE - MOVE_SIZE;
		win->x = win->x - 1;
	}
	if (win->pos_y >= WALL_SIZE)
	{
		win->pos_y = 0;
		win->y = win->y + 1;
	}
	else if (win->pos_y < 0)
	{
		win->pos_y = WALL_SIZE - MOVE_SIZE;
		win->y = win->y - 1;
	}
}
// void	rotate(int key, w_point *win)

void	rotate(int key, w_point *win)
{
	if (key == KEY_ROTATE_LEFT)
		win->d = win->d + ANG_SIZE;
	else if (key == KEY_ROTATE_RIGHT)
		win->d = win->d - ANG_SIZE;
	if (win->d < 0)
		win->d = 360 - ANG_SIZE;
	else if (win->d >= 360)
		win->d = 0;
}

void	zqsd(int key, w_point *win)
{
	if (key == KEY_MOVE_FRONT)
	{
		printf("JEAN %d ", win->pos_y);
		win->pos_y += (find_y(win->d, MOVE_SIZE) * win->diry);
		win->pos_x += (find_x(win->d, MOVE_SIZE) * win->dirx);
		// win->pos_y -= MOVE_SIZE;
		printf("JEAN %d\n", win->pos_y);
	}
	else if (key == KEY_MOVE_BACK)
	{
		win->pos_y += (find_y(win->d, MOVE_SIZE) * win->diry);
		win->pos_x += (find_x(win->d, MOVE_SIZE) * win->dirx);
	}
	else if (key == KEY_MOVE_LEFT)
	{
		win->pos_y += (find_x(win->d, MOVE_SIZE) * win->diry);
		win->pos_x += (find_y(win->d, MOVE_SIZE) * win->dirx);
	}
	else if (key == KEY_MOVE_RIGHT)
	{
		win->pos_y += (find_x(win->d, MOVE_SIZE) * win->diry);
		win->pos_x += (find_y(win->d, MOVE_SIZE) * win->dirx);
	}
}

int		ft_move_zqsd(int key, w_point *win)
{
	if (win->d <= 180) // vers le haut donc y decremente
		win->diry = -1;
	else // vers le bas donc y incremente
		win->diry = 1;

	if (win->d >= 90 && win->d <= 270) // vers la gauche donc x decremente
		win->dirx = -1;
	else // vers la droite donc x incremente
		win->dirx = 1;
	rotate(key, win);
	zqsd(key, win);	
	if (win->pos_y > WALL_SIZE
		|| win->pos_y < 0
		|| win->pos_x > WALL_SIZE
		|| win->pos_x < 0)
		ft_move_in_casa(win);
	
	printf("================\nkey : %d\nPos_X : %d\nPos_Y : %d\nX : %d\nY : %d\nD : %d\n"
		, key, win->pos_x, win->pos_y, win->x, win->y, (int) win->d);
	return (0);
}
