/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:19:52 by guderram          #+#    #+#             */
/*   Updated: 2022/08/12 14:20:07 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_pixel_ceiling(w_point *w, int i)
{
	w->str[i + 2] = w->map->fr;
	w->str[i + 1] = w->map->fg;
	w->str[i] = w->map->fb;
}

void	ft_put_pixel_floor(w_point *w, int i)
{
	w->str[i + 2] = w->map->cr;
	w->str[i + 1] = w->map->cg;
	w->str[i] = w->map->cb;
}

int	ft_get_centieme(double x)
{
	int	ret;

	x = x * 100;
	if (x < 0)
		ret = (int)x * -1;
	else
		ret = (int)x;
	ret = ret % 100;
	if (ret < 0 && ret > WALL_SIZE)
		ret = 0;
	return (ret);
}
