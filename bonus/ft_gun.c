/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:54:17 by mourdani          #+#    #+#             */
/*   Updated: 2022/08/17 23:21:40 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	spawn_gun(t_w_point *w)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(w->mlx, "ress/bonus_gun.xpm", &img_width, &img_height);
	if (!img)
		return (-1);
	mlx_put_image_to_window(w->mlx, w->win1, img, 350, 479);
	return (1);
}
