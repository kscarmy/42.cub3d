/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:25:15 by guderram          #+#    #+#             */
/*   Updated: 2022/07/17 02:47:20 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_set_ca(w_point *win)
{
	win->ca->hx = 0;
	win->ca->hy = 0;
	win->ca->fvcy = 0;
	win->ca->fvcx = 0;
	win->ca->fvcs = 0;
	win->ca->x = 0;
	win->ca->y = 0;
	win->ca->hray = 0;
	win->ca->ohray = 0;
	win->ca->vray = 0;
	win->ca->ovray = 0;
}

double	ft_converte_angle(double d, double a, int sig) // sig = addition 1 ou soustraction 0
{
	double deg;
	
	deg = d;
	if ((deg - a) < 0 && sig == 0)
		return (360 + (deg - a));
	if ((d + a) >= 360 && sig == 1)
		return (360 - (d + a));
	return (d + a);

}

double	ft_found_angle(w_point *win, double d)
{
	double rh;
	double rv;

	rh = 0;
	rv = 0;
	if (d == 0 || d == 90 || d == 180 || d == 270)
	{
		rh = ft_right_angle(win, d);
		return (rh);
	}

	rh = ft_while_hc(win, d);
	rh = rh * cos(ft_degrees_to_radian(d));
	
	rv = ft_while_vc(win, d);
	rv = rv * cos(ft_degrees_to_radian(d));
	if (rh < rv)
		return (rh);
	return (rv);
}

void	ft_thales(w_point *win, double a, int c, int i)	
{
	double h; // hauteur à disp
	double r;

	r = 0;
	ft_reset_ca(win);
	r = ft_found_angle(win, ft_converte_angle(win->d, a, 1)); // droite de l ecran
	r = ft_abs(r) * 2;  // A SUPP 
	h = (100 / r) * win->screen_range;	
	ft_red_pixel(win, h, c + i); // A SUPP LE '- 50'
}
