/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:05:01 by mourdani          #+#    #+#             */
/*   Updated: 2022/07/31 09:22:01 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
// Convert to radian
// Return Double

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
