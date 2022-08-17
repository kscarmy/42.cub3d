/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:54:48 by guderram          #+#    #+#             */
/*   Updated: 2022/08/17 14:42:44 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_fps(t_w_point *w)
{
	long	old;
	
	old = w->time;
	w->i += 1;
	w->time = ft_get_time();
	if (w->time != old)
	{
		w->fps = w->i;
		w->i = 0;
	}
	old = old;
}

long	ft_get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec));
}
