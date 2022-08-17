/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_thales.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:45:34 by guderram          #+#    #+#             */
/*   Updated: 2022/08/17 16:21:14 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	ft_thales_pytha(double x, double y)
{
	double	ret;

	ret = 0;
	ret = sqrt((x * x) + (y * y));
	return (ft_double_abs(ret));
}

void	ft_thales_init(t_w_point *w, double d)
{
	ft_re_set_calc(w);
	if (d <= 180)
		w->diry = -1;
	else
		w->diry = 1;
	if (d >= 90 && d <= 270)
		w->dirx = -1;
	else
		w->dirx = 1;
	ft_vc_init(w, d);
	ft_hc_init(w, d);
}

int	ft_thales_wall(t_w_point *w, double x, double y)
{
	if (x < 0.)
		return (0);
	if (y < 0.)
		return (0);
	if (x > 100000.)
		return (0);
	if (y > 100000.)
		return (0);
	w = w;
	if ((int)y > w->map->l - 1)
		return (0);
	if ((int)x > ft_str_size(w->map->map[(int)y]))
		return (0);
	if (w->map->map[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

double	ft_thales_range_or(t_w_point *w)
{
	double	ret;

	ret = 0;
	if (w->v->vr <= w->h->hr)
	{
		ret = w->v->vr;
		w->or = 1;
	}
	else
	{
		ret = w->h->hr;
		w->or = -1;
	}
	return (ret * w->zoom);
}

double	ft_thales_range(t_w_point *w, double d)
{
	int		i;

	i = 0;
	ft_thales_init(w, d);
	while (ft_thales_wall(w, w->h->hx, w->h->hy) == 1)
	{
		ft_hc_add(w);
		i++;
	}
	i = 0;
	while (ft_thales_wall(w, w->v->vx, w->v->vy) == 1)
	{
		ft_vc_add(w);
		i++;
	}
	return (ft_thales_range_or(w));
}
