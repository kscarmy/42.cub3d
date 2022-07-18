/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:46:43 by guderram          #+#    #+#             */
/*   Updated: 2022/07/17 14:00:55 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_vc_add(w_point *w, double d) // rajoute les zones de calculs au point en question
{
	if (d < 90)
	{
		w->ca->vs = w->ca->vs + w->ca->vcs;
		w->ca->vx = w->ca->vx + w->ca->vcx;
		w->ca->vy = w->ca->vy - w->ca->vcy;
	}
	if (d > 270)
	{
		w->ca->vs = w->ca->vs + w->ca->vcs;
		w->ca->vx = w->ca->vx - w->ca->vcx;
		w->ca->vy = w->ca->vy - w->ca->vcy;
	}
	w->ca->cr = w->ca->vs;
	w->ca->cx = w->ca->vx;
	w->ca->cy = w->ca->vy;
	// printf("ft_vc_add : x %f y %f\n", w->ca->vx, w->ca->vy);
}

void	ft_vc_pytha(w_point *w, double d)
{
	double	x;
	double	y;
	
	x = 0;
	y = 0;
	if (d < 90 || d > 270)
	{
		x = 1;
		y = x * tan(ft_degrees_to_radian(d));
		w->ca->vcx = x;
		w->ca->vcy = y;
	}
	w->ca->vcs = ft_ret_range(x, y, 0, 0);
}

void	ft_first_vc_pytha(w_point *w, double d)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	if (d < 90)
	{
		x = 1 - ((double)w->pos_x / 100);
		y = x / tan(ft_degrees_to_radian(d));

		w->ca->fvcx = w->ca->fvcx + x;
		w->ca->fvcy = w->ca->fvcy - y; // gestion de y avec la premiere ligne
		// printf("ft_first_vc_pytha : D %f : x %f y %f fvcx %f fvcy %f\n", d, x, y, w->ca->fvcx, w->ca->fvcy);
	}
	if (d > 270)
	{
		x = ((double)w->pos_x / 100);
		y = x / tan(ft_degrees_to_radian(d));
		w->ca->fvcx = w->ca->fvcx - x;
		w->ca->fvcy = w->ca->fvcy - y; // gestion de y avec la premiere ligne
	}
}

void	ft_first_vc(w_point *w, double d)
{
	w->ca->fvcx = w->ca->x;
	w->ca->fvcy = w->ca->y;
	if (d > 270 || d < 90) // vers le haut
		ft_first_vc_pytha(w, d);
}

double	ft_while_vc(w_point *w, double d)
{
	// printf("\n");
	// printf("ft_while_vc : entree\n");

	ft_first_vc(w, d);
	ft_vc_pytha(w, d);
	// printf("ft_while_vc : fvcx %f fvcy %f : vcx %f vcy %f \n", w->ca->fvcx, w->ca->fvcy, w->ca->vcx, w->ca->vcy);
	// printf("ft_while_vc : vc pytha ok\n");
	w->ca->vs = w->ca->fvcs;
	w->ca->vx = w->ca->fvcx;
	w->ca->vy = w->ca->fvcy;
	// printf
	// printf("ft_while_vc : vy %f vcy %f\n", w->ca->vy, w->ca->vcy);
	if (w->ca->vy - w->ca->vcy < 0)
		return (10000);


	// while (ft_is_wall(w->map, w->ca->vx, w->ca->vy) == 0 && w->ca->vs < 10000 && i < 20)
	// {
	// 	ft_vc_add(w, d);
	// 	i++;
	// }


	// printf("ft_while_vc : ft_is_wall %d vx %f vy %f i %d\n", ft_is_wall(w->map, w->ca->vx, w->ca->vy), w->ca->vx, w->ca->vy, i);
	// printf("ft_while_vc : i %d\n", i);
	// printf("ft_while_vc : vx %f vy %f\n", w->ca-vx, w->ca->vy);
	if (w->ca->vy < 0)
		return (10000);
	// printf("ft_while_vc : x %f y %f\n", w->ca->vx, w->ca->vy);
	return (w->ca->vs * 100);
}
