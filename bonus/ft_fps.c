/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:54:48 by guderram          #+#    #+#             */
/*   Updated: 2022/08/21 08:13:47 by guderram         ###   ########.fr       */
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

void	ft_put_pixel_hud(t_w_point *w, int x, int y)
{
	int		xx;
	int		yy;
	char	*hu;

	hu = w->hu;
	xx = x;
	yy = y;
	if (hu[x * 4 + 4 * HUD_X * y] == 0
		&& hu[x * 4 + 4 * HUD_X * y + 1] == 0
		&& hu[x * 4 + 4 * HUD_X * y + 2] == 0)
	{
		return ;
	}
	w->str[xx * 4 + 4 * RES_X * yy] = hu[x * 4 + 4 * HUD_X * y];
	w->str[xx * 4 + 4 * RES_X * yy + 1]
		= hu[x * 4 + 4 * HUD_X * y + 1];
	w->str[xx * 4 + 4 * RES_X * yy + 2]
		= hu[x * 4 + 4 * HUD_X * y + 2];
}

void	ft_put_hud(t_w_point *w)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HUD_Y)
	{
		while (x < HUD_X)
		{
			ft_put_pixel_hud(w, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
