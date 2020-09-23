/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:42 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_printf_itoa_init(t_point *ptf)
{
	int x;

	x = 0;
	while (x < 64)
	{
		ptf->d[x] = '\0';
		x++;
	}
}

int		ft_printf_d_disp_suite(int *m, int *a, int *u, t_point *ptf)
{
	int x;

	x = 1;
	while (ptf->d[x] != '\0' && ptf->t != 0)
	{
		while (x > 0 && *m > ((ptf->d[0] == '-') ? ptf->siz - 1 : ptf->siz))
		{
			ft_putchar_printf('0', ptf);
			*m = *m - 1;
			*a = *a + 1;
		}
		while (*u > ptf->siz + ptf->g && ptf->pco < 0 && ptf->fag == '0')
		{
			ft_putchar_printf('0', ptf);
			*a = *a + 1;
			*u = *u - 1;
		}
		ft_putchar_printf((ptf->d[x]), ptf);
		x = x + 1;
	}
	return (x);
}

void	ft_printf_d_disp(t_point *ptf)
{
	int x;
	int m;
	int a;
	int u;

	u = ptf->wdh;
	if (ptf->d[0] == '-' && ptf->typ == 'd' && ptf->t != 0)
		ft_putchar_printf('-', ptf);
	m = ptf->pco;
	a = 0;
	if (ptf->t == 0 && ptf->pco < 0)
	{
		ft_putchar_printf('0', ptf);
		a++;
	}
	while (ptf->t == 0 && m > 0)
	{
		ft_putchar_printf('0', ptf);
		m--;
		a++;
	}
	x = ft_printf_d_disp_suite(&m, &a, &u, ptf);
	x = x + 1;
	ptf->siz = (ptf->t == 0) ? 1 : ptf->siz + a;
}

void	ft_printf_itoa(t_point *ptf)
{
	int u;
	int i;

	i = 0;
	u = (ptf->t > 0) ? ptf->t : (ptf->t * -1);
	ptf->d[0] = (ptf->t > 0) ? '+' : '-';
	while (u >= ptf->b)
	{
		u = u / ptf->b;
		i++;
	}
	i = (u > 0) ? (i + 1) : i;
	ptf->siz = (ptf->t < 0) ? (i + 1) : i;
	u = (ptf->t > 0) ? ptf->t : (ptf->t * -1);
	while (i > 0)
	{
		ptf->d[i] = ((u % ptf->b) + ((u % ptf->b > 9) ? ptf->maj : '0'));
		u = u / ptf->b;
		i--;
	}
}

void	ft_printf_itoa_ull(t_point *ptf)
{
	unsigned long long u;
	unsigned long long i;

	i = 0;
	u = ptf->ull;
	ptf->d[0] = '0';
	ptf->d[1] = 'x';
	while (u >= (unsigned long long)ptf->b)
	{
		u = u / ptf->b;
		i++;
	}
	ptf->siz = i + 3;
	u = ptf->ull;
	while (i > 0)
	{
		ptf->d[i + 2] = ((u % ptf->b) + ((u % ptf->b > 9) ? ptf->maj : '0'));
		u = u / ptf->b;
		i--;
	}
	ptf->d[i + 2] = ((u % ptf->b) + ((u % ptf->b > 9) ? ptf->maj : '0'));
}
