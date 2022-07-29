/* ************************************************************************** */
<<<<<<< HEAD
/*																			*/
/*														:::	  ::::::::   */
/*   ft_structs.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: guderram <guderram@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/31 12:45:32 by guderram		  #+#	#+#			 */
/*   Updated: 2022/07/19 16:52:28 by guderram		 ###   ########.fr	   */
/*																			*/
=======
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2022/07/17 03:24:47 by mourdani         ###   ########.fr       */
/*                                                                            */
>>>>>>> moves
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_map(m_point *m)
{
	m->er = 0;
	m->rx = 0;
	m->ry = 0;
	m->x = 0;
	m->res = 0;
	m->floor = 0;
	m->fr = 0;
	m->fg = 0;
	m->fb = 0;
	m->ceiling = 0;
	m->cr = 0;
	m->cg = 0;
	m->cb = 0;
	m->spawn = '0';
	m->l = 0;
	m->fl = NULL;
	m->no = NULL;
	m->so = NULL;
	m->we = NULL;
	m->ea = NULL;
	m->map = NULL;
}

void	ft_disp_verif(m_point *m)
{
	int	u;

	u = 0;
	printf("R : '%d' : '%d','%d'\n", m->res, m->rx, m->ry);
	printf("NO : '%s'\n", m->no);
	printf("SO : '%s'\n", m->so);
	printf("WE : '%s'\n", m->we);
	printf("EA : '%s'\n", m->ea);
	printf("F : '%d' : '%d','%d','%d'\n", m->floor, m->fr, m->fg, m->fb);
	printf("C : '%d' : '%d','%d','%d'\n", m->ceiling, m->cr, m->cg, m->cb);
	printf("Spawn : %c\n", m->spawn);
	while (u < m->l)
	{
		printf("'%s'\n", m->map[u]);
		u++;
	}
}

void	ft_exit_free_map_paths(m_point *m)
{
	if (m->no != NULL)
		ft_strdel(&m->no);
	if (m->so != NULL)
		ft_strdel(&m->so);
	if (m->we != NULL)
		ft_strdel(&m->we);
	if (m->ea != NULL)
		ft_strdel(&m->ea);
	if (m->fl != NULL)
		ft_strdel(&m->fl);
}

int	ft_exit_free_map(m_point *m, int ret)
{
	int	i;

	i = 0;
	while (i < m->l)
	{
		free(m->map[i]);
		m->map[i] = NULL;
		i++;
	}
	if (m->map != NULL)
	{
		free(m->map);
		m->map = NULL;
		m->l = 0;
	}
<<<<<<< HEAD
	ft_exit_free_map_paths(m);
	printf("\n\033[0m<Les mallocs ont ete clears>\n");
	ft_disp_verif(m);
=======
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
>>>>>>> moves
	return (ret);
}
