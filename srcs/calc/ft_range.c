/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:56:59 by guderram          #+#    #+#             */
/*   Updated: 2022/07/17 13:57:51 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_reset_ca(w_point *w)
{
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
	// x++;
	// y++;
	if (y < 0)
		return (1);
	if (x < 0)
		return (1);


	if (ft_abs((int)y) > map->l)
		return (1);
	if (ft_abs((int)x) > ft_str_size(map->map[(int)ft_abs((int)y)]))
		return (1);
	// printf("ft_is_wall x %f y %f x %d y %d\n", x, y, (int)x, (int)y);
	// printf("ft_is_wall : x %d y %d\n", ft_is_entier(x), ft_is_entier(y));
	// if (ft_is_entier(x) == 0 && ft_is_entier(y) == 1)
	// {
	// 	if (map->map[(int)y][(int)x] == '1')
	// 		return (1);
	// 	if (map->map[(int)y][(int)x + 1] == '1')
	// 		return (1);
	// }
	// if (ft_is_entier(x) == 1 && ft_is_entier(y) == 0)
	// {
	// 	if (map->map[(int)y][(int)x] == '1')
	// 		return (1);
	// 	if (map->map[(int)y + 1][(int)x] == '1')
	// 		return (1);
	// }
	// if ((ft_is_entier(y) == 0) && ft_is_entier(x) == 1 && (map->map[(int)y - 1][(int)x] == '1')) // test y - 1 si y est en bordure
	// {
	// 	printf("wall x\n");
	// 	return (1);
	// }
	// if ((ft_is_entier(x) == 0) && ft_is_entier(y) == 1 && (map->map[(int)y][(int)x - 1] == '1')) // test x - 1 si y est en bordure
	// {
	// 	printf("wall y\n");
	// 	return (1);
	// }
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
	return (ft_ret_range(x, y, w->ca->x, w->ca->y) * 100);
}
