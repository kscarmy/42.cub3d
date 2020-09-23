/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:42 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_printf_s_disp(char *str, t_point *ptf)
{
	int i;

	i = 0;
	while (ptf->wdh > ptf->pco && ptf->pco < 0
		&& ptf->fag == '0' && ptf->wdh > ptf->siz)
		ft_printf_d_incre('0', ptf);
	while (ptf->wdh > ptf->siz && ptf->fag != '-' && ptf->wdh != 0)
	{
		ft_putchar_printf(' ', ptf);
		ptf->wdh = ptf->wdh - 1;
	}
	if (ptf->pco < 0 || ptf->pco > ptf->siz)
		ft_putstr_printf(ptf->str, ptf);
	while (ptf->pco > 0 && ptf->pco <= ptf->siz)
	{
		ft_putchar_printf(str[i], ptf);
		i++;
		if (ptf->pco != -1)
			ptf->pco = ptf->pco - 1;
	}
	while (ptf->wdh > ptf->siz && ptf->fag == '-')
	{
		ft_putchar_printf(' ', ptf);
		ptf->wdh = ptf->wdh - 1;
	}
}

int		ft_printf_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_printf_s(t_point *ptf)
{
	ptf->str = va_arg(ptf->ap, char*);
	if (ptf->str == NULL)
		ptf->str = "(null)";
	if (ft_printf_strlen(ptf->str) < ptf->pco || ptf->pco < 0)
		ptf->siz = ft_printf_strlen(ptf->str);
	else
		ptf->siz = ptf->pco;
	ft_printf_s_disp(ptf->str, ptf);
	ptf->i = ptf->i + ptf->u;
	ft_clear_ptf(ptf);
}
