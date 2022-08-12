/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:44:30 by guderram          #+#    #+#             */
/*   Updated: 2022/08/12 15:07:14 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_vc_add(t_w_point *w)
{
	w->v->vx += (w->v->vcx * w->dirx);
	w->v->vy += (w->v->vcy * w->diry);
	w->v->vr += w->v->vcr;
}

void	ft_hc_add(t_w_point *w)
{
	w->h->hx += (w->h->hcx * w->dirx);
	w->h->hy += (w->h->hcy * w->diry);
	w->h->hr += w->h->hcr;
}

double	ft_thales_angle_conv(t_w_point *w, double d)
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
