/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:53:17 by guderram          #+#    #+#             */
/*   Updated: 2019/11/26 22:53:19 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	ft_incre(char const *s1, char const *s2, int *i, int *u)
{
	*i = 0;
	*u = 0;
	while (s1[*i])
		*i = *i + 1;
	while (s2[*u])
		*u = *u + 1;
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		u;
	char	*str;

	if (((!s1) && (!s2)) || (!s1) || (!s2))
		return (NULL);
	ft_incre(s1, s2, &i, &u);
	str = (char *)malloc(sizeof(char) * (i + u + 1));
	if (!str)
		return (NULL);
	i = 0;
	u = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[u])
	{
		str[i + u] = s2[u];
		u++;
	}
	str[i + u] = '\0';
	return (str);
}
