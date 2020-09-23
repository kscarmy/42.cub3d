/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:48:32 by guderram          #+#    #+#             */
/*   Updated: 2019/11/26 22:48:33 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*la_dest;
	const	char	*la_src;

	if (!(src) && !(dest) && n != 0)
		return (dest);
	la_dest = (char *)dest;
	la_src = (const char *)src;
	while (0 < n)
	{
		*(char *)la_dest++ = *(const char *)la_src++;
		n--;
	}
	return (dest);
}
