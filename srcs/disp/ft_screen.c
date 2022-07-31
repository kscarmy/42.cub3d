/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:52:57 by guderram          #+#    #+#             */
/*   Updated: 2022/07/31 11:56:39 by guderram         ###   ########.fr       */
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

void	ft_screen(w_point *w)
{
	double	i;
	int		max;
	double	r;
	double	d;

	i = 0;
	r = 100000;
	max = 0;
	d = (double)FOV_SIZE / (double)RES_X;
	while (i <= (RES_X / 2) && 1 < 5)
	{
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * i));
		ft_red_pixel(w, (w->sr * (double)WALL_SIZE) / r, (RES_X / 2) + i);
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * i * -1));
		ft_red_pixel(w, (w->sr * (double)WALL_SIZE) / r, (RES_X / 2) - i);
		i++;
		max++;
	}
	d = d;
	r = r;
	w = w;
}
