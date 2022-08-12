/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 08:19:04 by guderram          #+#    #+#             */
/*   Updated: 2022/08/12 14:03:24 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_degrees_to_radian(double deg)
{
	return (deg * PI_VAL / 180);
}

double	ft_radian_to_degrees(double rad)
{
	return (rad * 180 / PI_VAL);
}

void	ft_put_pixel_ceiling(w_point *w, int i)
{
	w->str[i + 2] = w->map->fr;
	w->str[i + 1] = w->map->fg;
	w->str[i] = w->map->fb;
}

void	ft_put_pixel_floor(w_point *w, int i)
{
	w->str[i + 2] = w->map->cr;
	w->str[i + 1] = w->map->cg;
	w->str[i] = w->map->cb;
}

int	ft_get_centieme(double x)
{
	int	ret;

	x = x * 100;
	if (x < 0)
		ret = (int)x * -1;
	else
		ret = (int)x;
	ret = ret % 100;
	if (ret < 0 && ret > WALL_SIZE)
		ret = 0;
	return (ret);
}

void	ft_put_texture(w_point *w, char *img, int xx, int yy)
{
	int	x;
	int	y;

	if (yy - (RES_Y / 2) > 0)
		y = ((w->c->h / 2) + w->c->i) * WALL_SIZE / w->c->h;
	else
		y = ((w->c->h / 2) - w->c->i) * WALL_SIZE / w->c->h;
	if (y < 0 && y > WALL_SIZE)
		y = 0;
	if (w->or == -1)
	{
		x = (ft_get_centieme(w->h->hy) * WALL_SIZE / 100);
		w->str[xx * 4 + 4 * RES_X * yy] = img[x * 4 + (4 * WALL_SIZE * y)];
		w->str[xx * 4 + 4 * RES_X * yy + 1] = img[x * 4 + (4 * WALL_SIZE * y) + 1];
		w->str[xx * 4 + 4 * RES_X * yy + 2] = img[x * 4 + (4 * WALL_SIZE * y) + 2];
	}
	else
	{
		x = (ft_get_centieme(w->v->vx) * WALL_SIZE / 100);
		w->str[xx * 4 + 4 * RES_X * yy] = img[x * 4 + 4 * WALL_SIZE * y];
		w->str[xx * 4 + 4 * RES_X * yy + 1] = img[x * 4 + 4 * WALL_SIZE * y + 1];
		w->str[xx * 4 + 4 * RES_X * yy + 2] = img[x * 4 + 4 * WALL_SIZE * y + 2];
	}
}

void	ft_red_pixel(w_point *w, int h, int x)
{
	int	i;
	int	mid;
	int	head;

	i = 0;
	mid = RES_Y / 2;
	head = 0;
	w->c->h = h * 2;
	while (h > 0 && i < h && i < RES_Y / 2)
	{
		w->c->i = i;
		if (w->dirx == 1 && w->or == -1)
		{
			ft_put_texture(w, w->c->ea, x, (mid + i));
			ft_put_texture(w, w->c->ea, x, (mid - i));
		}
		else if (w->dirx == -1 && w->or == -1)
		{
			ft_put_texture(w, w->c->we, x, (mid + i));
			ft_put_texture(w, w->c->we, x, (mid - i));
		}
		else if (w->diry == 1 && w->or == 1)
		{
			ft_put_texture(w, w->c->so, x, (mid + i));
			ft_put_texture(w, w->c->so, x, (mid - i));
		}
		else if (w->diry == -1 && w->or == 1)
		{
			ft_put_texture(w, w->c->no, x, (mid + i));
			ft_put_texture(w, w->c->no, x, (mid - i));
		}
		i++;
	}
	head = (x * 4 + 4 * RES_X * (mid + i));
	while (i < RES_Y && head < (RES_X * 4) * RES_Y)
	{
		ft_put_pixel_ceiling(w, head);
		ft_put_pixel_floor(w, (x * 4 + 4 * RES_X * (mid - i)));
		i++;
		head = (x * 4 + 4 * RES_X * (mid + i));
	}
}

int	ft_str_size(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str != NULL && str[i] && str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_entier(double a)
{
	while (a >= 1)
		a = a - 1;
	if (a > 0)
		return (1);
	return (0);
}

double	ft_double_abs(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}
