/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_error_1.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: guderram <guderram@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/31 12:45:32 by guderram		  #+#	#+#			 */
/*   Updated: 2022/07/20 15:10:43 by guderram		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_exor_nfn(int error)
{
	if (error == 1)
	{
		printf("Erreur : veuillez ");
		printf("passer un fichier en argument tel ");
		printf("que : ./Cub3d 'fichier.cub'\n");
	}
	if (error == 2)
	{
		printf("Le fichier ne possede pas la bonne");
		printf(" extension *.cub tel que : 'fichier.cub'\n");
	}
	if (error == 3)
		printf("Le fichier spécifié n'existe pas\n");
	if (error == 4)
		printf("ERREUR : L'initialisation de la structure a échouée.\n");
	return (-1);
}

void	ft_map_disp_error(t_m_point *m, int l, int x, int erreur)
{
	int	a;
	int	c;

	a = 0;
	c = 0;
	while (m->map[a] != NULL)
	{
		while (m->map[a][c] != '\0')
		{
			if (a == l && c == x)
				printf("\033[1;31mX");
			else
				printf("\033[0m%c", m->map[a][c]);
			c++;
		}
		printf("\n");
		c = 0;
		a++;
	}
	m->er = erreur;
}

void	ft_show_error_file_bis(t_m_point *m, int u, int i, int j)
{
	while (u < m->x)
	{
		printf("\033[0;32m%c", m->fl[u]);
		u++;
	}
	printf("\033[1;31mI>%c<I", m->fl[u]);
	u++;
	while (m->fl[u + i] != '\0' && j < 8 && i < 300)
	{
		printf("\033[0;36m%c", m->fl[u + i]);
		i++;
		if (m->fl[u + i] == '\n')
			j++;
	}
}

void	ft_show_error_file(t_m_point *m)
{
	int	u;
	int	j;
	int	i;

	u = 0;
	j = 0;
	i = 0;
	printf("\033[0;31m[ERROR IN FILE]\n");
	if (m->er == 500)
	{
		printf("\033[0;33mLa Resolution de la");
		printf(" fenetre est definie deux fois :\n");
	}
	printf("\n");
	ft_show_error_file_bis(m, u, i, j);
}

void	ft_error_detected(t_m_point *m)
{
	printf("\033[0;31m[ERROR n'%d']\n", m->er);
	if (m->er < 960)
		ft_show_error_file(m);
	if (m->er >= 1000 && m->er < 1500)
		printf("\033[0;31mMalloc error !\n");
}
