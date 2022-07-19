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

#include "../../includes/libft.h"

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
		one = (m->fl[u] == '\n') ? 0 : one;
		u++;
	}
	while (m->fl[u] == ' ' || m->fl[u] == '\t' || m->fl[u] == '\n')
		u++;
	m->er = (m->fl[u] == '\0') ? m->er : 840;
	m->map = (char **)malloc(sizeof(char *) * (m->l + 1));
	m->er = (m->map == NULL) ? 1100 : m->er;
	m->map[m->l] = NULL;
	u = 0;
	while (u < m->l)
	{
		m->map[u] = (char *)malloc(sizeof(char) * 1); // comme ça je leaks ...
		m->map[u][0] = '\0';
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
		if (m->fl[u] == '1' && m->fl[u] == ' ' && m->fl[u] == '\n' && m->fl[u] == '\t')
			m->er = 810;
		if (m->fl[u] == '\n')
			back = u;
		u++;
	}
	m->er = (m->fl[u] == '\0') ? 800 : m->er;
	u = m->x;
	m->x = back;
	while (m->er == 0 && m->fl[u] != '\0')
	{
		if (ft_is_not_map(m->fl[u], 1) == 0)
			m->er = 820;
		if (m->fl[u] == 'N' || m->fl[u] == 'S' || m->fl[u] == 'E' || m->fl[u] == 'W')
			ft_set_world_spawn(m, u);
		u++;
	}
}

void	ft_fill_map(m_point *m)
{
	int	u;

	u = 0;
	while (u < m->l)
	{
		ft_fill_line_map(m, u);
		u++;
	}
}

void	ft_fill_line_map(m_point *m, int l) // l est la ligne à malloc :)
{
	int	u;

	u = 1;
	while (m->fl[m->x + u] != '\n' && m->fl[m->x + u] != '\0')
		u++;
	ft_gnl_strdel(&(m->map[l])); // TEST 123
	m->map[l] = (char*)malloc(sizeof(char) * (u));
	m->er = (m->map[l] == NULL) ? 1200 + l : m->er;
	m->map[l][u - 1] = '\0';
	u = 1;
	while (m->fl[m->x + u] != '\n' && m->fl[m->x + u] != '\0')
	{
		m->map[l][u - 1] = m->fl[m->x + u];
		u++;
	}
	m->map[l][u - 1] = '\0';
	m->x = m->x + u;
}

void	ft_parse_map(m_point *m)
{
	int	l;
	int	x;

	l = 0;
	x = 0;
	while (m->map[0][x] != '\0' && m->map[0][x] != '0' && m->map[0][x] != '2')
		x++;
	m->er = (m->map[0][x] == '\0' || m->map[0][x] != '2') ? m->er : 950;
	x = 0;
	while (m->map[m->l - 1][x] != '\0' && m->map[m->l - 1][x] != '0' && m->map[m->l - 1][x] != '2')
		x++;
	m->er = (m->map[m->l - 1][x] == '\0' || m->map[m->l - 1][x] != '2') ? m->er : 955;
	x = 0;
	while (m->er == 0 && m->map != NULL && m->map[l] != NULL)
	{
		while (m->er == 0 && m->map[l][x] != '\0')
		{
			if (ft_is_not_map(m->map[l][x], 0) == 1)
				ft_next_zero_map(m, l, x);
			if ((m->map[l][x] == '0' && m->er == 0) || (m->map[l][x] == '2' && m->er == 0))
				ft_next_zero_map(m, l, x);
			x++;
		}
		x = 0;
		l++;
	}
}

void	ft_check_map(m_point *m) // call toutes les merdes pour la map
{
	if (m->er == 0)
		ft_found_map(m);
	if (m->er == 0)
		ft_create_mapping(m);
	if (m->er == 0)
		ft_fill_map(m);
	if (m->er == 0)
		ft_parse_map(m);
}
