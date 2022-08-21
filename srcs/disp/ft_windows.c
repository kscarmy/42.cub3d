/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:03:21 by guderram          #+#    #+#             */
/*   Updated: 2022/08/21 08:06:12 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_w(t_w_point *w, t_m_point *m)
{
	w->er = 0;
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
	ft_xpm_file_to_image(w, m);
	ft_found_worldspawn(w);
	w->opti = 1;
	w->zoom = 100.;
	w->deg = (double)FOV_SIZE / (double)RES_X;
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

void	ft_found_worldspawn(t_w_point *w)
{
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

void	ft_exit_free_all(t_w_point *w, int ret)
{
	mlx_destroy_image(w->mlx, w->no);
	mlx_destroy_image(w->mlx, w->so);
	mlx_destroy_image(w->mlx, w->ea);
	mlx_destroy_image(w->mlx, w->we);
	mlx_destroy_image(w->mlx, w->screen);
	mlx_destroy_image(w->mlx, w->crossair);
	mlx_destroy_image(w->mlx, w->gun);
	mlx_destroy_image(w->mlx, w->hud);
	mlx_clear_window(w->mlx, w->win1);
	mlx_destroy_window(w->mlx, w->win1);
	mlx_destroy_display(w->mlx);
	free (w->v);
	free (w->h);
	free (w->c);
	free (w->mlx);
	ft_exit_free_map(w->map, ret);
	exit(ret);
}

void	ft_windows(t_m_point *m)
{
	t_w_point	w;
	t_v_point	*v;
	t_h_point	*h;
	t_c_point	*c;

	h = malloc(sizeof(t_h_point));
	v = malloc(sizeof(t_v_point));
	c = malloc(sizeof(t_c_point));
	w.h = h;
	w.v = v;
	w.c = c;
	ft_init_w(&w, m);
	if (w.er > 0)
		ft_exit_free_all(&w, -1);
	ft_screen_init(&w);
	ft_screen(&w);
	mlx_hook(w.win1, 17, 0, &ft_cross_is_red, &w);
	mlx_hook(w.win1, 02, 1L << 0, ft_entry_keyboard, &w);
	mlx_loop(w.mlx);
	ft_exit_free_all(&w, 0);
}
