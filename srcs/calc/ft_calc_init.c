/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:21:42 by guderram          #+#    #+#             */
/*   Updated: 2022/08/06 13:21:29 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_re_set_calc(w_point *w)
{
	w->h->hx = 0;
	w->h->hy = 0;
	w->h->hr = 0;
	w->h->hcx = 0;
	w->h->hcy = 0;
	w->h->hcr = 0;
	w->v->vx = 0;
	w->v->vy = 0;
	w->v->vr = 0;
	w->v->vcx = 0;
	w->v->vcy = 0;
	w->v->vcr = 0;
}

// void	ft_vc_init(w_point *w, double d)
// {
// 	if (d <= 180)
// 		w->v->vcy = ((double)w->pos_y / 100);
// 	else
// 		w->v->vcy = ((100 - (double)w->pos_y) / 100);
// 	w->v->vcx = ft_double_abs(w->v->vcy / tan(ft_degrees_to_radian(d)));
// 	printf("ft_vc_init : cx %f cy %f\n", w->v->vcx, w->v->vcy);
// 	w->v->vr = ft_thales_pytha(w->v->vcx, w->v->vcy);
// 	if (d <= 180)
// 		w->v->vy = (double)w->y;
// 	else
// 		w->v->vy = (double)w->y + 1;
// 	w->v->vx = (double)w->x + ((double)w->pos_x / 100) + (w->v->vcx * w->dirx);
// 	w->v->vcy = 1;
// 	w->v->vcx = ft_double_abs(w->v->vcy / tan(ft_degrees_to_radian(d)));
// }

// void	ft_hc_init(w_point *w, double d)
// {
// 	if (d >= 90 && d <= 270)
// 		w->h->hcx = ((100 - (double)w->pos_x) / 100);
// 	else
// 		w->h->hcx = ((double)w->pos_x / 100);
// 	w->h->hcy = ft_double_abs(w->h->hcx / cos(ft_degrees_to_radian(d)));
// 	printf("ft_hc_init : cx %f cy %f\n", w->h->hcx, w->h->hcy);
// 	w->h->hr = ft_thales_pytha(w->h->hcx, w->h->hcy);
// 	if (d >= 90 && d <= 270)
// 		w->h->hx = (double)w->x;
// 	else
// 		w->h->hx = (double)w->x + 1;

// 	w->h->hy = (double)w->y + ((double)w->pos_y / 100) + (w->v->vcy * w->diry);
// 	w->h->hcx = 1;
// 	w->h->hcy = ft_double_abs(w->v->vcx / cos(ft_degrees_to_radian(d)));
// }

void	ft_vc_init_up(w_point *w, double d)
{
	w->h->hcy = ((double)w->pos_y / 100);
	if (d <= 90)
		w->h->hcx = w->h->hcy / tan(ft_degrees_to_radian(d));
	else
		w->h->hcx = w->h->hcy / tan(ft_degrees_to_radian(360 - d));
	w->h->hr = ft_thales_pytha(w->h->hcx, w->h->hcy);
	w->h->hy = (double)w->y;
	if (d <= 90)
		w->h->hx = (double)w->x + ((double)w->pos_x / 100) + w->h->hcx;
	else
		w->h->hx = (double)w->x + ((double)w->pos_x / 100) - w->h->hcx;

	w->h->hcy = 1;
	if (d <= 90)
		w->h->hcx = w->h->hcy / tan(ft_degrees_to_radian(d));
	else
		w->h->hcx = w->h->hcy / tan(ft_degrees_to_radian(360 - d));
	w->h->hcr = ft_thales_pytha(w->h->hcx, w->h->hcy);
}

void	ft_vc_init_down(w_point *w, double d)
{
	w->h->hcy = 1 - ((double)w->pos_y / 100);
	if (d > 90 && d <= 180)
		w->h->hcx = w->h->hcy / tan(ft_degrees_to_radian(180 - d));
	else
		w->h->hcx = w->h->hcy / tan(ft_degrees_to_radian(d - 180));
	w->h->hr = ft_thales_pytha(w->h->hcx, w->h->hcy);
	w->h->hy = (double)w->y + 1;
	if (d > 90 && d <= 180)
		w->h->hx = (double)w->x + ((double)w->pos_x / 100) + w->h->hcx;
	else
		w->h->hx = (double)w->x + ((double)w->pos_x / 100) - w->h->hcx;

	w->h->hcy = 1;
	if (d > 90 && d <= 180)
		w->h->hcx = w->h->hcy / tan(ft_degrees_to_radian(180 - d));
	else
		w->h->hcx = w->h->hcy / tan(ft_degrees_to_radian(d - 180));
	w->h->hcr = ft_thales_pytha(w->h->hcx, w->h->hcy);
}

void	ft_hc_init_right(w_point *w, double d)
{
	w->v->vcx = 1 - ((double)w->pos_x / 100);
	if (d <= 90)
		w->v->vcy = w->v->vcx / tan(ft_degrees_to_radian(90 - d));
	else
		w->v->vcy = w->v->vcx / tan(ft_degrees_to_radian(d - 90));
	w->v->vr = ft_thales_pytha(w->v->vcx, w->v->vcy);
	w->v->vx = (double)w->x + 1;
	if (d <= 90)
		w->v->vy = (double)w->y + ((double)w->pos_y / 100) - w->v->vcy;
	else
		w->v->vy = (double)w->y + ((double)w->pos_y / 100) + w->v->vcy;

	w->v->vcx = 1;
	if (d <= 90)
		w->v->vcy = w->v->vcx / tan(ft_degrees_to_radian(90 - d));
	else
		w->v->vcy = w->v->vcx / tan(ft_degrees_to_radian(d - 90));
	w->v->vcr = ft_thales_pytha(w->v->vcx, w->v->vcy);
}

void	ft_hc_init_left(w_point *w, double d)
{
	w->v->vcx = ((double)w->pos_x / 100);
	if (d <= 270)
		w->v->vcy = w->v->vcx / tan(ft_degrees_to_radian(270 - d));
	else
		w->v->vcy = w->v->vcx / tan(ft_degrees_to_radian(270 - d));
	w->v->vr = ft_thales_pytha(w->v->vcx, w->v->vcy);
	w->v->vx = (double)w->x;
	if (d <= 270)
		w->v->vy = (double)w->y + ((double)w->pos_y / 100) - w->v->vcy;
	else
		w->v->vy = (double)w->y + ((double)w->pos_y / 100) + w->v->vcy;

	w->v->vcx = 1;
	if (d <= 270)
		w->v->vcy = w->v->vcx / tan(ft_degrees_to_radian(270 - d));
	else
		w->v->vcy = w->v->vcx / tan(ft_degrees_to_radian(270 - d));
	w->v->vcr = ft_thales_pytha(w->v->vcx, w->v->vcy);
}
