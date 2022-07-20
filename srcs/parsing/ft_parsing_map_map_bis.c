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

void	ft_fill_line_map(m_point *m, int l)
{
	int	u;

	u = 1;
	while (m->fl[m->x + u] != '\n' && m->fl[m->x + u] != '\0')
		u++;
	ft_gnl_strdel(&(m->map[l]));
	m->map[l] = (char *)malloc(sizeof(char) * (u));
	if (m->map[l] == NULL)
		m->er = 1200 + l;
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

void	ft_parse_map_bis(m_point *m, int l, int x)
{
	while (m->er == 0 && m->map != NULL && m->map[l] != NULL)
	{
		while (m->er == 0 && m->map[l][x] != '\0')
		{
			if (ft_is_not_map(m->map[l][x], 0) == 1)
				ft_next_zero_map(m, l, x);
			if ((m->map[l][x] == '0' && m->er == 0)
				|| (m->map[l][x] == '2' && m->er == 0))
				ft_next_zero_map(m, l, x);
			x++;
		}
		x = 0;
		l++;
	}
}

void	ft_parse_map(m_point *m)
{
	int	l;
	int	x;

	l = 0;
	x = 0;
	while (m->map[0][x] != '\0' && m->map[0][x] != '0' && m->map[0][x] != '2')
		x++;
	if (m->map[0][x] != '\0' || m->map[0][x] == '2')
		m->er = 950;
	x = 0;
	while (m->map[m->l - 1][x] != '\0' && m->map[m->l - 1][x]
		!= '0' && m->map[m->l - 1][x] != '2')
		x++;
	if (m->map[m->l - 1][x] != '\0' || m->map[m->l - 1][x] == '2')
	m->er = 955;
	x = 0;
	ft_parse_map_bis(m, l, x);
}

void	ft_check_map(m_point *m)
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
