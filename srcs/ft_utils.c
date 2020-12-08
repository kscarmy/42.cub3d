#include "../includes/libft.h"

double	ft_degrees_to_radian(double deg)
{
	return(deg * M_PI / 180);
}

double	ft_radian_to_degrees(double rad)
{
	return(rad * 180 / M_PI);
}

void	ft_red_pixel(w_point *win, int h, int x)
{
	int	i;
	int ret;
	int mid;

	i = 0;
	mid = win->map->ry/2;
	while (i < h)
	{
		ret = mlx_pixel_put(win->mlx,win->win1, x, mid + i,0xFF99FF);
		ret = mlx_pixel_put(win->mlx,win->win1, x, mid - i,0xFF99FF);
		i++;
	}
	ret = ret;
}