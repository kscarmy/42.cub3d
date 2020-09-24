/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2020/01/31 12:45:33 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_init_map(m_point *map)
{
	map->error = 0;
	map->rx = 0;
	map->ry = 0;
	map->x = 0;
	map->res = 0;
	map->floor = 0;
	map->fr = 0;
	map->fg = 0;
	map->fb = 0;
	map->ceiling = 0;
	map->cr = 0;
	map->cg = 0;
	map->cb = 0;
	map->spawn = '0';
	map->l = 0;
	map->file = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->s = NULL;
	map->map = NULL; // TEST
}

void	ft_disp_verif(m_point *map)
{
	int u;
	// int i;

	u = 0;
	// i = 0;
	ft_printf("R : '%d' : '%d','%d'\n", map->res, map->rx, map->ry);
	ft_printf("NO : '%s'\n", map->no);
	ft_printf("SO : '%s'\n", map->so);
	ft_printf("WE : '%s'\n", map->we);
	ft_printf("EA : '%s'\n", map->ea);
	ft_printf("S : '%s'\n", map->s);
	ft_printf("F : '%d' : '%d','%d','%d'\n", map->floor, map->fr, map->fg, map->fb);
	ft_printf("C : '%d' : '%d','%d','%d'\n", map->ceiling, map->cr, map->cg, map->cb);
	ft_printf("Spawn : %c\n", map->spawn);
	ft_printf("\n\n L = '%d\n\n", map->l);
	ft_printf("l === '%d'\n", map->l);
	// printf("BON : '%s'\n", map->map[0]);
	while (u < map->l) // AFFICHAGE DE LA MAP BUGGER
	{
		// i = 0;
		// while (map->map[u][i])
		// {
		// 	ft_printf("%s", (map->map[u]));
		// 	i++;
		// }
		// ft_printf("\n");
		// printf("'%s'\n", map->map[u]);
		u++;
	}
}

int		ft_exit_free_map(m_point *map, int ret)
{
	int i;

	i = 0;
	while (i < map->l)
	{
		free(map->map[i]);
		map->map[i] = NULL;
		i++;
	}
	ft_printf("ptn %d\n", map->l);
	if (map->map != NULL)
	{
		free(map->map);
		map->map = NULL;
		map->l = 0;
	}
	ft_printf("ptn %d\n", map->l);
	if (map->no != NULL)
		ft_gnl_strdel(&map->no);
	if (map->so != NULL)
		ft_gnl_strdel(&map->so);
	if (map->we != NULL)
		ft_gnl_strdel(&map->we);
	if (map->ea != NULL)
		ft_gnl_strdel(&map->ea);
	if (map->s != NULL)
		ft_gnl_strdel(&map->s);
	if (map->file != NULL)
		ft_gnl_strdel(&map->file);
	ft_printf("\n\033[0m<Les mallocs ont ete clears>\n");
	// ft_disp_verif(map);
	return (ret);
}
