/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:05:01 by mourdani          #+#    #+#             */
/*   Updated: 2022/07/31 11:12:53 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	convert_to_radian(double degree)
{
	return (degree * (M_PI / 180.0));
}

double	find_y(double d, double h)
{
	return (cos(convert_to_radian(d)) * h);
}

double	find_x(double d, double h)
{
	return (sin(convert_to_radian(d)) * h);
}
