/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:46:43 by guderram          #+#    #+#             */
/*   Updated: 2022/06/15 15:24:34 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_vc_add(w_point *w, double d) // rajoute les zones de calculs au point en question
{
	printf("ft_vc_add : x %f y %f\n", w->ca->hx, w->ca->hy);
	if (d < 90)
	{
		w->ca->hs = w->ca->hs + w->ca->vcs;
		w->ca->hx = w->ca->hx + w->ca->vcx;
		w->ca->hy = w->ca->hy - w->ca->vcy;
	}
	printf("ft_vc_add : x %f y %f\n", w->ca->hx, w->ca->hy);
}

void	ft_vc_pytha(w_point *w, double d)
{
	double	x;
	double	y;
	
	printf("ft_vc_pytha : d %f\n", d);
	if (d < 90)
	{
		y = 1;
		// printf("ft_first_vc_pytha : x %f\n", d);
		x = y * tan(ft_degrees_to_radian(d));
		w->ca->vcx = x;
		w->ca->vcy = y;
	}
	w->ca->vcs = ft_ret_range(x, y, 0, 0);
	printf("ft_vc_pytha : x %f y %f x %f y %f\n", x, y, w->ca->fvcx, w->ca->fvcy);
}

void	ft_first_vc_pytha(w_point *w, double d)
{
	double	x;
	double	y;

	printf("ft_first_vc_pytha : d %f\n", d);
	if (d < 90)
	{
		// y = ((double)w->pos_y / 100);
		// x = y * tan(ft_degrees_to_radian(d));

		x = 1 - ((double)w->pos_x / 100);
		y = x / tan(ft_degrees_to_radian(d));
		w->ca->fvcx = w->ca->fvcx + x;
		w->ca->fvcy = w->ca->fvcy - y; // gestion de y avec la premiere ligne
	}
	printf("ft_first_vc_pytha : x %f y %f x %f y %f\n", x, y, w->ca->fvcx, w->ca->fvcy);
}

void	ft_first_vc(w_point *w, double d)
{
	w->ca->fvcx = w->ca->x;
	w->ca->fvcy = w->ca->y;
	if (d <= 90) // vers le haut
		ft_first_vc_pytha(w, d);
}

double	ft_while_vc(w_point *w, double d)
{
	int	i = 0;
	printf("ft_while_vc : ENTREE\n");
	ft_first_vc(w, d);
	ft_vc_pytha(w, d);
	w->ca->hs = w->ca->fvcs;
	w->ca->hx = w->ca->fvcx;
	w->ca->hy = w->ca->fvcy;
	while (ft_is_wall(w->map, w->ca->hx, w->ca->hy - 1) == 0 && w->ca->hs  < 10000 && i < 10000)
	{
		ft_vc_add(w, d);
		i++;
	}
	printf("ft_while_vc : i %d\n", i);
	printf("ft_while_vc : x %f y %f\n", w->ca->hx, w->ca->hy);
	return (ft_ret_range(w->ca->hx, w->ca->hy, w->ca->x, w->ca->y) * 100);
}
