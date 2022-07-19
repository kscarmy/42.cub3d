/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_parsing_map_utils.c							 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: guderram <guderram@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/31 12:45:32 by guderram		  #+#	#+#			 */
/*   Updated: 2022/07/19 16:47:43 by guderram		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_set_world_spawn(m_point *m, int u)
{
	if (m->spawn != '0')
	{
		m->x = u;
		m->er = 830;
	}
	else
		m->spawn = m->fl[u];
}

int	ft_is_not_map(char c, int one)
{
	int	m;

	m = 0;
	if (c == '1' && one == 1)
		m++;
	if (c == '0')
		m++;
	if (c == '2')
		m++;
	if (c == ' ' && one == 1)
		m++;
	if (c == '\n' && one == 1)
		m++;
	if (c == '\t' && one == 1)
		m++;
	if (c == 'N')
		m++;
	if (c == 'S')
		m++;
	if (c == 'E')
		m++;
	if (c == 'W')
		m++;
	return (m);
}

int	ft_next_zero_char(char c)
{
	int	x;

	x = 0;
	if (c == '0')
		x++;
	if (c == '1')
		x++;
	if (c == '2')
		x++;
	if (c == 'N')
		x++;
	if (c == 'S')
		x++;
	if (c == 'E')
		x++;
	if (c == 'W')
		x++;
	return (x);
}

void	ft_next_zero_map(m_point *m, int l, int x)
{
	if (l == 0 || l == m->l - 1)
		m->er = 970;
	if (m->er == 0 && ft_next_zero_char(m->map[l - 1][x - 1]) == 0)
		ft_map_disp_error(m, l - 1, x - 1, 960);
	if (m->er == 0 && ft_next_zero_char(m->map[l - 1][x]) == 0)
		ft_map_disp_error(m, l - 1, x, 961);
	if (m->er == 0 && ft_next_zero_char(m->map[l - 1][x + 1]) == 0)
		ft_map_disp_error(m, l - 1, x + 1, 962);
	if (m->er == 0 && ft_next_zero_char(m->map[l][x - 1]) == 0)
		ft_map_disp_error(m, l, x - 1, 963);
	if (m->er == 0 && ft_next_zero_char(m->map[l][x + 1]) == 0)
		ft_map_disp_error(m, l, x + 1, 964);
	if (m->er == 0 && ft_next_zero_char(m->map[l + 1][x - 1]) == 0)
		ft_map_disp_error(m, l + 1, x - 1, 965);
	if (m->er == 0 && ft_next_zero_char(m->map[l + 1][x]) == 0)
		ft_map_disp_error(m, l + 1, x, 966);
	if (m->er == 0 && ft_next_zero_char(m->map[l + 1][x + 1]) == 0)
		ft_map_disp_error(m, l + 1, x + 1, 967);
	if (m->er == 970)
		ft_map_disp_error(m, l, x, 970);
}
