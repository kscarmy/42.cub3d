/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2022/07/17 02:56:21 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_incre_spaces(m_point *map, int backn, int h) // retourne u espaces rencontré dans map->fil[map->x + h] ou h est un head
{
	int u;

	u = 0;
	while (ft_is_space(map->file[map->x + u + h], backn, 0, map) > 0)
		u++;
	return (u);
}

int		ft_is_space(char c, int backn, int end, m_point *map)
{
	int x;

	x = 0;
	map->error = map->error; // A SUPPRIMER
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

int		ft_is_color(int color) // Si color faux return 1, sinon 0
{
	if (color >= 0 && color <= 255)
		return (0);
	return (1);
}

