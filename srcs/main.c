/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:22:27 by guderram          #+#    #+#             */
/*   Updated: 2022/07/20 15:20:16 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	main(int argc, char **argv)
{
	m_point	map;

	if (argc != 2)
		return (ft_exor_nfn(1));
	if (ft_check_file_name(argv[1], 1) != 0)
		return (-1);
	ft_init_map(&map);
	ft_disp_verif(&map);
	if (ft_parsing_map(&map, argv[1]) == -1)
		return (-1);
	ft_disp_verif(&map);
	return (ft_exit_free_map(&map, 0));
}
