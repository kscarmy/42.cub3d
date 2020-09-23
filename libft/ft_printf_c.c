/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:42 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_printf_c(t_point *ptf)
{
	ptf->siz = 1;
	ptf->c = va_arg(ptf->ap, int);
	while (ptf->wdh > ptf->siz && ptf->fag != '-' && ptf->wdh != 0)
	{
		if (ptf->fag == '0')
			ft_putchar_printf('0', ptf);
		else
			ft_putchar_printf(' ', ptf);
		ptf->wdh = ptf->wdh - 1;
	}
	ft_putchar_printf(ptf->c, ptf);
	while (ptf->wdh > ptf->siz && ptf->fag == '-')
	{
		ft_putchar_printf(' ', ptf);
		ptf->wdh = ptf->wdh - 1;
	}
	ptf->i = ptf->i + ptf->u;
	ft_clear_ptf(ptf);
}
