/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 08:19:04 by guderram          #+#    #+#             */
/*   Updated: 2022/08/07 08:30:48 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_degrees_to_radian(double deg)
{
	return (deg * PI_VAL / 180);
}

double	ft_radian_to_degrees(double rad)
{
	return (rad * 180 / PI_VAL);
}

void	ft_red_pixel(w_point *w, int h, int x)
{
	int	i;
	int	mid;

	i = 0;
	mid = RES_Y / 2;
	// printf("crash ?");
	while (h > 0 && i < h && i <= RES_Y)
	{
		if (w->dirx == 1 && w->or == 1) //			DROITE : ORANGE
		{
			mlx_pixel_put(w->mlx, w->win1, x, mid + i, 0xF59042);
			mlx_pixel_put(w->mlx, w->win1, x, mid - i, 0xF59042);
		}
		else if (w->dirx == -1 && w->or == 1) //	GAUCHE : VERT
		{
			mlx_pixel_put(w->mlx, w->win1, x, mid + i, 0x26BF59);
			mlx_pixel_put(w->mlx, w->win1, x, mid - i, 0x26BF59);
		}
		else if (w->diry == 1 && w->or == -1) //		BAS : BLEU
		{
			mlx_pixel_put(w->mlx, w->win1, x, mid + i, 0x0D256E);
			mlx_pixel_put(w->mlx, w->win1, x, mid - i, 0x0D256E);
		}
		else if (w->diry == -1 && w->or == -1) //	HAUT : MAUVE
		{
			mlx_pixel_put(w->mlx, w->win1, x, mid + i, 0xA30F54);
			mlx_pixel_put(w->mlx, w->win1, x, mid - i, 0xA30F54);
		}
		// mlx_pixel_put(w->mlx, w->win1, x, mid + i, 0xFF99FF);
		// mlx_pixel_put(w->mlx, w->win1, x, mid - i, 0xFF99FF);
		i++;
	}
	// printf("non\n");
	// while (i <= RES_Y)
	// {
	// 	mlx_pixel_put(w->mlx, w->win1, x, mid + i, w->map->floor);
	// 	mlx_pixel_put(w->mlx, w->win1, x, mid - i, w->map->ceiling);
	// 	i++;
	// }
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

double	ft_double_abs(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}
