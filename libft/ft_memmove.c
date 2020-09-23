/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:48:55 by guderram          #+#    #+#             */
/*   Updated: 2019/11/26 22:48:57 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
		while (0 < n)
		{
			la_dest[n - 1] = la_src[n - 1];
			n--;
		}
	else
		while (i < n)
		{
			la_dest[i] = la_src[i];
			i++;
		}
	return (dest);
}
