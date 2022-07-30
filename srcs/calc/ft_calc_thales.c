/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_thales.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:45:34 by guderram          #+#    #+#             */
/*   Updated: 2022/07/30 15:05:45 by guderram         ###   ########.fr       */
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

double  ft_thales_range(w_point *w, double d)
{
	double	ret;

	ret = 0;
	printf("ft_thales_range : d %f\n", d);
	w = w;
	return (ret);
}
