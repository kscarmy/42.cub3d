/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:46:43 by guderram          #+#    #+#             */
/*   Updated: 2022/07/17 02:48:17 by mourdani         ###   ########.fr       */
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
		y = x * tan(ft_degrees_to_radian(90 - d));
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
		y = x / tan(ft_degrees_to_radian(90 - d));
		w->ca->fvcx = w->ca->fvcx + x;
		w->ca->fvcy = w->ca->fvcy - y; // gestion de y avec la premiere ligne
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
	int	i = 0;
	ft_first_vc(w, d);
	ft_vc_pytha(w, d);
	w->ca->vs = w->ca->fvcs;
	w->ca->vx = w->ca->fvcx;
	w->ca->vy = w->ca->fvcy;
	if (w->ca->vy - w->ca->vcy < 0)
		return (10000);
	while (ft_is_wall(w->map, w->ca->vx, w->ca->vy) == 0 && w->ca->vy - w->ca->vcy > 0 && w->ca->vs < 10000 && i < 10)
	{
		ft_vc_add(w, d);
		i++;
	}
	if (w->ca->vy < 0)
		return (10000);
	return (ft_ret_range(w->ca->vx, w->ca->vy, w->ca->x, w->ca->y) * 100);
}
