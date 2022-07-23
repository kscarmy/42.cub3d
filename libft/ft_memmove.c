/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:48:55 by guderram          #+#    #+#             */
/*   Updated: 2022/07/23 08:50:57 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_else(char *dest, const char *src, size_t i, size_t n)
{
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*la_src;
	char		*la_dest;
	size_t		i;

	i = 0;
	la_src = src;
	la_dest = dest;
	if (!(src) && !(dest) && n != 0)
		return (dest);
	if (la_dest > la_src)
	{
		while (0 < n)
		{
			la_dest[n - 1] = la_src[n - 1];
			n--;
		}
	}
	else
		ft_memmove_else(la_dest, la_src, i, n);
	return (dest);
}
