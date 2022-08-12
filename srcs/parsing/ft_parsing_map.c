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

void	ft_check_fl_half(t_m_point *m)
{
	if (m->floor == 0)
		m->er = 705;
	if (m->ceiling == 0)
		m->er = 710;
	if (m->no == NULL)
		m->er = 715;
	if (m->so == NULL)
		m->er = 720;
	if (m->we == NULL)
		m->er = 725;
	if (m->ea == NULL)
		m->er = 730;
}

void	ft_strfreejoin_newline_bis(t_m_point *m, char *buff, int i, int u)
{
	while (buff[u] != '\0')
	{
		m->fl[i + u] = buff[u];
		u++;
	}
	m->fl[i + u] = '\n';
	m->fl[i + u + 1] = '\0';
}

void	ft_strfreejoin_newline(t_m_point *m, char *buff)
{
	char	*tmp;
	int		i;
	int		u;

	i = 0;
	u = 0;
	tmp = m->fl;
	m->fl = malloc (sizeof(char)
			* (ft_strlen(tmp) + ft_strlen(buff) + 2));
	if (m->fl == NULL)
		m->er = 1010;
	if (m->er != 0)
		return ;
	while (tmp != NULL && tmp[i] != '\0')
	{
		m->fl[i] = tmp[i];
		i++;
	}
	ft_strfreejoin_newline_bis(m, buff, i, u);
	ft_strdel(&tmp);
}

void	ft_parsing_open_fd(t_m_point *m, char *argv)
{
	int		ret;
	int		fd;
	char	*buff;

	ret = 0;
	buff = NULL;
	fd = open(argv, O_RDONLY);
	ret = get_next_line(fd, &buff);
	while (ret > 0)
	{
		ft_strfreejoin_newline(m, buff);
		ft_strdel(&buff);
		ret = get_next_line(fd, &buff);
	}
	ft_strfreejoin_newline(m, buff);
	ft_strdel(&buff);
	close(fd);
	if (fd == -1)
		m->er = 15;
	if (ret != 0)
		m->er = 20;
}
