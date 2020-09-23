/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:42 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_printf_p_disp_suite(int *m, int *a, int *u, t_point *ptf)
{
	int x;

	x = 2;
	ft_putchar_printf((ptf->d[0]), ptf);
	ft_putchar_printf((ptf->d[1]), ptf);
	while (ptf->d[x] != '\0' && ptf->ull != 0)
	{
		while (x > 0 && *m + 2 > ptf->siz)
		{
			ft_putchar_printf('0', ptf);
			*m = *m - 1;
			*a = *a + 1;
		}
		*m = *m;
		*a = *a;
		*u = *u;
		ft_putchar_printf((ptf->d[x]), ptf);
		x = x + 1;
	}
	if (ptf->ull == 0 && ptf->pco != 0)
		ft_putchar_printf((ptf->d[2]), ptf);
}

void	ft_printf_p_disp(t_point *ptf)
{
	int m;
	int a;
	int u;

	u = ptf->wdh;
	m = ptf->pco;
	a = 0;
	ft_printf_p_disp_suite(&m, &a, &u, ptf);
	ptf->siz = (ptf->ull == 0 && ptf->pco == 0) ? 2 : ptf->siz + a;
}

void	ft_printf_p_incre(int x, t_point *ptf)
{
	ft_putchar_printf(x, ptf);
	ptf->wdh = ptf->wdh - 1;
}

void	ft_printf_p_suite(t_point *ptf)
{
	while (ptf->ull == 0 && ptf->wdh > ptf->pco && ptf->pco < 0
		&& ptf->fag == 0 && ptf->wdh > ptf->siz)
		ft_printf_p_incre(' ', ptf);
	while (ptf->ull == 0 && ptf->wdh > ptf->pco && ptf->pco > 0
		&& ptf->fag != '-' && ptf->wdh > ptf->siz && ptf->wdh > ptf->pco)
		ft_printf_p_incre(' ', ptf);
	while (ptf->ull == 0 && ptf->wdh > ptf->pco && ptf->pco < 0
		&& ptf->fag == 0 && ptf->wdh > ptf->siz)
		ft_printf_p_incre(' ', ptf);
	while (ptf->wdh > ptf->siz + ptf->g && ptf->fag != '-'
	&& ptf->wdh != 0 && ptf->fag != '0' && ptf->ull != 0)
		ft_printf_p_incre(' ', ptf);
	while (ptf->wdh > ptf->siz + ptf->g && ptf->fag == '0'
	&& ptf->wdh > ptf->pco && ptf->pco >= 0)
		ft_printf_p_incre(' ', ptf);
	while (ptf->ull == 0 && ptf->wdh > 0 && ptf->wdh > ptf->pco
		&& (ptf->fag != '-') && ptf->wdh > ptf->siz)
		ft_printf_p_incre(' ', ptf);
}

void	ft_printf_p(t_point *ptf)
{
	ptf->ull = va_arg(ptf->ap, unsigned long long);
	ptf->b = 16;
	ft_printf_itoa_ull(ptf);
	ptf->siz = (ptf->ull == 0 && ptf->pco == 0) ? 2 : ptf->siz;
	ft_printf_p_suite(ptf);
	ft_printf_p_disp(ptf);
	while (ptf->wdh > ptf->siz && ptf->fag == '-' && ptf->wdh > ptf->pco)
		ft_printf_p_incre(' ', ptf);
	while (ptf->ull == 0 && ptf->wdh > ptf->pco && ptf->pco >= 0
		&& ptf->wdh > ptf->siz)
		ft_printf_p_incre(' ', ptf);
	while (ptf->ull == 0 && ptf->pco - 1 > 0)
	{
		ft_printf_p_incre('0', ptf);
		ptf->pco = ptf->pco - 1;
	}
	ptf->i = ptf->i + ptf->u;
	ft_clear_ptf(ptf);
}
