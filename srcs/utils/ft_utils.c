/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:35:30 by guderram          #+#    #+#             */
/*   Updated: 2022/07/30 13:29:37 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_degrees_to_radian(double deg)
{
	return (deg * M_PI / 180);
}

double	ft_radian_to_degrees(double rad)
{
	return (rad * 180 / M_PI);
}

void	ft_red_pixel(w_point *w, int h, int x)
{
	int	i;
	int	mid;

	i = 0;
	mid = RES_Y / 2;
	while (h < RES_Y && h > 0 && i < h && i <= RES_Y)
	{
		mlx_pixel_put(w->mlx, w->win1, x, mid + i, 0xFF99FF);
		mlx_pixel_put(w->mlx, w->win1, x, mid - i, 0xFF99FF);
		i++;
	}
	while (i <= RES_Y)
	{
		mlx_pixel_put(w->mlx, w->win1, x, mid + i, w->map->ceiling);
		mlx_pixel_put(w->mlx, w->win1, x, mid - i, w->map->floor);
		i++;
	}
}

int	ft_str_size(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str != NULL && str[i] && str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_entier(double a)
{
	while (a >= 1)
		a = a - 1;
	if (a > 0)
		return (1);
	return (0);
}
