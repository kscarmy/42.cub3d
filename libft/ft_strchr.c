/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:53:11 by guderram          #+#    #+#             */
/*   Updated: 2022/07/21 16:08:26 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((char)s[i] == c)
		{
			s = &s[i];
			return ((char *)s);
		}
		i++;
	}
	if ((!c) && ((char)s[i] == '\0'))
	{
		s = &s[i];
		return ((char *)s);
	}
	return (NULL);
}
