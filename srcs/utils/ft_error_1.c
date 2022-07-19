/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:32 by guderram          #+#    #+#             */
/*   Updated: 2022/07/19 16:37:30 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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

void    ft_map_disp_error(m_point *m, int l, int x, int erreur)
{
    int a;
    int c;

    a = 0;
    c = 0;
    while (m->map[a] != NULL)
    {
        while (m->map[a][c] != '\0')
        {
            if (a == l && c == x)
                ft_printf("\033[1;31mX");
            else
                ft_printf("\033[0m%c", m->map[a][c]);
            c++;
        }
        ft_printf("\n");
        c = 0;
        a++;
    }
    m->er = erreur;
}

void	ft_show_error_file(m_point *m)
{
	int u;
    int j;
    int i;

	u = 0;
    j = 0;
    i = 0;
	ft_printf("\033[0;31m[ERROR IN FILE]\n");
    // ft_error_file_detail(map);
    if (m->er == 500)
        ft_printf("\033[0;33mLa Resolution de la fenetre est definie deux fois :\n");
    ft_printf("\n");
	while (u < m->x)
	{
		ft_printf("\033[0;32m%c", m->fl[u]);
		u++;
	}
	ft_printf("\033[1;31mI>%c<I", m->fl[u]);
	u++;
	while (m->fl[u + i] != '\0' && j < 8 && i < 300)
	{
		ft_printf("\033[0;36m%c", m->fl[u + i]);
        i++;
		j = (m->fl[u + i] == '\n') ? j + 1 : j;

	}
}

void ft_error_detected(m_point *m)
{
    ft_printf("\033[0;31m[ERROR n'%d']\n", m->er);
    if (m->er < 960)
        ft_show_error_file(m);
    if (m->er >= 1000 && m->er < 1500)
        ft_printf("\033[0;31mMalloc error !\n");

}