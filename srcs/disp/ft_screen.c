/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:52:57 by guderram          #+#    #+#             */
/*   Updated: 2022/08/07 14:58:58 by mourdani         ###   ########.fr       */
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

void	ft_swap_pos(w_point *w)
{
	int	a;
	int	b;

	a = w->x;
	b = w->pos_x;
	w->x = w->y;
	w->y = a;
	w->pos_x = w->pos_y;
	w->pos_y = b;
}

static void	ft_printf_map(w_point *w)
{
	int y = 0;
	int x = 0;
	// printf("<");
	while (w->map->map[y])
	{
		while (w->map->map[y][x])
		{
			printf("%c'", w->map->map[y][x]);
			x++;
		}
		printf(">\n");
		x = 0;
		y++;
	}
	
}

void	ft_screen(w_point *w)
{
	double	i;
	int	max = 0;
	double	r;
	double	d;

	i = 0;
	r = 100000.;
	// ft_swap_pos(w);
	d = (double)FOV_SIZE / (double)RES_X;
	printf("---------------ft_screen : d %f x %d y %d\n", w->d, w->x, w->y);
	while (i <= (RES_X / 2) && 1 < 2)
	{
			/*	ZONE DROITE DE L	ECRAN	*/
	//	printf("DROITE :\n");
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * i * -1));
		
			/*	FONCTION DAFFICHAGE DE LA COLONNE	*/
		ft_red_pixel(w, (w->sr * (double)WALL_SIZE) / r, (RES_X / 2) + i); // PROVISOIRE

	//	printf("GAUCHE :\n");
			/*	ZONE GAUCHE DE LECRAN	*/
		r = ft_thales_range(w, ft_thales_angle_conv(w, d * i));
			/*	FONCTION DAFFICHAGE DE LA COLONNE	*/
		ft_red_pixel(w, (w->sr * (double)WALL_SIZE) / r, (RES_X / 2) - i); // PROVISOIRE
	//	printf("\n================\n");
		i++;
		max++;
	}
	printf("================\nPos_X : %d\nPos_Y : %d\nX : %d\nY : %d\nD : %d\n"
		, w->pos_x, w->pos_y, w->x, w->y, (int) w->d);
	// ft_swap_pos(w);
	ft_printf_map(w);
	d = d;
	r = r;
	w = w;
}
