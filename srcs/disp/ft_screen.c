/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:52:57 by guderram          #+#    #+#             */
/*   Updated: 2022/08/06 08:35:45 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_screen_init(w_point *w)
{
	w->sr = 0;
	w->sr = (RES_X / 2) / tan(ft_degrees_to_radian(FOV_SIZE / 2));

	w->map->floor = (w->map->fr << 16) | (w->map->fg << 8) | w->map->fb;
	w->map->ceiling = (w->map->cr << 16) | (w->map->cg << 8) | w->map->cb;
	printf("ft_screen_init : screen range : %f floor %d ceilling %d\n", w->sr, w->map->floor, w->map->ceiling);
}

void	ft_screen(w_point *w)
{
	double	i;
	int	max = 0;
	double	r;
	double	d;
	int	a; // droite de lecran
	int	b; // gauche de lecran
	
	i = 0;
	r = 0;
	a = 0;
	b = 0;
	r = 100000;
	d = (double)FOV_SIZE / (double)RES_X;
	while (i <= (RES_X / 2) && 1 < 2)
	{
			/*	ZONE DROITE DE L	ECRAN	*/
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * i)) + 500;
		while (a < PIXEL_SIZE)
		{
			/*	FONCTION DAFFICHAGE DE LA COLONNE	*/
			ft_red_pixel(w, (w->sr * (double)WALL_SIZE) / r, (RES_X / 2) + i); // PROVISOIRE
			a++;
			i++;
		}
		a = 0;
		i = i - PIXEL_SIZE;
				/*	ZONE GAUCHE DE LECRAN	*/
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * i * -1)) + 500;
		while (b < PIXEL_SIZE)
		{
			
			


			/*	FONCTION DAFFICHAGE DE LA COLONNE	*/
			ft_red_pixel(w, (w->sr * (double)WALL_SIZE) / r, (RES_X / 2) - i); // PROVISOIRE
			i++;
			b++;
		}
		b = 0;
		max++;
	}
	d = d;
	r = r;
	w = w;
}
