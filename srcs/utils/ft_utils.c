/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:35:30 by guderram          #+#    #+#             */
/*   Updated: 2022/06/14 16:21:31 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

double	ft_degrees_to_radian(double deg)
{
	return(deg * M_PI / 180);
}

double	ft_radian_to_degrees(double rad)
{
	return(rad * 180 / M_PI);
}


void	ft_red_pixel(w_point *win, int h, int x)
{
	int	i;
	int ret;
	int mid;

	i = 0;
	mid = win->map->ry/2;
	ret = 0;
	ft_printf("red pixel : h : '%d' x : '%d'\n", h, x);
	while (h > 0 && i < h)
	{
		ret = mlx_pixel_put(win->mlx,win->win1, x, mid + i,0xFF99FF);
		ret = mlx_pixel_put(win->mlx,win->win1, x, mid - i,0xFF99FF);
		i++;
	}
	ret = ret;
}