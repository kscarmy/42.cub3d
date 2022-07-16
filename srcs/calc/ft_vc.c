/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:46:43 by guderram          #+#    #+#             */
/*   Updated: 2022/07/16 13:59:48 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_vc_add(w_point *w, double d) // rajoute les zones de calculs au point en question
{
	// printf("ft_vc_add : x %f y %f\n", w->ca->vx, w->ca->vy);
	if (d < 90)
	{
		// printf("incre vc 0-90\n");
		w->ca->vs = w->ca->vs + w->ca->vcs;
		w->ca->vx = w->ca->vx + w->ca->vcx;
		w->ca->vy = w->ca->vy - w->ca->vcy;
	}
	if (d > 270)
	{
		// printf("incre vc 270-0\n");
		w->ca->vs = w->ca->vs + w->ca->vcs;
		w->ca->vx = w->ca->vx - w->ca->vcx;
		w->ca->vy = w->ca->vy - w->ca->vcy;
	}
	// printf("ft_vc_add : x %f y %f\n", w->ca->vx, w->ca->vy);
}

void	ft_vc_pytha(w_point *w, double d)
{
	double	x;
	double	y;
	
	x = 0;
	y = 0;
	// printf("ft_vc_pytha : d %f\n", d);
	if (d < 90 || d > 270)
	{
		x = 1;
		y = x * tan(ft_degrees_to_radian(d));
		w->ca->vcx = x;
		w->ca->vcy = y;
	}
	w->ca->vcs = ft_ret_range(x, y, 0, 0);
	// printf("ft_vc_pytha : x %f y %f x %f y %f\n", x, y, w->ca->fvcx, w->ca->fvcy);
}

void	ft_first_vc_pytha(w_point *w, double d)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	// printf("ft_first_vc_pytha : d %f\n", d);
	if (d < 90)
	{
		x = 1 - ((double)w->pos_x / 64);
		y = x / tan(ft_degrees_to_radian(d));

		w->ca->fvcx = w->ca->fvcx + x;
		w->ca->fvcy = w->ca->fvcy - y; // gestion de y avec la premiere ligne
		// printf("ft_first_vc_pytha : D %f : x %f y %f fvcx %f fvcy %f\n", d, x, y, w->ca->fvcx, w->ca->fvcy);
	}
	if (d > 270)
	{
		x = ((double)w->pos_x / 64);
		y = x / tan(ft_degrees_to_radian(d));
		w->ca->fvcx = w->ca->fvcx - x;
		w->ca->fvcy = w->ca->fvcy - y; // gestion de y avec la premiere ligne
	}
	// printf("ft_first_vc_pytha : x %f y %f x %f y %f\n", x, y, w->ca->fvcx, w->ca->fvcy);
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
	int	i = 0;
	// printf("ft_while_vc : entree\n");

	ft_first_vc(w, d);
	// printf("ft_while_vc : first vc pytha ok\n");
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
	while (ft_is_wall(w->map, w->ca->vx, w->ca->vy) == 0 && w->ca->vs < 10000 && i < 20)
	{
		ft_vc_add(w, d);
		i++;
	}
	printf("ft_while_vc : ft_is_wall %d vx %f vy %f i %d\n", ft_is_wall(w->map, w->ca->vx, w->ca->vy), w->ca->vx, w->ca->vy, i);
	// printf("ft_while_vc : i %d\n", i);
	// printf("ft_while_vc : vx %f vy %f\n", w->ca-vx, w->ca->vy);
	if (w->ca->vy < 0)
		return (10000);
	// printf("ft_while_vc : x %f y %f\n", w->ca->vx, w->ca->vy);
	return (ft_ret_range(w->ca->vx, w->ca->vy, w->ca->x, w->ca->y) * 100);
}
