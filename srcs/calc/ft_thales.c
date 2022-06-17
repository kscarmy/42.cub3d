/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:25:15 by guderram          #+#    #+#             */
/*   Updated: 2022/06/17 14:46:34 by guderram         ###   ########.fr       */
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
	// win->ca->xx = 0;
	// win->ca->yy = 0;
	// win->ca->ox = ((win->x * 100) + win->pos_x) / 100;
	// win->ca->oy = ((win->x * 100) + win->pos_y) / 100;
	// win->ca->phx = win->ca->ox;
	// win->ca->phy = win->ca->oy;
	// win->ca->pvx = win->ca->ox;
	// win->ca->pvy = win->ca->oy;
	// win->ca->deg = 0;
	// win->ca->rad = 0;
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
	{
		return (360 + (deg - a));
	}
	if ((d + a) >= 360 && sig == 1)
	{
		return (360 - (d + a));
	}
	return (d + a);

}

double	ft_found_angle(w_point *win, double d)
{
	double rh;
	double rv;

	rh = 0;
	rv = 0;
	// ft_set_ca(win);
	// d = d;
	// printf("ft_found_angle : d %f\n", d);
	if (d == 0 || d == 90 || d == 180 || d == 270)
	{
		// printf("ANGLE DROIT\n");
		// return (ft_right_angle(win, d));
		rh = ft_right_angle(win, d);
		// printf("ft_found_angle : r %f\n", rh);
		return (rh);
	}

	// printf("\n\nPAS ANGLE DROIT\n\n");
		// ft_first_vc(win, d);
		// ft_first_hc(win, d);
	rh = ft_while_hc(win, d);
	rh = rh * cos(ft_degrees_to_radian(d));
	
	rv = ft_while_vc(win, d);
	rv = rv * cos(ft_degrees_to_radian(d));
	printf("ft_found_angle : rh %f rv %f \n", rh, rv);
	// printf("rh %f rv %f\n", rh, rv);
	// if (win->ca->hx < 0 || win->ca->hy < 0)
		// return (rv);
	// // printf("")
	// if (win->ca->vx < 0 || win->ca->vy < 0)
		// return (rh);	
	if (rh < rv)
		return (rh);
	return (rv);
	// return (0);
		
		// if (win->ca->hs < win->ca->vs)
		// 	r = win->ca->hs;
		// else
		// 	r = win->ca->vs;

		// win->ca->deg = d;
		// win->ca->rad = ft_degrees_to_radian(win->ca->deg);
		// r = ft_not_angle_droit(win, d);
		rv = rv;
}

void	ft_thales(w_point *win, double a, int c, int i)	
{
	double h; // hauteur à disp
	double r;
	// double u;

	r = 0;
	// h = 0;
	// a = 0;
	// r = r;
	// h = h;
	// a = a;
	// c = c;
	// i = i;
	// win = win;
	// i = 0;
	// c = 0;
	ft_reset_ca(win);
	// printf("ft_thales : x %f y %f\n", win->ca->x, win->ca->y);
	r = ft_found_angle(win, ft_converte_angle(win->d, a, 1)); // droite de l ecran
	r = ft_abs(r) * 2;  // A SUPP 
	// ft_map_disp_pos(win);
	printf("ft_thales : r %f\n", r);
	// printf("screen range : %d\n", win->screen_range);
	h = (100 / r) * win->screen_range;	
	ft_red_pixel(win, h, c + i); // A SUPP LE '- 50'
}
