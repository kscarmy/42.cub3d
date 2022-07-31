/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_thales.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:45:34 by guderram          #+#    #+#             */
/*   Updated: 2022/07/31 11:04:48 by guderram         ###   ########.fr       */
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
	return (ret);
}

double	ft_thales_range(w_point *w, double d)
{
	double	ret;

	ret = 0;
	ft_re_set_calc(w);
	if (d > 90 && d <= 270)
		ft_vc_init_down(w, d);
	else
		ft_vc_init_up(w, d);
	if (d <= 180)
		ft_hc_init_right(w, d);
	else
		ft_hc_init_left(w, d);
	if (w->v->vr <= w->h->hr)
	{
		ret = w->v->vr;
		printf("ft_thales_range : VR ret %f d %f\n", ret, d);
	}
	else
	{
		ret = w->h->hr;
		printf("ft_thales_range : HR ret %f d %f\n", ret, d);
	}
	w = w;
	return (ret * 100);
}
