/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:56:59 by guderram          #+#    #+#             */
/*   Updated: 2022/06/14 17:03:39 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_reset_ca(w_point *win)
{
	win->ca->hx = 0;
	win->ca->hy = 0;
	win->ca->vx = 0;
	win->ca->vy = 0;
	win->ca->phx = 0;
	win->ca->phy = 0;
	win->ca->pvx = 0;
	win->ca->pvy = 0;
}

double		ft_pytha(double x, double y) // rend la distance
{
	double ray;

	ray = sqrt((x * x) + (y * y));
	return(ray);
}



int		ft_is_wall(m_point *map, double x, double y) // renvoie 1 sur mur, sinon 0
{
	// int	i;
	// int	u;

	// i = 0;
	// u = 0;
	// while ()
	if (map->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

double	ft_abs(double i) // renvoie la valeur absolue dun double
{
	if (i < 0)
		return (i * -1);
	return (i);
}

double	ft_inf_one(double i) // renvoie ce qui est apres la virgule
{
	while (i > 1)
		i--;
	return (i);
}

double	ft_ret_range(double x, double y, double xx, double yy) // renvoie la distance des deux points
{
	double ret;
	
	ret = 0;
	x = ft_abs(x) - ft_abs(xx);
	y = ft_abs(y) - ft_abs(yy);
	ret = ft_pytha(ft_abs(x), ft_abs(y));
	return(ret);
}

double	ft_right_angle(w_point *w, double d)
{
	int	i; // A SUPP SECU
	double	x;
	double	y;

	i = 0;
	x = w->ca->x;
	y = w->ca->y;
	while (ft_is_wall(w->map, x, y) == 0 && i < 10)
	{
		if (d == 0) // remonte
			y--;
		if (d == 90) // droite
			x++;
		if (d == 180) // descend
			y++;
		if (d == 270) // gauche
			x--;
		i++;
	}
	x = x + ((double)w->pos_y / 100);
	y = y + ((double)w->pos_x / 100);
	printf("ft_right_angle : x %f y %f\n", x, y);
	return (ft_ret_range(x, y, w->ca->x, w->ca->y) * 100);
}
