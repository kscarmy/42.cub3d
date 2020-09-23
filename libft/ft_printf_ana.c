/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ana.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:42 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_false_type(t_point *ptf)
{
	ptf->i = ptf->i;
	if ((ptf->fmt[ptf->i + ptf->u] != 's') && (ptf->fmt[ptf->i + ptf->u] != '%')
	&& (ptf->fmt[ptf->i + ptf->u] != 'c') && (ptf->fmt[ptf->i + ptf->u] != 'd')
	&& (ptf->fmt[ptf->i + ptf->u] != 'p') && (ptf->fmt[ptf->i + ptf->u] != 'u')
		&& (ptf->fmt[ptf->i + ptf->u] != 'i')
		&& (ptf->fmt[ptf->i + ptf->u] != 'x')
		&& (ptf->fmt[ptf->i + ptf->u] != 'X')
			&& (ptf->fmt[ptf->i + ptf->u] != '0')
			&& (ptf->fmt[ptf->i + ptf->u] != '.')
			&& (ptf->fmt[ptf->i + ptf->u] != '-')
			&& (ptf->fmt[ptf->i + ptf->u] != '*')
			&& (ft_isdigit(ptf->fmt[ptf->i + ptf->u] == 1)))
	{
		return (0);
	}
	return (1);
}

void	ft_ana_types(t_point *ptf)
{
	if (ptf->typ == 's')
		ft_printf_s(ptf);
	if (ptf->typ == '%')
		ft_printf_percent(ptf);
	if (ptf->typ == 'c')
		ft_printf_c(ptf);
	if (ptf->typ == 'd')
		ft_printf_d(ptf);
	if (ptf->typ == 'p')
		ft_printf_p(ptf);
	if (ptf->typ == 'u')
		ft_printf_u(ptf);
	if (ptf->typ == 'x')
		ft_printf_x(ptf);
	if (ptf->typ == 'X')
		ft_printf_x(ptf);
}

int		ft_make_type(char type, t_point *ptf)
{
	ptf->typ = type;
	ptf->u = ptf->u + 1;
	return (0);
}

int		ft_find_type(t_point *ptf)
{
	if (ptf->fmt[ptf->i + ptf->u] == 's' && ptf->u > 0)
		return (ft_make_type('s', ptf));
	if (ptf->fmt[ptf->i + ptf->u] == '%' && ptf->u > 0)
		return (ft_make_type('%', ptf));
	if (ptf->fmt[ptf->i + ptf->u] == 'c' && ptf->u > 0)
		return (ft_make_type('c', ptf));
	if ((ptf->fmt[ptf->i + ptf->u] == 'd'
	|| ptf->fmt[ptf->i + ptf->u] == 'i') && ptf->u > 0)
		return (ft_make_type('d', ptf));
	if (ptf->fmt[ptf->i + ptf->u] == 'p' && ptf->u > 0)
		return (ft_make_type('p', ptf));
	if (ptf->fmt[ptf->i + ptf->u] == 'u' && ptf->u > 0)
		return (ft_make_type('u', ptf));
	if (ptf->fmt[ptf->i + ptf->u] == 'x' && ptf->u > 0)
		return (ft_make_type('x', ptf));
	if (ptf->fmt[ptf->i + ptf->u] == 'X' && ptf->u > 0)
		return (ft_make_type('X', ptf));
	else
	{
		ptf->u = ptf->u + 1;
	}
	return (ft_false_type(ptf));
}

void	ft_ana_flags(t_point *ptf)
{
	while (ft_find_type(ptf) == 1)
	{
		if (ptf->fmt[ptf->i + ptf->u] == '-'
		|| ptf->fmt[ptf->i + ptf->u] == '0')
			ft_know_flags(ptf);
		if (ptf->fmt[ptf->i + ptf->u] == '-')
			ft_know_flags(ptf);
		if (ft_isdigit(ptf->fmt[ptf->i + ptf->u])
		|| ptf->fmt[ptf->i + ptf->u] == '*')
			ft_know_width(ptf);
		if (ptf->fmt[ptf->i + ptf->u] == '.')
			ft_know_precision(ptf);
		if (ft_false_type(ptf) == 0)
			break ;
	}
	if (ft_false_type(ptf) == 1)
		ft_ana_types(ptf);
	else
	{
		ptf->i = ptf->i + ptf->u;
	}
}
