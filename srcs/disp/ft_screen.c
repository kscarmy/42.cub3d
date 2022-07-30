/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:52:57 by guderram          #+#    #+#             */
/*   Updated: 2022/07/30 13:32:17 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_screen_init(w_point *w)
{
	w->sr = 0;
	w->sr = (RES_X / 2) / tan(ft_degrees_to_radian(FOV_SIZE / 2));
	printf("ft_screen_init : screen range : %f", w->sr);
	w->map->floor = (w->map->fr << 16) | (w->map->fg << 8) | w->map->fb;
	w->map->ceiling = (w->map->cr << 16) | (w->map->cg << 8) | w->map->cb;
}

void	ft_screen(w_point *w)
{
	int	i;
	int	max = 0;
	double	r;
	double	d;

	i = 0;
	r = 100000;
	d = RES_X / FOV_SIZE;
	while (i < (RES_X / 2) && max < 10)
	{
			/*	ZONE DROITE DE LECRAN	*/
		// r = ft_thanles_range(w, (d * i));
		/*	FONCTION DAFFICHAGE DE LA COLONNE	*/

			/*	ZONE DROITE DE LECRAN	*/
		// r = ft_thanles_range(w, (d * -i));
		/*	FONCTION DAFFICHAGE DE LA COLONNE	*/
		
		i++;
		max++;
	}
	d = d;
	r = r;
	w = w;
}
