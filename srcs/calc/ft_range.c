/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:56:59 by guderram          #+#    #+#             */
/*   Updated: 2022/06/15 14:26:47 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_reset_ca(w_point *w)
{
	// w->ca->hx = 0;
	// win->ca->hy = 0;
	// win->ca->fvcy = 0;
	// win->ca->fvcx = 0;
	// win->ca->fvcs = 0;
	// win->ca->phx = 0;
	// win->ca->phy = 0;
	// win->ca->pvx = 0;
	// win->ca->pvy = 0;



	w->ca->fvcs = 0;
	w->ca->fvcx = 0;
	w->ca->fvcy = 0;

	w->ca->vcs = 0;
	w->ca->vcx = 0;
	w->ca->vcy = 0;

	w->ca->vs = 0;
	w->ca->vx = 0;
	w->ca->vy = 0;





	w->ca->fhcs = 0;
	w->ca->fhcx = 0;
	w->ca->fhcy = 0;


	w->ca->hcs = 0;
	w->ca->hcx = 0;
	w->ca->hcy = 0;

	w->ca->hs = 0;
	w->ca->hx = 0;
	w->ca->hy = 0;
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
	if ((int)y > map->l + 1)
		return (1);
	if ((int)x > ft_str_size(map->map[(int)y]))
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
	printf("ft_ret_range 1 : x %f y %f xx %f yy %f\n", x, y, xx, yy);
	x = ft_abs(x) - ft_abs(xx);
	y = ft_abs(y) - ft_abs(yy);
	printf("ft_ret_range 2 : x %f y %f xx %f yy %f\n", x, y, xx, yy);
	ret = ft_pytha(ft_abs(x), ft_abs(y));
	printf("ft_ret_range 3 : ret %f\n", ret);
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
	printf("ft_right_angle 1 : x %f y %f\n", x, y);
	while (ft_is_wall(w->map, x, y) == 0 && i < 100000000)
	{
		if (d == 0) // remonte
			y = y - 0.001;
		if (d == 90) // droite
			x = x + 0.001;
		if (d == 180) // descend
			y = y + 0.001;
		if (d == 270) // gauche
			x = x - 0.001;
		i++;
	}
	printf("ft_right_angle 2 : x %f y %f\n", x, y);
	printf("ft_right_angle 3 : i %d\n", i);
	// x = x + ((double)w->pos_y / 100);
	// y = y + ((double)w->pos_x / 100);
	// printf("ft_right_angle 4 : x %f y %f\n", x, y);
	return (ft_ret_range(x, y, w->ca->x, w->ca->y) * 100);
}
