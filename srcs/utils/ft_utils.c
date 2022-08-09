/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 08:19:04 by guderram          #+#    #+#             */
/*   Updated: 2022/08/09 16:53:18 by guderram         ###   ########.fr       */
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

// void	ft_put_pixel(w_point *w, int i)
// {
// 	w->str[i] = w->c->r;
// 	w->str[i + 1] = w->c->g;
// 	w->str[i + 2] = w->c->b;
// }

void	ft_put_pixel_floor(w_point *w, int i)
{
	// w->str[i] = (char)w->map->fr;
	// w->str[i + 1] = (char)w->map->fg;
	// w->str[i + 2] = (char)w->map->fb;
	// w->str[i] = w->map->floor;
	w->str[i] = 78;
	w->str[i + 1] = 82;
	w->str[i + 2] = 43;
}

void	ft_put_pixel_ceiling(w_point *w, int i)
{
	// w->str[i] = (char)w->map->cr;
	// w->str[i + 1] = (char)w->map->cg;
	// w->str[i + 2] = (char)w->map->cb;
	// w->str[i] = w->map->ceiling;
	w->str[i] = 245;
	w->str[i + 1] = 135;
	w->str[i + 2] = 66;
}

int	ft_get_centieme(double x)
{
	int ret;

	x = x * 100;
	ret = (int)x;
	if (ret < 0)
		ret = ret * -1;
	ret = ret % 100;
	return (ret);
}

void	ft_put_texture(w_point *w, char *img, int xx, int yy)
{
	int	x;
	int	y;
	if (w->or == 1) // HR
	{
		x = (ft_get_centieme(w->h->hx) * 64 / 100);
		// y = (ft_get_centieme(w->h->hy) * 64 / 100);
		y = 0;
		// printf("ft_put_texture : hx %f hy %f x %d y %d\n", w->h->hx, w->h->hy, x, y);
		w->str[xx * 4 + 4 * (int)RES_X * yy] = img[x * 4 + 4 * (int)RES_X * y];
		w->str[xx * 4 + 4 * (int)RES_X * yy + 1] = img[x * 4 + 4 * (int)RES_X * y + 1];
		w->str[xx * 4 + 4 * (int)RES_X * yy + 2] = img[x * 4 + 4 * (int)RES_X * y + 2];
	}
	else // vr
	{
		x = (ft_get_centieme(w->v->vy) * 64 / 100);
		// y = (ft_get_centieme(w->v->vy) * 64 / 100);
		y = 0;
		// printf("ft_put_texture : vx %f vy %f x %d y %d\n", w->v->vx, w->v->vy, x, y);
		w->str[xx * 4 + 4 * (int)RES_X * yy] = img[x * 4 + 4 * (int)RES_X * y];
		w->str[xx * 4 + 4 * (int)RES_X * yy + 1] = img[x * 4 + 4 * (int)RES_X * y + 1];
		w->str[xx * 4 + 4 * (int)RES_X * yy + 2] = img[x * 4 + 4 * (int)RES_X * y + 2];
	}
}

// void	ft_put_colon(w_point *w, int h, int x)
// {
// 	int	i;
// 	int	mid;

// 	i = 0;
// 	mid = RES_Y / 2;
// 	while (h > 0 && i < h && i <= RES_Y)
// 	{
// 		i++;
// 	}
// 	while (i <= RES_Y)
// 	{
		
// 		ft_put_pixel_ceiling(w, (x * 4 + 4 * RES_X * (mid + i)));
// 		ft_put_pixel_floor(w, (x * 4 + 4 * RES_X * (mid - i)));
// 		i++;
// 	}
// }

void	ft_red_pixel(w_point *w, int h, int x)
{
	int	i;
	int	mid;

	i = 0;
	mid = RES_Y / 2;
	// printf("crash ?");
	int	head;

	head = 0;
	while (h > 0 && i < h && i <= RES_Y)
	{
		if (w->dirx == 1 && w->or == -1) //			DROITE : ORANGE
		{
			ft_put_texture(w, w->c->ea, x, (mid + i));
			ft_put_texture(w, w->c->ea, x, (mid - i));
			// mlx_pixel_put(w->mlx, w->win1, x, mid + i, 0xF59042);
			// mlx_pixel_put(w->mlx, w->win1, x, mid - i, 0xF59042);
		}
		else if (w->dirx == -1 && w->or == -1) //	GAUCHE : VERT
		{
			ft_put_texture(w, w->c->we, x, (mid + i));
			ft_put_texture(w, w->c->we, x, (mid - i));
			// mlx_pixel_put(w->mlx, w->win1, x, mid + i, 0x26BF59);
			// mlx_pixel_put(w->mlx, w->win1, x, mid - i, 0x26BF59);
		}
		else if (w->diry == 1 && w->or == 1) //		BAS : BLEU
		{
			ft_put_texture(w, w->c->so, x, (mid + i));
			ft_put_texture(w, w->c->so, x, (mid - i));
			// mlx_pixel_put(w->mlx, w->win1, x, mid + i, 0x0D256E);
			// mlx_pixel_put(w->mlx, w->win1, x, mid - i, 0x0D256E);
		}
		else if (w->diry == -1 && w->or == 1) //	HAUT : MAUVE
		{
			ft_put_texture(w, w->c->no, x, (mid + i));
			ft_put_texture(w, w->c->no, x, (mid - i));
			// mlx_pixel_put(w->mlx, w->win1, x, mid + i, 0xA30F54);
			// mlx_pixel_put(w->mlx, w->win1, x, mid - i, 0xA30F54);
		}

		// // mlx_pixel_put(w->mlx, w->win1, x, mid + i, 0xFF99FF);
		// // mlx_pixel_put(w->mlx, w->win1, x, mid - i, 0xFF99FF);
		i++;
	}
	// printf("non\n");
	// printf("x %d RES_X %d y %d\n", x, RES_X, mid + i);
	head = (x * 4 + 4 * (int)RES_X * (mid + i));
	while (i <= RES_Y && head <= (RES_X * 4) * RES_Y)
	{
		
		// printf("ft_red_pixel : x %d size %d\n", x, head);
		ft_put_pixel_ceiling(w, head);

		ft_put_pixel_floor(w, (x * 4 + 4 * (int)RES_X * (mid - i)));
		// mlx_pixel_put(w->mlx, w->win1, x, mid + i, w->map->floor);
		// mlx_pixel_put(w->mlx, w->win1, x, mid - i, w->map->ceiling);
		i++;
		head = (x * 4 + 4 * RES_X * (mid + i));
		
	}
	w = w;
	
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
