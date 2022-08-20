/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:52:57 by guderram          #+#    #+#             */
/*   Updated: 2022/08/20 10:37:01 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_screen_init(t_w_point *w)
{
	w->sr = 0;
	w->sr = (RES_X / 2) / tan(ft_degrees_to_radian(FOV_SIZE / 2));
	w->map->floor = (w->map->fr << 16) | (w->map->fg << 8) | w->map->fb;
	w->map->ceiling = (w->map->cr << 16) | (w->map->cg << 8) | w->map->cb;
	w->time = ft_get_time();
	w->i = 0;
	w->fps = 0;
}

void	ft_screen_bis(t_w_point *w, double i, double r, double d)
{
	char	*fps;

	fps = NULL;
	if (RES_X % 2 == 0)
	{
		if (i + w->opti < (RES_X / 2))
			i = i + w->opti;
		else
			i = i + (w->opti + (RES_X / 2) - (i + w->opti));
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * -i));
		if (w->or == 1)
			r = r * cos(ft_degrees_to_radian(d * i));
		else
			r = r * sin(ft_degrees_to_radian(90. + (d * i)));
		ft_opti(w, (w->sr * (double)WALL_SIZE) / r, i * -1);
	}
	ft_put_crossair(w);
	mlx_put_image_to_window(w->mlx, w->win1, w->screen, 0, 0);
	ft_init_fps(w);
	fps = ft_itoa(w->fps);
	mlx_string_put(w->mlx, w->win1, 10, 10, 16572163, fps);
	free (fps);
}

void	ft_opti(t_w_point *w, int h, int x)
{
	int	i;

	i = 0;
	if (x == 0)
	{
		while (x < w->opti)
		{
			ft_red_pixel(w, h, (RES_X / 2) + x);
			ft_red_pixel(w, h, (RES_X / 2) - x);
			x++;
		}
	}
	while (i < w->opti && x < (RES_X / 2))
	{
		ft_red_pixel(w, h, (RES_X / 2) + x);
		if (x >= 0)
			x++;
		else
			x--;
		i++;
	}
}

void	ft_screen(t_w_point *w)
{
	double	i;
	double	r;

	i = 0;
	while (i < (RES_X / 2))
	{
		r = ft_thales_range(w, ft_thales_angle_conv(w, w->deg * i * -1));
		if (w->or == 1)
			r = r * cos(ft_degrees_to_radian(w->deg * i * -1));
		else
			r = r * sin(ft_degrees_to_radian(90. + (w->deg * i * -1)));
		ft_opti(w, (w->sr * (double)WALL_SIZE) / r, i);
		r = ft_thales_range(w, ft_thales_angle_conv(w, w->deg * i));
		if (w->or == 1)
			r = r * cos(ft_degrees_to_radian(w->deg * i));
		else
			r = r * sin(ft_degrees_to_radian(90. + (w->deg * i)));
		ft_opti(w, (w->sr * (double)WALL_SIZE) / r, i * -1);
		if (i + w->opti < (RES_X / 2))
			i = i + w->opti;
		else
			i = i + (w->opti + (RES_X / 2) - (i + w->opti));
	}
	ft_screen_bis(w, i, r, w->deg);
}
