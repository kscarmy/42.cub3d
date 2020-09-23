/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:53:37 by guderram          #+#    #+#             */
/*   Updated: 2019/11/26 22:53:38 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *source, const char *objet, size_t len)
{
	size_t i;
	size_t u;

	i = 0;
	u = 0;
	if (len == 0 && (objet[0] == '\0'))
		return ((char*)source);
	while ((source[i] || ((source[i] == '\0') && (objet[u] == '\0'))) && (len))
	{
		if ((source[i] == objet[u]) || (objet[u] == '\0'))
		{
			while (((source[i + u] == objet[u]) && ((source[i + u])
				&& (objet[u]))) && ((len - u) > 0))
				u++;
			if (objet[u] == '\0')
			{
				source = &source[i];
				return ((char *)source);
			}
			u = 0;
		}
		i++;
		len--;
	}
	return (0);
}
