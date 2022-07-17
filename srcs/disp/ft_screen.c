/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:27:50 by guderram          #+#    #+#             */
/*   Updated: 2022/07/17 03:56:02 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_screen(w_point *win)
{
	ft_set_screen(win);
}

void	ft_set_screen(w_point *win)
{
	float	tan;
	float	value;

	tan = 0.57735026919;
	value = ((win->map->rx / 2) / tan);
	win->screen_range = (int)value;
	ft_disp_screen(win);
}


void	ft_disp_screen(w_point *win)
{
	int x;
	int i;
	int u;
	double ang; // angle entre deux colones en degrés

	x = win->map->rx; // =nombre colones
	i = 0; // compteur colones
	ang = 90 / (double)win->map->rx;
	printf("ang : '%lf'\n", ang);

	u = (x % 2 == 0) ? x / 2 + 1 : x / 2; // zone où se situe les colones
	// ft_thales(win, win->d, u); // test angle droit // A REMETTRE ET MODIFIER LA FONCTION SUREMENT
	//affichage colone milieu
	win->max_y = 0;
	while (win->map->map[win->max_y])
		win->max_y++;
	
	win->ca->x = (double)win->y + ((double)win->pos_y / 100);
	win->ca->y = (double)win->x + ((double)win->pos_x / 100);
	printf("ft_disp_screen 1 : x %f y %f\n", win->ca->x, win->ca->y);
	while (i < (x / 2) && 1 < 280) // supp i < 10 car test
	{
		ft_thales(win, (ang * i), u, i);
		i++;
	}
	// affichage colone supplémentaire si rx est pair
//	ft_map_disp_pos(win);
}
