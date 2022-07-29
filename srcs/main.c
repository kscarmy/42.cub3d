/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:22:27 by guderram          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/29 10:06:03 by guderram         ###   ########.fr       */
=======
/*   Updated: 2022/07/17 02:44:18 by mourdani         ###   ########.fr       */
>>>>>>> moves
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
<<<<<<< HEAD
	m_point	map;
=======
	m_point map; // déclaration de la structure "map".
>>>>>>> moves

	if (argc != 2)
		return (ft_exor_nfn(1));
	if (ft_check_file_name(argv[1], 1) != 0)
		return (-1);
	ft_init_map(&map);
<<<<<<< HEAD
	ft_disp_verif(&map);
	if (ft_parsing_map(&map, argv[1]) == -1)
		return (-1);
	ft_disp_verif(&map);
=======
		// return(ft_exor_nfn(4)); // Dans le cas où je dois malloc des données dans ft_init_map
	if (ft_parsing_map(&map, argv[1]) == -1) // parsing du fichier
		return (-1);

>>>>>>> moves
	ft_windows(&map);
	return (ft_exit_free_map(&map, 0));
}
