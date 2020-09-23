/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:45:38 by guderram          #+#    #+#             */
/*   Updated: 2019/11/26 16:45:44 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while ((src[i]) && (i < size))
	{
		dest[i] = src[i];
		i++;
	}
	if (i == size)
		dest[size - 1] = '\0';
	else
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
