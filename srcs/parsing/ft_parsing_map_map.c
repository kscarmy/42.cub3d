/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_parsing_map_map.c							   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: guderram <guderram@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/31 12:45:32 by guderram		  #+#	#+#			 */
/*   Updated: 2022/07/19 16:42:18 by guderram		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_create_mapping_bis(m_point *m, int u)
{
	while (m->fl[u] == ' ' || m->fl[u] == '\t' || m->fl[u] == '\n')
		u++;
	if (m->fl[u] != '\0')
		m->er = 840;
	m->map = (char **)malloc(sizeof(char *) * (m->l + 1));
	if (m->map == NULL)
		m->er = 1100;
	if (m->map == NULL)
		return ;
	m->map[m->l] = NULL;
	u = 0;
	while (u < m->l)
	{
		m->map[u] = (char *)malloc(sizeof(char) * 1);
		m->map[u][0] = '\0';
		u++;
	}
}

void	ft_create_mapping(m_point *m)
{
	int	u;
	int	one;

	u = m->x;
	one = 0;
	while (m->fl[u] != '\0')
	{
		if (m->fl[u] == '\n' && one == 0 && u != m->x)
			break ;
		if (m->fl[u] == '1')
			one++;
		if (m->fl[u] == '\n' && one > 0)
			m->l = m->l + 1;
		if (m->fl[u] == '\n')
			one = 0;
		u++;
	}
	ft_create_mapping_bis(m, u);
}

void	ft_found_map_bis(m_point *m, int u)
{
	while (m->er == 0 && m->fl[u] != '\0')
	{
		if (ft_is_not_map(m->fl[u], 1) == 0)
			m->er = 820;
		if (m->fl[u] == 'N' || m->fl[u] == 'S'
			|| m->fl[u] == 'E' || m->fl[u] == 'W')
			ft_set_world_spawn(m, u);
		u++;
	}
}

void	ft_found_map(m_point *m)
{
	int	u;
	int	back;

	u = m->x;
	back = u;
	while (m->er == 0 && m->fl[u] != '\0' && m->fl[u] != '1')
	{
		if (m->fl[u] == '1' && m->fl[u] == ' '
			&& m->fl[u] == '\n' && m->fl[u] == '\t')
			m->er = 810;
		if (m->fl[u] == '\n')
			back = u;
		u++;
	}
	if (m->fl[u] == '\0')
		m->er = 800;
	u = m->x;
	m->x = back;
	ft_found_map_bis(m, u);
}

void	ft_fill_map(m_point *m)
{
	int	u;

	u = 0;
	while (m->fl[m->x] != '\n')
		m->x = m->x - 1;
	while (u < m->l)
	{
		ft_fill_line_map(m, u);
		u++;
	}
}
