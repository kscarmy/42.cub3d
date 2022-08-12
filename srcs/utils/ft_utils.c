/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 08:19:04 by guderram          #+#    #+#             */
/*   Updated: 2022/08/12 14:18:36 by guderram         ###   ########.fr       */
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
