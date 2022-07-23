/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:20:18 by guderram          #+#    #+#             */
/*   Updated: 2022/07/23 09:06:02 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	u;
	char	*ret;

	u = 0;
	if (!s)
		return (NULL);
	if (ft_strlen_st(s) < start)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	while (0 < len)
	{
		ret[u] = s[start + u];
		u++;
		len--;
	}
	ret[u] = '\0';
	return (ret);
}
