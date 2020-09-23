/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2020/01/31 12:45:33 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strfreejoin_newline(m_point *map, char *buff)
{
	char	*tmp;
	int		i;
    int u;

	i = 0;
    u = 0;
    // ft_printf("file : %s, buff : %s\n", map->file, buff);
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
	ft_printf("\n%s\n\n", map->file);
    while (map->error == 0 && map->file[map->x] != '\0' && m < 8)
    {
		ft_printf("map>-x : '%d\n'", map->x);
		ft_printf("\neuuhhh : '%c'\n", map->file[map->x]);
		
        map->x = ft_incre_spaces(map, 1, 0) + map->x;
		ft_printf("map>-x : '%d\n'", map->x);
        if (map->file[map->x] == 'R')
            ft_parsing_resolution(map);
        if (map->file[map->x] == 'F')
            ft_parsing_floor(map);
        if (map->file[map->x] == 'C')
            ft_parsing_ceiling(map);
        if ((((map->file[map->x] == 'N' && map->file[map->x + 1] == 'O') || (map->file[map->x] == 'S' && map->file[map->x + 1] == 'O') || (map->file[map->x] == 'W' && map->file[map->x + 1] == 'E') || (map->file[map->x] == 'E' && map->file[map->x + 1] == 'A')) && map->file[map->x + 2] == ' ') || (map->file[map->x] == 'S' && map->file[map->x + 1] == ' '))
            ft_parsing_path_to(map); // JEAN MICHEL
        // map->x = (map->file[map->x] != '\0') ? map->x + 1 : map->x;
        m++;
    }
    // (map->error == 0) ? ft_check_file_half(map) : ft_printf("ERROR BEFORE MAPING\n");
    // // METTRE LA FONCTION POUR GERER LA MAP ICI
    // // ft_printf("Ax : %d\n", map->x);
    // // ft_printf("file : \n'%s'\n", &map->file[map->x]);
    // if (map->error == 0)
    //     ft_check_map(map);
    // if (map->error > 0)
    //     ft_error_detected(map);
    // return ((map->error == 0) ? 1 : ft_exit_free_map(map, -1));
	return(1);
}
