/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:28:22 by guderram          #+#    #+#             */
/*   Updated: 2022/07/17 02:52:00 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../mlx/mlx.h"

void	ft_init_win(w_point *win, m_point *mapi, c_point *cal) // mapi = map
{
	win->error = 0;
	if (!(win->mlx = mlx_init()))
	{
		ft_printf("Init mlx fail !\n");
		win->error = 1;
	}
	if (!(win->win1 = mlx_new_window(win->mlx, mapi->rx, mapi->ry,"win1")))
	{
		ft_printf("Init win1 fail !\n");
		win->error = 1;
	}

	mlx_clear_window(win->mlx, win->win1);
	win->pos_x = 50;
	win->pos_y = 50;
	win->x = 0;
	win->y = 0;
	win->map = mapi;
	win->ca = cal;
	win->move_size = 10;
	win->d_size = 10;
	printf("INIT WIND\n");
	ft_found_worldspawn(win);
}

int		ft_is_worldspawn(char c)
{
	if (c == 'N')
		return(1);
	if (c == 'S')
		return(1);
	if (c == 'E')
		return(1);
	if (c == 'O')
		return(1);
	return(0);
}

void	ft_found_worldspawn(w_point *win)
{
	ft_map_disp_pos(win);

	while (win->map->map[win->x] != NULL
		&& ft_is_worldspawn(win->map->map[win->x][win->y]) == 0)
	{
        	while (win->map->map[win->x][win->y] != '\0'
			&& ft_is_worldspawn(win->map->map[win->x][win->y]) == 0)
			win->y = win->y + 1;
        
        if (ft_is_worldspawn(win->map->map[win->x][win->y]) == 0)
		{
			win->y = 0;
			win->x = win->x + 1;
		}
	}
	if (win->map->map[win->x][win->y] == 'N')
		win->d = 0;
	if (win->map->map[win->x][win->y] == 'E')
		win->d = 90;
	if (win->map->map[win->x][win->y] == 'S')
		win->d = 180;
	if (win->map->map[win->x][win->y] == 'O')
		win->d = 270;
}

void	ft_exit_free_all(w_point *win, int ret)
{
	ft_printf("All is begin freeing\n");
	mlx_clear_window(win->mlx, win->win1);
	mlx_destroy_window(win->mlx, win->win1);

	exit(ft_exit_free_map(win->map, ret));
}



void	ft_windows(m_point *map)
{
	w_point win; // déclaration strucure "win" pour windows
	c_point ca; // déclaration structure de calcul

	ft_init_win(&win, map, &ca);
	if (win.error > 0)
		ft_exit_free_all(&win, -1); // Free win et map puis exit(0);
	ft_screen(&win);
	mlx_key_hook(win.win1,ft_entry_keyboard,&win);

	mlx_loop(win.mlx);
	ft_exit_free_all(&win, 0);
}
