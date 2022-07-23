/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:45:10 by guderram          #+#    #+#             */
/*   Updated: 2022/07/23 08:50:57 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gnl_exerror(char **str, int error)
{
	ft_gnl_strdel(&*str);
	if (error == 1)
		return (-1);
	return (0);
}

void	ft_gnl_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_gnl_strsub(char const *s,
	unsigned int start, size_t len, int **error)
{
	size_t	i;
	char	*str;

	if (start == 0 && len == 0)
		return (ft_gnl_strnew(&**error));
	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		**error = 1;
	if (str == NULL)
		return (NULL);
	i = 0;
	str[len] = '\0';
	while (len != 0)
	{
		str[i] = s[i + start];
		i++;
		len--;
	}
	return (str);
}

void	ft_gnl_read(char **str, char **line, int ret, int *error)
{
	int		i;
	char	*tmp;

	i = ft_gnl_strcount(*str);
	ft_gnl_strdel(&*line);
	if (i != 0 && ((*str)[i - 1] != '\0') && ret == 0 && *error == 0)
		*line = ft_gnl_strsub(*str, 0, (i + 1), &error);
	else if ((*str)[i] != '\0' && *error == 0)
		*line = ft_gnl_strsub(*str, 0, i, &error);
	else if ((*str)[i] == '\0' && *error == 0)
		*line = ft_gnl_strnew(&*error);
	tmp = *str;
	if (*error == 0)
	{
		*str = ft_gnl_strsub(*str, i + 1, ft_gnl_strlen(*str) - i, &error);
		ft_gnl_strdel(&tmp);
	}
}

int	ft_get_next_line(int fd, char **line)
{
	static char	*str;
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	int			error;

	ret = 1;
	error = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (-1);
	if (str == NULL)
		str = ft_gnl_strnew(&error);
	ret = read(fd, buff, BUFFER_SIZE);
	while (error == 0 && ft_gnl_strchr(str) == 1 && 0 < ret)
	{
		buff[ret] = '\0';
		ft_gnl_strjoin(&str, buff, ret, &error);
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (error == 1 || ret == -1)
		return (ft_gnl_exerror(&str, error));
	ft_gnl_read(&str, line, ret, &error);
	if ((error == 1) || (ret == 0 && *str == 0))
		return (ft_gnl_exerror(&str, error));
	printf("ft_get_next_line : <%s>\n", *line);
	return (1);
}
