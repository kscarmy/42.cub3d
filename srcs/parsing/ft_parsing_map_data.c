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

#include "../../includes/libft.h"

void	ft_parsing_resolution(m_point *m)
{
	int	z;

	z = 1;
	if (m->res == 0)
	{
		z = z + ft_incre_spaces(m, 0, z);
		m->rx = ft_atoi((&m->fl[m->x + z])); // donne une valeur à rx
		while (ft_isdigit(m->fl[m->x + z]) == 1) // bouge le head jusqu'au prochain int
			z++;
		m->ry = ft_atoi((&m->fl[m->x + z])); // donne une valeur à ry
		z = z + ft_incre_spaces(m, 0, z);
		while (ft_isdigit(m->fl[m->x + z]) == 1) // bouge le head jusqu'au prochain int
			z++;
		z = z + ft_incre_spaces(m, 0, z);
		m->x = m->x + z;
		if (m->fl[m->x] != '\n' || m->rx <= 0 || m->ry <= 0)
			m->er = 505;
		m->res = 1;
	}
	else
		m->er = 500;
}

void	ft_parsing_floor(m_point *m)
{
	int	z;

	z = 1;
	if (m->floor == 0)
	{
		z = z + ft_incre_spaces(m, 0, z);
		m->fr = ft_atoi((&m->fl[m->x + z])); // Floor Red
		while (ft_isdigit(m->fl[m->x + z]) == 1) // bouge le head jusqu'au prochain int
			z++;
		z = (m->fl[m->x + z] == ',') ? z + 1 : z;
		m->fg = ft_atoi((&m->fl[m->x + z])); // Floor Green
		while (ft_isdigit(m->fl[m->x + z]) == 1) // bouge le head jusqu'au prochain int
			z++;
		z = (m->fl[m->x + z] == ',') ? z + 1 : z;
		m->fb = ft_atoi((&m->fl[m->x + z])); // Floor Blue
		while (ft_isdigit(m->fl[m->x + z]) == 1) // bouge le head jusqu'au prochain int
			z++;
		z = z + ft_incre_spaces(m, 0, z);
		m->x = m->x + z;
		if (m->fl[m->x] != '\n' || ft_is_color(m->fr) || ft_is_color(m->fg) || ft_is_color(m->fb))
			m->er = 515;
		m->floor = 1;
	}
	else
		m->er = 510;
}

void	ft_parsing_ceiling(m_point *m)
{
	int	z;

	z = 1;
	if (m->ceiling == 0)
	{
		z = z + ft_incre_spaces(m, 0, z);
		m->cr = ft_atoi((&m->fl[m->x + z])); // Ceiling Red
		while (ft_isdigit(m->fl[m->x + z]) == 1) // bouge le head jusqu'au prochain int
			z++;
		z = (m->fl[m->x + z] == ',') ? z + 1 : z;
		m->cg = ft_atoi((&m->fl[m->x + z])); // Ceiling Green
		while (ft_isdigit(m->fl[m->x + z]) == 1) // bouge le head jusqu'au prochain int
			z++;
		z = (m->fl[m->x + z] == ',') ? z + 1 : z;
		m->cb = ft_atoi((&m->fl[m->x + z])); // Ceiling Blue
		while (ft_isdigit(m->fl[m->x + z]) == 1) // bouge le head jusqu'au prochain int
			z++;
		z = z + ft_incre_spaces(m, 0, z);
		m->x = m->x + z;
		if (m->fl[m->x] != '\n' || ft_is_color(m->cr) || ft_is_color(m->cg) || ft_is_color(m->cb))
			m->er = 525;
		m->ceiling = 1;
	}
	else
		m->er = 520;
}

char	*ft_parsing_get_path(m_point *m, int z)
{
	char	*str;
	int		u;
	int		k;

	u = 0;
	k = 0;
	while (ft_is_space(m->fl[m->x + z + u], 1, 1, m) == 0)
		u++;
	str = malloc(sizeof(char) * (u + 1));
	if ((m->er = (str == NULL) ? 1010 : m->er) != 0)
		return (NULL);
	while (m->er == 0 && k < u)
	{
		str[k] = m->fl[m->x + z + k];
		k++;
	}
	str[k] = '\0';
	// ft_printf("alors ?\n");
	m->er = (ft_check_open(str) == 1) ? 900 : m->er;
	m->x = (m->er == 0) ? m->x + z + u : m->x;
	return (str);
}

void	ft_parsing_path_to(m_point *m)
{
	int	z;
	int	y;

	y = m->x;
	z = (m->fl[m->x] == 'S' && m->fl[m->x + 1] == ' ') ? 1 : 2;
	z = z + ft_incre_spaces(m, 0, z);
	m->er = (m->no != NULL && m->fl[m->x] == 'N' && m->fl[m->x + 1] == 'O') ? 600 : m->er; //check si déjà alloué
	m->er = (m->so != NULL && m->fl[m->x] == 'S' && m->fl[m->x + 1] == 'O') ? 610 : m->er;
	m->er = (m->we != NULL && m->fl[m->x] == 'W' && m->fl[m->x + 1] == 'E') ? 620 : m->er;
	m->er = (m->ea != NULL && m->fl[m->x] == 'E' && m->fl[m->x + 1] == 'A') ? 630 : m->er;
	m->er = (m->s != NULL && m->fl[m->x] == 'S' && m->fl[m->x + 1] == ' ') ? 640 : m->er;
	if (m->er == 0 && m->fl[y] == 'N' && m->fl[y + 1] == 'O')
		m->no = ft_parsing_get_path(m, z);
	if (m->er == 0 && m->fl[y] == 'S' && m->fl[y + 1] == 'O')
		m->so = ft_parsing_get_path(m, z);
	if (m->er == 0 && m->fl[y] == 'W' && m->fl[y + 1] == 'E')
		m->we = ft_parsing_get_path(m, z);
	if (m->er == 0 && m->fl[y] == 'E' && m->fl[y + 1] == 'A')
		m->ea = ft_parsing_get_path(m, z);
	if (m->er == 0 && m->fl[y] == 'S' && m->fl[y + 1] == ' ')
		m->s = ft_parsing_get_path(m, z);
}
