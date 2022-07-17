/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:21:44 by guderram          #+#    #+#             */
/*   Updated: 2022/07/17 03:26:25 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_hc_add(w_point *w, double d) // rajoute les zones de calculs au point en question
{
	if (d < 90)
	{
		w->ca->hs = w->ca->hs + w->ca->hcs;
		w->ca->hx = w->ca->hx + w->ca->hcx;
		w->ca->hy = w->ca->hy - w->ca->hcy;
	}
	if (d > 270)
	{
		w->ca->hs = w->ca->hs + w->ca->hcs;
		w->ca->hx = w->ca->hx - w->ca->hcx;
		w->ca->hy = w->ca->hy - w->ca->hcy;
	}
}

void	ft_hc_pytha(w_point *w, double d)
{
	double	x;
	double	y;
	
	x = 0;
	y = 0;
	if (d < 90 || d > 270)
	{
		y = 1;
		x = y * tan(ft_degrees_to_radian(d));
		w->ca->hcx = x;
		w->ca->hcy = y;
	}
	w->ca->hcs = ft_ret_range(x, y, 0, 0);
}

void	ft_first_hc_pytha(w_point *w, double d)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	if (d < 90)
	{
		y = ((double)w->pos_y / 100);
		x = y * tan(ft_degrees_to_radian(d));
		w->ca->fhcx = w->ca->fhcx + x;
		w->ca->fhcy = w->ca->fhcy - y; // gestion de y avec la premiere ligne
	}
	if (d > 270)
	{
		y = ((double)w->pos_y / 100);
		x = y * tan(ft_degrees_to_radian(d));
		w->ca->fhcx = w->ca->fhcx - x;
		w->ca->fhcy = w->ca->fhcy - y;
	}
}

void	ft_first_hc(w_point *w, double d)
{
	w->ca->fhcx = w->ca->x;
	w->ca->fhcy = w->ca->y;
	if (d < 90 || d > 270) // vers le haut
		ft_first_hc_pytha(w, d);
}

double	ft_while_hc(w_point *w, double d)
{
	int	i = 0;
	ft_first_hc(w, d);
	ft_hc_pytha(w, d);
	w->ca->hs = w->ca->fhcs;
	w->ca->hx = w->ca->fhcx;
	w->ca->hy = w->ca->fhcy;
	while (ft_is_wall(w->map, w->ca->hx	, w->ca->hy - 1) == 0 && w->ca->hy > 1 && w->ca->hs < 10000 && i < 10)
	{
		ft_hc_add(w, d);
		i++;
	}
	return (ft_ret_range(w->ca->hx, w->ca->hy, w->ca->x, w->ca->y) * 100);
}
