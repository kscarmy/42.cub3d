/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:21:44 by guderram          #+#    #+#             */
/*   Updated: 2022/06/15 15:23:47 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_hc_add(w_point *w, double d) // rajoute les zones de calculs au point en question
{
	printf("ft_hc_add : x %f y %f\n", w->ca->hx, w->ca->hy);
	if (d < 90)
	{
		w->ca->hs = w->ca->hs + w->ca->hcs;
		w->ca->hx = w->ca->hx + w->ca->hcx;
		w->ca->hy = w->ca->hy - w->ca->hcy;
	}
	printf("ft_hc_add : x %f y %f\n", w->ca->hx, w->ca->hy);
}

void	ft_hc_pytha(w_point *w, double d)
{
	double	x;
	double	y;
	
	printf("ft_hc_pytha : d %f\n", d);
	if (d < 90)
	{
		y = 1;
		// printf("ft_first_hc_pytha : x %f\n", d);
		x = y * tan(ft_degrees_to_radian(d));
		w->ca->hcx = x;
		w->ca->hcy = y;
	}
	w->ca->hcs = ft_ret_range(x, y, 0, 0);
	printf("ft_hc_pytha : x %f y %f x %f y %f\n", x, y, w->ca->fhcx, w->ca->fhcy);
}

void	ft_first_hc_pytha(w_point *w, double d)
{
	double	x;
	double	y;

	printf("ft_first_hc_pytha : d %f\n", d);
	if (d < 90)
	{
		y = ((double)w->pos_y / 100);
		// printf("ft_first_hc_pytha : x %f\n", d);
		x = y * tan(ft_degrees_to_radian(d));
		w->ca->fhcx = w->ca->fhcx + x;
		w->ca->fhcy = w->ca->fhcy - y; // gestion de y avec la premiere ligne
	}
	printf("ft_first_hc_pytha : x %f y %f x %f y %f\n", x, y, w->ca->fhcx, w->ca->fhcy);
}

void	ft_first_hc(w_point *w, double d)
{
	w->ca->fhcx = w->ca->x;
	w->ca->fhcy = w->ca->y;
	if (d <= 90) // vers le haut
		ft_first_hc_pytha(w, d);
}

double	ft_while_hc(w_point *w, double d)
{
	int	i = 0;
	printf("ft_while_hc : ENTREE\n");
	ft_first_hc(w, d);
	ft_hc_pytha(w, d);
	w->ca->hs = w->ca->fhcs;
	w->ca->hx = w->ca->fhcx;
	w->ca->hy = w->ca->fhcy;
	while (ft_is_wall(w->map, w->ca->hx, w->ca->hy - 1) == 0 && w->ca->hs  < 10000 && i < 10000)
	{
		ft_hc_add(w, d);
		i++;
	}
	printf("ft_while_hc : i %d\n", i);
	printf("ft_while_hc : x %f y %f\n", w->ca->hx, w->ca->hy);
	return (ft_ret_range(w->ca->hx, w->ca->hy, w->ca->x, w->ca->y) * 100);
}
