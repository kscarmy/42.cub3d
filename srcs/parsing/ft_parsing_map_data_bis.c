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

void	ft_parsing_path_to_bis(m_point *m, int y, int z)
{
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

void	ft_parsing_path_to(m_point *m)
{
	int	z;
	int	y;

	y = m->x;
	z = 2;
	if (m->fl[m->x] == 'S' && m->fl[m->x + 1] == ' ')
		z = 1;
	z = z + ft_incre_spaces(m, 0, z);
	if (m->no != NULL && m->fl[m->x] == 'N' && m->fl[m->x + 1] == 'O')
		m->er = 600;
	if (m->so != NULL && m->fl[m->x] == 'S' && m->fl[m->x + 1] == 'O')
		m->er = 610;
	if (m->we != NULL && m->fl[m->x] == 'W' && m->fl[m->x + 1] == 'E')
		m->er = 620;
	if (m->ea != NULL && m->fl[m->x] == 'E' && m->fl[m->x + 1] == 'A')
		m->er = 630;
	if (m->s != NULL && m->fl[m->x] == 'S' && m->fl[m->x + 1] == ' ')
		m->er = 640;
	ft_parsing_path_to_bis(m, y, z);
}
