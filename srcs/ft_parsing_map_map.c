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

void    ft_create_mapping(m_point *map)
{
    int u;
    // int l; // Je dois l'integrer à la structure :)
    int one;

    u = map->x;
    // l = 1; // nbre de lignes, commence à 1 car la tete de lecture est déjà dessus normalement.
    one = 0;
    // one = one + 1; // A SUPPRIMER C PR TESTER
    // ft_printf("4x : %d, u : %d\n", map->x, u);
    while (map->file[u] != '\0')
    {
        if (map->file[u] == '\n' && one == 0 && u != map->x)
        {
            // ft_printf("u : %d,\n'%c'\n", &map->file[u]);
            break ;
        }
        if (map->file[u] == '1')
            one++;
        if (map->file[u] == '\n' && one > 0)
            map->l = map->l + 1;
        one = (map->file[u] == '\n') ? 0 : one;
        u++;
    }
    // ft_printf("test file : \n%s\n", &map->file[map->x + u]);
    // ft_printf("5x : %d, u : %d\n", map->x, u);
    while (map->file[u] == ' ' || map->file[u] == '\t' || map->file[u] == '\n')
        u++;
    // ft_printf("6x : %d, u : %d\n", map->x, u);
    // ft_printf("error : %d\n", map->error);
    // ft_printf("file u : '%c'\n", map->file[u]);
    // ft_printf("1l : %d\n", map->l);
    map->error = (map->file[u] == '\0') ? map->error : 840;
    map->map = (char**)malloc(sizeof(char*) * (map->l + 1));
    map->error = (map->map == NULL) ? 1100 : map->error;
	map->map[map->l] = NULL;
	u = 0;
	while (u < map->l)
	{
		// ft_bzero(map->map[u], 1); // TEST 123
		map->map[u] = (char*)malloc(sizeof(char) * 1); // comme ça je leaks ...
		map->map[u][0] = '\0';
		// map->map[u] = NULL;
		u++;
	}



	// printf("error = '%d'\n", map->error);
    // ft_printf("7x : %d, u : %d\n", map->x, u);
}

void    ft_found_map(m_point *map)
{
    int u;
    int back;

    u = map->x;
    back = u;
    while (map->error == 0 && map->file[u] != '\0' && map->file[u] != '1')
    {
        if (map->file[u] == '1' && map->file[u] == ' ' && map->file[u] == '\n' && map->file[u] == '\t')
            map->error = 810;
        if (map->file[u] == '\n')
            back = u;
        u++;
    }
    map->error = (map->file[u] == '\0') ? 800 : map->error;
    u = map->x;
    map->x = back;
    while (map->error == 0 && map->file[u] != '\0')
    {
        if (ft_is_not_map(map->file[u], 1) == 0)
            map->error = 820;
        if (map->file[u] == 'N' || map->file[u] == 'S' || map->file[u] == 'E' || map->file[u] == 'W')
            ft_set_world_spawn(map, u);
        u++;
    }
}

void    ft_fill_map(m_point *map)
{
    int u;

    u = 0;
    while (u < map->l)
    {
        ft_fill_line_map(map, u);
        u++;
    }
    // ft_printf("u : %d\n", u);
    // ft_printf("l : %d\n", map->l);
}

void    ft_fill_line_map(m_point *map, int l) // l est la ligne à malloc :)
{
    int u;

    u = 1;
	ft_printf("et là c'est cmt\n");
    while (map->file[map->x + u] != '\n' && map->file[map->x + u] != '\0')
        u++;
    // ft_printf("AEu : %d\n", u);
	ft_gnl_strdel(&(map->map[l])); // TEST 123
    map->map[l] = (char*)malloc(sizeof(char) * (u + 1));
    map->error = (map->map[l] == NULL) ? 1200 + l : map->error;
    map->map[l][u] = '\0';
    u = 1;
    // ft_printf("AEx : %d\n", map->x);
    while (map->file[map->x + u] != '\n' && map->file[map->x + u] != '\0')
    {
        map->map[l][u - 1] = map->file[map->x + u];
        // ft_printf("'%c'", map->file[map->x + u]);
        u++;
    }
	map->map[l][u] = '\0';
    map->x = map->x + u;
}

void    ft_check_map(m_point *map) // call toutes les merdes pour la map
{
	ft_printf("UN PASSAGE\n");
    if (map->error == 0)
        ft_found_map(map);
    // ft_printf("x : %d\nfile : \n'%s'\n", map->x, &map->file[map->x]);
    if (map->error == 0)
        ft_create_mapping(map);
    if (map->error == 0)
        ft_fill_map(map);
    // if (map->error == 0)
    //     ft_parse_map(map);
    // ft_printf("HEIN\n");
}