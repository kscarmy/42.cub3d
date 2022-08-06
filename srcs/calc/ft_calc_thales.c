/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_thales.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:45:34 by guderram          #+#    #+#             */
/*   Updated: 2022/08/06 19:42:43 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_thales_angle_conv(w_point *w, double d)
{
	double	ret;

	ret = w->d;
	ret = ret + d;
	if (ret < 0)
		ret = 360 - ft_double_abs(ret);
	if (ret >= 360)
		ret = ret - 360;
	return (ret);
}

double	ft_thales_pytha(double x, double y)
{
	double	ret;

	ret = 0;
	ret = sqrt((x * x) + (y * y));
	return (ft_double_abs(ret));
}

void	ft_thales_init(w_point *w, double d)
{
	ft_re_set_calc(w);
	if (d <= 180) // vers le haut donc y decremente
		w->diry = -1;
	else // vers le bas donc y incremente
		w->diry = 1;

	if (d >= 90 && d <= 270) // vers la gauche donc x decremente
		w->dirx = -1;
	else // vers la droite donc x incremente
		w->dirx = 1;

	ft_vc_init(w, d);
	ft_hc_init(w, d);	
}

int	ft_thales_wall(m_point *m, double x, double y)
{
	// printf("ft_thales_wall : x %f y %f\n", x, y);
	if (x < 0.)
		return (0);
	if (y < 0.)
		return (0);
	if (x > 100000.)
		return (0);
	if (y > 100000.)
		return (0);
	if ((int)y > m->l - 1)
		return (0);
	if ((int)x > ft_str_size(m->map[(int)y]) - 1)
		return (0);
	if (m->map[(int)y][(int)x] == '1')
		return (0);
	// if (m->map[(int)y][(int)x] != '0' && m->map[(int)y][(int)x] != 'N' && m->map[(int)y][(int)x] != 'S' && m->map[(int)y][(int)x] != 'E' && m->map[(int)y][(int)x] != 'W')
	// 	return (0);
	return (1);
}

double	ft_thales_range(w_point *w, double d)
{
	double	ret;
	int		i;

	ret = 0;
	i = 0;
	ft_thales_init(w, d);
	// while (i < 4)
	// {
	// 	ft_vc_add(w);
	// 	ft_hc_add(w);
	// 	i++;
	// }
	// printf("x %f y %f\n", w->h->hx, w->h->hy);
	while (i < 5 && ft_thales_wall(w->map, w->h->hx, w->h->hy) == 1)
	{
		// printf("hc : x %f y %f\n", w->h->hx, w->h->hy);
		ft_hc_add(w);
		i++;
	}
	i = 0;
	while (i < 5 && ft_thales_wall(w->map, w->v->vx, w->v->vy) == 1)
	{
		// printf("vc : x %f y %f\n", w->v->vx, w->v->vy);
		ft_vc_add(w);
		i++;
	}
	if (w->v->vr <= w->h->hr)
	{
		ret = w->v->vr;
		// ret = ret * cos(ft_degrees_to_radian(d));
		// printf("vc : x %f y %f\n", w->v->vx, w->v->vy);
		// printf("ft_thales_range : VR ret %f d %f\n", ret, d);
	}
	else
	{
		ret = w->h->hr;
		// ret = ret * cos(ft_degrees_to_radian(d));
		// printf("hc : x %f y %f\n", w->h->hx, w->h->hy);
		// printf("ft_thales_range : HR ret %f d %f\n", ret, d);
	}
	i = i;
	return (ret * 100);
}
