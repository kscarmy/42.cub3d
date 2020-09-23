/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:53:27 by guderram          #+#    #+#             */
/*   Updated: 2019/11/26 22:53:28 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (((!f) || (!s)) || ((!f) && (!s)))
		return (NULL);
	while (s[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (((!f) || (!str)) || ((!f) && (!str)))
		return (NULL);
	str[i] = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
