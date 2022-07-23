/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:53:56 by guderram          #+#    #+#             */
/*   Updated: 2022/07/23 09:06:02 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_checking(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		u;

	i = 0;
	u = (ft_strlen_st(s1) - 1);
	while (ft_checking(s1[i], set) == 1)
		i++;
	if ((i - 1) == u)
	{
		ret = malloc(sizeof(char) * 1);
		ret[0] = 0;
		return (ret);
	}
	while (ft_checking(s1[u], set) == 1)
		u--;
	ret = ft_substr(s1, i, (u - i + 1));
	return (ret);
}
