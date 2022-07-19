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

#include "../../includes/libft.h"

void	ft_check_fl_half(m_point *m)
{
	if (m->res == 0)
		m->er = 700;
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
	if (m->s == NULL)
		m->er = 735;
}

void	ft_strfreejoin_newline(m_point *m, char *buff)
{
	char	*tmp;
	int		i;
	int		u;

	i = 0;
	u = 0;
	tmp = m->fl;
	m->fl = malloc (sizeof(char) * (ft_gnl_strlen(tmp) + ft_gnl_strlen(buff) + 2));
	if ((m->er = (m->fl == NULL) ? 1010 : m->er) == 0)
	{
		while (tmp != NULL && tmp[i] != '\0')
		{
			m->fl[i] = tmp[i];
			i++;
		}
		while (buff[u] != '\0')
		{
			m->fl[i + u] = buff[u];
			u++;
		}
		m->fl[i + u] = '\n';
		m->fl[i + u + 1] = '\0';
	}
	ft_gnl_strdel(&tmp);
}

void	ft_parsing_open_fd(m_point *m, char *argv)
{
	int		ret;
	int		fd;
	char	*buff;

	ret = 0;
	buff = NULL;
	fd = open(argv, O_RDONLY);
	while ((ret = ft_get_next_line(fd, &buff)) > 0)
	{
		ft_strfreejoin_newline(m, buff);
		ft_gnl_strdel(&buff);
	}
	ft_strfreejoin_newline(m, buff);
	ft_gnl_strdel(&buff);
	close(fd);
	if (fd == -1)
		m->er = 15;
	if (ret != 0)
		m->er = 20;
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
		if ((((m->fl[m->x] == 'N' && m->fl[m->x + 1] == 'O') || (m->fl[m->x] == 'S' && m->fl[m->x + 1] == 'O') || (m->fl[m->x] == 'W' && m->fl[m->x + 1] == 'E') || (m->fl[m->x] == 'E' && m->fl[m->x + 1] == 'A')) && m->fl[m->x + 2] == ' ') || (m->fl[m->x] == 'S' && m->fl[m->x + 1] == ' '))
			ft_parsing_path_to(m);
		i++;
	}
	(m->er == 0) ? ft_check_fl_half(m) : ft_printf("er BEFORE MAPING\n");
	if (m->er == 0)
		ft_check_map(m);
	if (m->er > 0)
		ft_error_detected(m);
	return ((m->er == 0) ? 1 : ft_exit_free_map(m, -1));
	return (1);
}
