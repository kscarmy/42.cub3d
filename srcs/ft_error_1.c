/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2020/01/31 12:45:33 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_exor_nfn(int error)
{
	if (error == 1)
		ft_printf("Erreur : veuillez passer un fichier en argument tel que : ./Cub3d 'fichier.cub'\n");
	if (error == 2)
		ft_printf("Le fichier ne possede pas la bonne extension *.cub tel que : 'fichier.cub'\n");
	if (error == 3)
		ft_printf("Le fichier spécifié n'existe pas\n");
	if (error == 4)
		ft_printf("ERREUR : L'initialisation de la structure a échouée.\n");
	return (-1);
}
