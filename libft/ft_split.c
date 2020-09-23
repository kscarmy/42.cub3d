/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:12:56 by guderram          #+#    #+#             */
/*   Updated: 2019/11/26 21:12:59 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int		ft_taille(char *str, char c)
{
	int i;
	int nbc;

	i = 0;
	nbc = 1;
	if (str[i] == c)
		nbc--;
	while (str[i])
	{
		if ((str[i] == c) && (!(str[i + 1] == c)) && str[i + 1] != '\0')
			nbc++;
		i++;
	}
	return (nbc);
}

static	char	*ft_ligne(char *s, int *f, char c)
{
	int		i;
	int		u;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	u = *f;
	while ((s[u] == c) && s[u] != '\0')
		u++;
	while ((s[u] != c) && s[u] != '\0')
	{
		j++;
		u++;
	}
	str = (char*)malloc(sizeof(char) * (j + 1));
	while ((s[*f] == c) && s[*f] != '\0')
		(*f)++;
	while ((s[*f] != c) && s[*f] != '\0')
	{
		str[i++] = s[*f];
		(*f)++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		nbc;

	i = 0;
	nbc = 0;
	if (!(tab = (char**)malloc(sizeof(char *) * (ft_taille((char *)s, c) + 1))))
		return (NULL);
	if (s[0] != '\0')
	{
		while (i < ft_taille((char *)s, c))
		{
			tab[i] = ft_ligne((char *)s, &nbc, c);
			i++;
		}
	}
	tab[i] = 0;
	return (tab);
}
