/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_know.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:42 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_know_flags(t_point *ptf)
{
	ptf->fag = ptf->fmt[ptf->i + ptf->u];
	ptf->u = ptf->u + 1;
}

void	ft_know_width(t_point *ptf)
{
	if (ptf->fmt[ptf->i + ptf->u] == '*')
	{
		ptf->wdh = va_arg(ptf->ap, int);
		ptf->u = ptf->u + 1;
		if (ptf->wdh < 0)
		{
			ptf->wdh = ptf->wdh * -1;
			ptf->fag = '-';
		}
	}
	else
	{
		ptf->wdh = ft_atoi(&ptf->fmt[ptf->i + ptf->u]);
		while (ft_isdigit(ptf->fmt[ptf->i + ptf->u]) == 1)
			ptf->u = ptf->u + 1;
	}
}

void	ft_know_precision(t_point *ptf)
{
	ptf->u = ptf->u + 1;
	if (ptf->fmt[ptf->i + ptf->u] == '*')
	{
		ptf->pco = va_arg(ptf->ap, int);
		ptf->u = ptf->u + 1;
	}
	else
	{
		ptf->pco = ft_atoi(&ptf->fmt[ptf->i + ptf->u]);
		while (ft_isdigit(ptf->fmt[ptf->i + ptf->u]) == 1)
			ptf->u = ptf->u + 1;
	}
}
