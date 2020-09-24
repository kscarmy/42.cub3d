/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2020/01/31 12:45:33 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void    ft_set_world_spawn(m_point *map, int u)
{
    if (map->spawn != '0')
    {
        map->x = u;
        map->error = 830;
    }
    else
        map->spawn = map->file[u];
}

int     ft_is_not_map(char c, int one)
{
    int m;



    m = 0;
    if (c == '1' && one == 1)
        m++;
    if (c == '0')
        m++;
    if (c == '2')
        m++;
    if (c == ' ' && one == 1)
        m++;
    if (c == '\n' && one == 1)
        m++;
    if (c == '\t' && one == 1)
        m++;
    if (c == 'N')
        m++;
    if (c == 'S')
        m++;
    if (c == 'E')
        m++;
    if (c == 'W')
        m++;
    return (m);
}