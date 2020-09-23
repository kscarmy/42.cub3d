/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:42 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_printf_itoa_ll(t_point *ptf)
{
	long long u;
	long long i;
	long long t;

	i = 0;
	t = ptf->t;
	u = (t > 0) ? t : (t * -1);
	ptf->d[0] = (t > 0) ? '+' : '-';
	while (u >= ptf->b)
	{
		u = u / ptf->b;
		i++;
	}
	i = (u > 0) ? (i + 1) : i;
	ptf->siz = (ptf->t < 0) ? (i + 1) : i;
	u = (t > 0) ? t : (t * -1);
	while (i > 0)
	{
		ptf->d[i] = ((u % ptf->b) + ((u % ptf->b > 9) ? ptf->maj : '0'));
		u = u / ptf->b;
		i--;
	}
}

void	ft_printf_percent(t_point *ptf)
{
	ptf->siz = 1;
	while (ptf->wdh > ptf->siz && ptf->fag != '-' && ptf->wdh != 0)
	{
		if (ptf->fag == '0')
			ft_putchar_printf('0', ptf);
		else
			ft_putchar_printf(' ', ptf);
		ptf->wdh = ptf->wdh - 1;
	}
	ft_putchar_printf('%', ptf);
	while (ptf->wdh > ptf->siz && ptf->fag == '-')
	{
		ft_putchar_printf(' ', ptf);
		ptf->wdh = ptf->wdh - 1;
	}
	ptf->i = ptf->i + ptf->u;
	ft_clear_ptf(ptf);
}
