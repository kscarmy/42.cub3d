/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2022/06/14 14:25:56 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void    ft_check_file_half(m_point *map)
{
    if (map->res == 0)
        map->error = 700;
    if (map->floor == 0)
        map->error = 705;
    if (map->ceiling == 0)
        map->error = 710;
    if (map->no == NULL)
        map->error = 715;
    if (map->so == NULL)
        map->error = 720;
    if (map->we == NULL)
        map->error = 725;
    if (map->ea == NULL)
        map->error = 730;
    if (map->s == NULL)
        map->error = 735;
}

void	ft_strfreejoin_newline(m_point *map, char *buff)
{
	char	*tmp;
	int		i;
    int u;

	i = 0;
    u = 0;
	tmp = map->file;
	map->file = malloc (sizeof(char) * (ft_gnl_strlen(tmp) + ft_gnl_strlen(buff) + 2));
	if ((map->error = (map->file == NULL) ? 1010 : map->error) == 0)
	{
		while (tmp != NULL && tmp[i] != '\0')
		{
			map->file[i] = tmp[i];
			i++;
		}
        while (buff[u] != '\0')
        {
            map->file[i + u] = buff[u];
            u++;
        }
		map->file[i + u] = '\n';
        map->file[i + u + 1] = '\0';
	}
	ft_gnl_strdel(&tmp);
}

void    ft_parsing_open_fd(m_point *map, char *argv)
{
    int ret;
    int fd;
    char *buff;

    ret = 0;
    buff = NULL;
    fd = open(argv, O_RDONLY);
    while ((ret = ft_get_next_line(fd, &buff)) > 0)
    {
        ft_strfreejoin_newline(map, buff);
        ft_gnl_strdel(&buff);
    }
    ft_strfreejoin_newline(map, buff);
    ft_gnl_strdel(&buff);
    close(fd);
    if (fd == -1)
        map->error = 15;
    if (ret != 0)
        map->error = 20;
}

int ft_parsing_map(m_point *map, char *argv)
{
    int m;

    m = 0;
    ft_parsing_open_fd(map, argv);
    while (map->error == 0 && map->file[map->x] != '\0' && m < 8)
    {
        map->x = ft_incre_spaces(map, 1, 0) + map->x;
        if (map->file[map->x] == 'R')
            ft_parsing_resolution(map);
        if (map->file[map->x] == 'F')
            ft_parsing_floor(map);
        if (map->file[map->x] == 'C')
            ft_parsing_ceiling(map);
        if ((((map->file[map->x] == 'N' && map->file[map->x + 1] == 'O') || (map->file[map->x] == 'S' && map->file[map->x + 1] == 'O') || (map->file[map->x] == 'W' && map->file[map->x + 1] == 'E') || (map->file[map->x] == 'E' && map->file[map->x + 1] == 'A')) && map->file[map->x + 2] == ' ') || (map->file[map->x] == 'S' && map->file[map->x + 1] == ' '))
            ft_parsing_path_to(map);
        m++;
    }
    (map->error == 0) ? ft_check_file_half(map) : ft_printf("ERROR BEFORE MAPING\n");
    if (map->error == 0)
        ft_check_map(map);
    if (map->error > 0)
        ft_error_detected(map);
    return ((map->error == 0) ? 1 : ft_exit_free_map(map, -1));
	return(1);
}
