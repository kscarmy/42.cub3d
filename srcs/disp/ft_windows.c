/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:03:21 by guderram          #+#    #+#             */
/*   Updated: 2022/08/07 16:00:27 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_w(w_point *w, m_point *m)
{
	w->er = 0;
	printf("INIT win\n");
	w->mlx = mlx_init();
	if (!(w->mlx))
	{
		printf("Init mlx fail !\n");
		w->er = 1;
	}
	w->win1 = mlx_new_window(w->mlx, RES_X, RES_Y, "cub3d");
	if (!(w->win1))
	{
		printf("Init win fail !\n");
		w->er = 1;
	}
	mlx_clear_window(w->mlx, w->win1);
	w->pos_x = 50;
	w->pos_y = 50;
	w->x = 0;
	w->y = 0;
	w->map = m;
	w->dirx = 0;
	w->diry = 0;
	
	printf("INIT win ok\n");
	ft_found_worldspawn(w);
}

int	ft_is_worldspawn(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	return (0);
}

void	ft_found_worldspawn(w_point *w)
{
	ft_map_disp_pos(w);
	while (w->map->map[w->y] != NULL
		&& ft_is_worldspawn(w->map->map[w->y][w->x]) == 0)
	{
		while (w->map->map[w->y][w->x] != '\0'
			&& ft_is_worldspawn(w->map->map[w->y][w->x]) == 0)
		{
			w->x = w->x + 1;
		}
		if (ft_is_worldspawn(w->map->map[w->y][w->x]) == 0)
		{
			w->x = 0;
			w->y = w->y + 1;
		}
	}
	if (w->map->map[w->y][w->x] == 'N')
		w->d = 90;
	if (w->map->map[w->y][w->x] == 'E')
		w->d = 0;
	if (w->map->map[w->y][w->x] == 'S')
		w->d = 270;
	if (w->map->map[w->y][w->x] == 'W')
		w->d = 180;
}

void	ft_exit_free_all(w_point *w, int ret)
{
	printf("All is begin freeing\n");
	mlx_clear_window(w->mlx, w->win1);
	mlx_destroy_window(w->mlx, w->win1);
	ret = ret;
}

void	ft_windows(m_point *m)
{
	w_point	w;
	v_point	*v;
	h_point	*h;

	h = malloc(sizeof(h_point));
	v = malloc(sizeof(v_point));
	ft_init_w(&w, m);
	w.h = h;
	w.v = v;
	if (w.er > 0)
		ft_exit_free_all(&w, -1);
	printf("Pas d'erreur d'initialisation\n");
	ft_screen_init(&w);
	ft_screen(&w);
	// movement with key maintained
	mlx_hook(w.win1, 02, 1L<<0,  ft_entry_keyboard, &w);
	// movement at key press only
	// mlx_key_hook(w.win1, ft_entry_keyboard, &w);
	mlx_loop(w.mlx);
	ft_exit_free_all(&w, 0);
}
