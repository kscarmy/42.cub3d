/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_parsing_map.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: guderram <guderram@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/31 12:45:32 by guderram		  #+#	#+#			 */
/*   Updated: 2022/07/19 16:50:50 by guderram		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_parsing_map_bis(m_point *m)
{
	if (m->er == 0)
		ft_check_fl_half(m);
	else
		printf("er BEFORE MAPING\n");
	if (m->er == 0)
		ft_check_map(m);
	if (m->er > 0)
		ft_error_detected(m);
	if (m->er == 0)
		return (1);
	return (ft_exit_free_map(m, -1));
}

int	ft_parsing_map(m_point *m, char *argv)
{
	int	i;

	i = 0;
	ft_parsing_open_fd(m, argv);
	while (m->er == 0 && m->fl[m->x] != '\0' && i < 8)
	{
		m->x = ft_incre_spaces(m, 1, 0) + m->x;
		if (m->fl[m->x] == 'R')
			ft_parsing_resolution(m);
		if (m->fl[m->x] == 'F')
			ft_parsing_floor(m);
		if (m->fl[m->x] == 'C')
			ft_parsing_ceiling(m);
		if ((((m->fl[m->x] == 'N' && m->fl[m->x + 1] == 'O')
					|| (m->fl[m->x] == 'S' && m->fl[m->x + 1] == 'O')
					|| (m->fl[m->x] == 'W' && m->fl[m->x + 1] == 'E')
					|| (m->fl[m->x] == 'E' && m->fl[m->x + 1] == 'A'))
				&& m->fl[m->x + 2] == ' ')
			|| (m->fl[m->x] == 'S' && m->fl[m->x + 1] == ' '))
			ft_parsing_path_to(m);
		i++;
	}
	return (ft_parsing_map_bis(m));
}
