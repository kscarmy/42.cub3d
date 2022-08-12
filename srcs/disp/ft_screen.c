/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:52:57 by guderram          #+#    #+#             */
/*   Updated: 2022/08/12 14:35:57 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_screen_init(w_point *w)
{
	w->sr = 0;
	w->sr = (RES_X / 2) / tan(ft_degrees_to_radian(FOV_SIZE / 2));
	w->map->floor = (w->map->fr << 16) | (w->map->fg << 8) | w->map->fb;
	w->map->ceiling = (w->map->cr << 16) | (w->map->cg << 8) | w->map->cb;
}

void	ft_swap_pos(w_point *w)
{
	int	a;
	int	b;

	a = w->x;
	b = w->pos_x;
	w->x = w->y;
	w->y = a;
	w->pos_x = w->pos_y;
	w->pos_y = b;
}

void	ft_screen_bis(w_point *w, double i, double r, double d)
{
	if (RES_X % 2 == 0)
	{
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * i));
		if (w->or == 1)
			r = r * cos(ft_degrees_to_radian(d * i));
		else
			r = r * sin(ft_degrees_to_radian(90. + (d * i)));
		ft_red_pixel(w, (w->sr * (double)WALL_SIZE) / r, (RES_X / 2) - i);
	}
	mlx_put_image_to_window(w->mlx, w->win1, w->screen, 0, 0);
}

void	ft_screen(w_point *w)
{
	double	i;
	double	r;
	double	d;

	i = 0;
	d = (double)FOV_SIZE / (double)RES_X;
	while (i < (RES_X / 2))
	{
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * i * -1));
		if (w->or == 1)
			r = r * cos(ft_degrees_to_radian(d * i * -1));
		else
			r = r * sin(ft_degrees_to_radian(90. + (d * i * -1)));
		ft_red_pixel(w, (w->sr * (double)WALL_SIZE) / r, (RES_X / 2) + i);
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * i));
		if (w->or == 1)
			r = r * cos(ft_degrees_to_radian(d * i));
		else
			r = r * sin(ft_degrees_to_radian(90. + (d * i)));
		ft_red_pixel(w, (w->sr * (double)WALL_SIZE) / r, (RES_X / 2) - i);
		i++;
	}
	ft_screen_bis(w, i, r, d);
}
