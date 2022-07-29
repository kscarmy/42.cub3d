/* ************************************************************************** */
<<<<<<< HEAD
/*																			*/
/*														:::	  ::::::::   */
/*   ft_parsing_utils.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: guderram <guderram@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/31 12:45:32 by guderram		  #+#	#+#			 */
/*   Updated: 2022/07/19 16:52:54 by guderram		 ###   ########.fr	   */
/*																			*/
=======
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2022/07/17 02:56:21 by mourdani         ###   ########.fr       */
/*                                                                            */
>>>>>>> moves
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_incre_spaces(m_point *m, int backn, int h)
{
	int	u;

	u = 0;
	while (ft_is_space(m->fl[m->x + u + h], backn, 0, m) > 0)
		u++;
	return (u);
}

int	ft_is_space(char c, int backn, int end, m_point *m)
{
	int	x;

	x = 0;
<<<<<<< HEAD
	m->er = m->er;
=======
	map->error = map->error; // A SUPPRIMER
>>>>>>> moves
	if (c == ' ')
		x++;
	if (c == '\n' && backn == 1)
		x++;
	if (c == '\t')
		x++;
	if (c == '\0' && end == 1)
		x++;
	return (x);
}

int	ft_is_color(int color)
{
	if (color >= 0 && color <= 255)
		return (0);
	return (1);
}
