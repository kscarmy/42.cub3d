/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_structs.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: guderram <guderram@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/31 12:45:32 by guderram		  #+#	#+#			 */
/*   Updated: 2022/07/19 16:52:28 by guderram		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/libft.h"

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
	m->s = NULL;
	m->map = NULL;
}

void	ft_disp_verif(m_point *m)
{
	int	u;

	u = 0;
	ft_printf("R : '%d' : '%d','%d'\n", m->res, m->rx, m->ry);
	ft_printf("NO : '%s'\n", m->no);
	ft_printf("SO : '%s'\n", m->so);
	ft_printf("WE : '%s'\n", m->we);
	ft_printf("EA : '%s'\n", m->ea);
	ft_printf("S : '%s'\n", m->s);
	ft_printf("F : '%d' : '%d','%d','%d'\n", m->floor, m->fr, m->fg, m->fb);
	ft_printf("C : '%d' : '%d','%d','%d'\n", m->ceiling, m->cr, m->cg, m->cb);
	ft_printf("Spawn : %c\n", m->spawn);
	while (u < m->l)
	{
		printf("'%s'\n", m->map[u]);
		u++;
	}
}

void	ft_exit_free_map_paths(m_point *m)
{
	if (m->no != NULL)
		ft_gnl_strdel(&m->no);
	if (m->so != NULL)
		ft_gnl_strdel(&m->so);
	if (m->we != NULL)
		ft_gnl_strdel(&m->we);
	if (m->ea != NULL)
		ft_gnl_strdel(&m->ea);
	if (m->s != NULL)
		ft_gnl_strdel(&m->s);
	if (m->fl != NULL)
		ft_gnl_strdel(&m->fl);
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
	ft_exit_free_map_paths(m);
	ft_printf("\n\033[0m<Les mallocs ont ete clears>\n");
	ft_disp_verif(m);
	return (ret);
}
