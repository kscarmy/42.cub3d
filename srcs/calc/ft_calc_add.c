/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:44:30 by guderram          #+#    #+#             */
/*   Updated: 2022/08/06 15:32:54 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_vc_add(w_point *w)
{
	w->v->vx += (w->v->vcx * w->dirx);
	w->v->vy += (w->v->vcy * w->diry);
	w->v->vr += w->v->vcr;





	// if (d <= 180)
	// {
	// 	w->h->hr += w->h->hcr;
	// 	w->h->hx += w->h->hcx;
	// 	w->h->hy += w->h->hcy;
	// }
	// else
	// {
	// 	w->h->hr += w->h->hcr;
	// 	w->h->hx -= w->h->hcx;
	// 	w->h->hy += w->h->hcy;
	// }
}


void	ft_hc_add(w_point *w)
{
	w->h->hx += (w->h->hcx * w->dirx);
	w->h->hy += (w->h->hcy * w->diry);
	w->h->hr += w->h->hcr;

	// if (d > 90 && d <= 270)
	// {
	// 	w->v->vr += w->v->vcr;
	// 	w->v->vx += w->v->vcx;
	// 	w->v->vy -= w->v->vcy;
	// }
	// else
	// {
	// 	w->v->vr += w->v->vcr;
	// 	w->v->vx += w->v->vcx;
	// 	w->v->vy += w->v->vcy;
	// }
}
