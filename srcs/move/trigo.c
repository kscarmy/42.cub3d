/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 08:19:38 by guderram          #+#    #+#             */
/*   Updated: 2022/08/06 08:20:25 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
soh cah toa

adjacent : b
opposite : a
hypotenus : h


sinus     = a / h
cosinus   = b / h
tan       = a / b
*/

// M_PI = pi (3.141592..)
double	convert_to_radian(double degree)
{
	return (degree * (M_PI / 180.0));
}

// b = cosinus * h 
double	find_y(double d, double h)
{
	return (cos(convert_to_radian(d)) * h);
}

// a = sinus * h
double	find_x(double d, double h)
{
	return (sin(convert_to_radian(d)) * h);
}
