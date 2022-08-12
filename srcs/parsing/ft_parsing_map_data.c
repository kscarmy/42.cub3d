/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_parsing_m_data.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: guderam <guderam@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/31 12:45:32 by guderam		  #+#	#+#			 */
/*   Updated: 2022/06/14 12:48:49 by guderam		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	ft_parsing_resolution(t_m_point *m)
// {
// 	int	z;

// 	z = 1;
// 	if (m->res == 0)
// 	{
// 		z = z + ft_incre_spaces(m, 0, z);
// 		// m->rx = ft_atoi((&m->fl[m->x + z]));
// 		while (ft_isdigit(m->fl[m->x + z]) == 1)
// 			z++;
// 		m->ry = ft_atoi((&m->fl[m->x + z]));
// 		z = z + ft_incre_spaces(m, 0, z);
// 		while (ft_isdigit(m->fl[m->x + z]) == 1)
// 			z++;
// 		z = z + ft_incre_spaces(m, 0, z);
// 		m->x = m->x + z;
// 		if (m->fl[m->x] != '\n' || m->rx <= 0 || m->ry <= 0)
// 			m->er = 505;
// 		m->res = 1;
// 	}
// 	else
// 		m->er = 500;
// }

int	ft_parsing_while(t_m_point *m, int z)
{
	while (ft_isdigit(m->fl[m->x + z]) == 1)
		z++;
	return (z);
}

void	ft_parsing_floor(t_m_point *m)
{
	int	z;

	z = 1;
	if (m->floor != 0)
		m->er = 510;
	if (m->floor != 0)
		return ;
	z = z + ft_incre_spaces(m, 0, z);
	m->fr = ft_atoi((&m->fl[m->x + z]));
	z = ft_parsing_while(m, z);
	if (m->fl[m->x + z] == ',')
		z++;
	m->fg = ft_atoi((&m->fl[m->x + z]));
	z = ft_parsing_while(m, z);
	if (m->fl[m->x + z] == ',')
		z++;
	m->fb = ft_atoi((&m->fl[m->x + z]));
	z = ft_parsing_while(m, z);
	z = z + ft_incre_spaces(m, 0, z);
	m->x = m->x + z;
	if (m->fl[m->x] != '\n' || ft_is_color(m->fr)
		|| ft_is_color(m->fg) || ft_is_color(m->fb))
		m->er = 515;
	m->floor = 1;
}

void	ft_parsing_ceiling(t_m_point *m)
{
	int	z;

	z = 1;
	if (m->ceiling != 0)
		m->er = 520;
	if (m->ceiling != 0)
		return ;
	z = z + ft_incre_spaces(m, 0, z);
	m->cr = ft_atoi((&m->fl[m->x + z]));
	z = ft_parsing_while(m, z);
	if (m->fl[m->x + z] == ',')
		z++;
	m->cg = ft_atoi((&m->fl[m->x + z]));
	z = ft_parsing_while(m, z);
	if (m->fl[m->x + z] == ',')
		z++;
	m->cb = ft_atoi((&m->fl[m->x + z]));
	z = ft_parsing_while(m, z);
	z = z + ft_incre_spaces(m, 0, z);
	m->x = m->x + z;
	if (m->fl[m->x] != '\n' || ft_is_color(m->cr)
		|| ft_is_color(m->cg) || ft_is_color(m->cb))
		m->er = 525;
	m->ceiling = 1;
}

char	*ft_parsing_get_path(t_m_point *m, int z)
{
	char	*str;
	int		u;
	int		k;

	u = 0;
	k = 0;
	while (ft_is_space(m->fl[m->x + z + u], 1, 1, m) == 0)
		u++;
	str = malloc(sizeof(char) * (u + 1));
	if (str == NULL)
		m->er = 1010;
	if (str == NULL)
		return (NULL);
	while (m->er == 0 && k < u)
	{
		str[k] = m->fl[m->x + z + k];
		k++;
	}
	str[k] = '\0';
	if (ft_check_open(str) == 1)
		m->er = 900;
	if (m->er == 0)
		m->x = m->x + z + u;
	return (str);
}
