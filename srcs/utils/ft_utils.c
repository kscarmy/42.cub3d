/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:35:30 by guderram          #+#    #+#             */
/*   Updated: 2022/07/19 16:37:06 by guderram         ###   ########.fr       */
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


void	ft_red_pixel(w_point *w, int h, int x)
{
	int	i;
	int ret;
	int mid;

	i = 0;
	mid = w->map->ry/2;
	ret = 0;
	// ft_printf("red pixel : h : '%d' x : '%d'\n\n", h, x);
	while (h < w->map->ry && h > 0 && i < h && i <= w->map->ry)
	{
		ret = mlx_pixel_put(w->mlx,w->win1, x, mid + i,0xFF99FF);
		ret = mlx_pixel_put(w->mlx,w->win1, x, mid - i,0xFF99FF);
		i++;
	}
	ret = ret;
}

int		ft_str_size(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str != NULL && str[i] && str[i] != '\0')
		i++;
	return (i);
}

int		ft_is_entier(double a) // retourne 1 si le nombre n'est pas entier sinon 0
{
	while (a >= 1)
		a = a - 1;
	// printf("ft_is_entier a %f\n", a);
	if (a > 0)
		return (1);
	return (0);
}