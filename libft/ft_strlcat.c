/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:22:35 by guderram          #+#    #+#             */
/*   Updated: 2019/12/13 00:26:59 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	u;
	size_t	j;

	i = 0;
	u = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (destsize <= 0)
		return (i);
	while (u < destsize && dest[u] != '\0')
		u++;
	if (destsize <= u)
		return (destsize + i);
	destsize = destsize - u - 1;
	while (src[j] != '\0' && destsize != 0)
	{
		dest[u + j] = src[j];
		j++;
		destsize--;
	}
	dest[u + j] = '\0';
	return (i + u);
}
