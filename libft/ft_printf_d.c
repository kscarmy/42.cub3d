/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:42 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_printf_d_incre(int x, t_point *ptf)
{
	ft_putchar_printf(x, ptf);
	ptf->wdh = ptf->wdh - 1;
}

void	ft_printf_d_suite(t_point *ptf)
{
	while (ptf->t == 0 && ptf->wdh > ptf->pco && ptf->pco < 0
		&& ptf->fag == '0' && ptf->wdh > ptf->siz)
		ft_printf_d_incre('0', ptf);
	while (ptf->t == 0 && ptf->wdh > ptf->pco && ptf->pco < 0
		&& ptf->fag == 0 && ptf->wdh > ptf->siz)
		ft_printf_d_incre(' ', ptf);
	while (ptf->t == 0 && ptf->wdh > ptf->pco && ptf->pco > 0
		&& ptf->fag != '-' && ptf->wdh > ptf->siz && ptf->wdh > ptf->pco)
		ft_printf_d_incre(' ', ptf);
	while (ptf->t == 0 && ptf->wdh > ptf->pco && ptf->pco < 0
		&& ptf->fag == 0 && ptf->wdh > ptf->siz)
		ft_printf_d_incre(' ', ptf);
	while (ptf->wdh > ptf->siz + ptf->g && ptf->fag != '-'
	&& ptf->wdh != 0 && ptf->fag != '0' && ptf->t != 0)
		ft_printf_d_incre(' ', ptf);
	while (ptf->wdh > ptf->siz + ptf->g && ptf->fag == '0'
	&& ptf->wdh > ptf->pco && ptf->pco >= 0)
		ft_printf_d_incre(' ', ptf);
	while (ptf->t == 0 && ptf->wdh > 0 && ptf->wdh > ptf->pco
		&& (ptf->d[0] != '-'))
		ft_printf_d_incre(' ', ptf);
}

void	ft_printf_d(t_point *ptf)
{
	ptf->t = va_arg(ptf->ap, int);
	(ptf->t == -2147483648) ? ft_printf_itoa_ll(ptf) : ft_printf_itoa(ptf);
	ptf->siz = (ptf->t == 0) ? 1 : ptf->siz;
	if (ptf->pco > ((ptf->d[0] == '-') ? ptf->siz - 1 : ptf->siz))
		ptf->g = ptf->pco - ((ptf->d[0] == '-') ? ptf->siz - 1 : ptf->siz);
	ft_printf_d_suite(ptf);
	ft_printf_d_disp(ptf);
	while (ptf->wdh > ptf->siz && ptf->fag == '-' && ptf->wdh > ptf->pco)
		ft_printf_d_incre(' ', ptf);
	while (ptf->t == 0 && ptf->wdh > ptf->pco && ptf->pco >= 0)
		ft_printf_d_incre(' ', ptf);
	ptf->i = ptf->i + ptf->u;
	ft_clear_ptf(ptf);
}
