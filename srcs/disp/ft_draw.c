/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:18:13 by guderram          #+#    #+#             */
/*   Updated: 2022/08/12 14:31:35 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_texture(w_point *w, char *img, int xx, int yy)
{
	int	x;
	int	y;

	if (yy - (RES_Y / 2) > 0)
		y = ((w->c->h / 2) + w->c->i) * WALL_SIZE / w->c->h;
	else
		y = ((w->c->h / 2) - w->c->i) * WALL_SIZE / w->c->h;
	if (w->or == -1)
	{
		x = (ft_get_centieme(w->h->hy) * WALL_SIZE / 100);
		w->str[xx * 4 + 4 * RES_X * yy] = img[x * 4 + (4 * WALL_SIZE * y)];
		w->str[xx * 4 + 4 * RES_X * yy + 1]
			= img[x * 4 + (4 * WALL_SIZE * y) + 1];
		w->str[xx * 4 + 4 * RES_X * yy + 2]
			= img[x * 4 + (4 * WALL_SIZE * y) + 2];
	}
	else
	{
		x = (ft_get_centieme(w->v->vx) * WALL_SIZE / 100);
		w->str[xx * 4 + 4 * RES_X * yy] = img[x * 4 + 4 * WALL_SIZE * y];
		w->str[xx * 4 + 4 * RES_X * yy + 1]
			= img[x * 4 + 4 * WALL_SIZE * y + 1];
		w->str[xx * 4 + 4 * RES_X * yy + 2]
			= img[x * 4 + 4 * WALL_SIZE * y + 2];
	}
}

void	ft_red_pixel_bord(w_point *w, int h, int x)
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

void	ft_red_pixel_up(w_point *w, int h, int x)
{
	int	i;
	int	mid;

	i = 0;
	mid = RES_Y / 2;
	w->c->h = h * 2;
	while (h > 0 && i < h && i < RES_Y / 2)
	{
		w->c->i = i;
		if (w->dirx == 1 && w->or == -1)
			ft_put_texture(w, w->c->ea, x, (mid - i));
		else if (w->dirx == -1 && w->or == -1)
			ft_put_texture(w, w->c->we, x, (mid - i));
		else if (w->diry == 1 && w->or == 1)
			ft_put_texture(w, w->c->so, x, (mid - i));
		else if (w->diry == -1 && w->or == 1)
			ft_put_texture(w, w->c->no, x, (mid - i));
		i++;
	}
	ft_red_pixel_bord(w, h, x);
}

void	ft_red_pixel(w_point *w, int h, int x)
{
	int	i;
	int	mid;

	i = 0;
	mid = RES_Y / 2;
	w->c->h = h * 2;
	while (h > 0 && i < h && i < RES_Y / 2)
	{
		w->c->i = i;
		if (w->dirx == 1 && w->or == -1)
			ft_put_texture(w, w->c->ea, x, (mid + i));
		else if (w->dirx == -1 && w->or == -1)
			ft_put_texture(w, w->c->we, x, (mid + i));
		else if (w->diry == 1 && w->or == 1)
			ft_put_texture(w, w->c->so, x, (mid + i));
		else if (w->diry == -1 && w->or == 1)
			ft_put_texture(w, w->c->no, x, (mid + i));
		i++;
	}
	ft_red_pixel_up(w, h, x);
}
