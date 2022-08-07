/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:44:30 by guderram          #+#    #+#             */
/*   Updated: 2022/08/07 09:36:37 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_vc_add(w_point *w)
{
	w->v->vx += (w->v->vcx * w->dirx);
	w->v->vy += (w->v->vcy * w->diry);
	w->v->vr += w->v->vcr;
}


void	ft_hc_add(w_point *w)
{
	printf("\nft_hc_add : R %f x %f y %f x %f y %f dx %f dy %f\n", w->h->hr, w->h->hx, w->h->hy, w->h->hcx, w->h->hcy, w->dirx, w->diry);
	w->h->hx += (w->h->hcx * w->dirx);
	w->h->hy += (w->h->hcy * w->diry);
	w->h->hr += w->h->hcr;
	printf("ft_hc_add : R %f x %f y %f x %f y %f dx %f dy %f\n", w->h->hr, w->h->hx, w->h->hy, w->h->hcx, w->h->hcy, w->dirx, w->diry);
}
