#include "../includes/libft.h"

double	ft_degrees_to_radian(double deg)
{
	return(deg * M_PI / 180);
}

double	ft_radian_to_degrees(double rad)
{
	return(rad * 180 / M_PI);
}

// // void	ft_ent_to_dec(w_point *win, int s) // s = 1 = vc && s = 2 = hc && s = 3 = vc + hc
// // {
// // 	if(s == 1 || s == 3)
// // 	{
// // 		win->vc->xx = (win->vc->posxr + 100) + win->vc->px;
// // 		win->vc->xx = win->vc->xx / 100;
// // 		win->vc->yy = (win->vc->posyr + 100) + win->vc->py;
// // 		win->vc->yy = win->vc->yy / 100;
// // 	}
// // 	if(s == 2 || s == 3)
// // 	{
// // 		win->hc->xx = (win->hc->posxr + 100) + win->hc->px;
// // 		win->hc->xx = win->hc->xx / 100;
// // 		win->hc->yy = (win->hc->posyr + 100) + win->hc->py;
// // 		win->hc->yy = win->hc->yy / 100;
// // 	}
// // }

// // void	ft_dec_to_ent(w_point *win, int s) // s = 1 = vc && s = 2 = hc && s = 3 = vc + hc
// // {
// // 	if(s == 1 || s == 3)
// // 	{
// // 		win->vc->posxr = win->vc->xx / 100;
// // 		win->vc->px =  (int)win->vc->xx % 100;
// // 		win->vc->posyr = win->vc->yy / 100;
// // 		win->vc->py =  (int)win->vc->yy % 100;
// // 	}
// // 	if(s == 2 || s == 3)
// // 	{
// // 		win->hc->posxr = win->hc->xx / 100;
// // 		win->hc->px =  (int)win->hc->xx % 100;
// // 		win->hc->posyr = win->hc->yy / 100;
// // 		win->hc->py =  (int)win->hc->yy % 100;
// // 	}
// // }


// // void	ft_dec_to_ent_2(w_point *win, int s) // s = 1 = vc && s = 2 = hc && s = 3 = vc + hc
// // {
// // 	if(s == 1 || s == 3)
// // 	{
// // 		win->vc->posxr = win->vc->x / 100;
// // 		win->vc->px =  (int)win->vc->x % 100;
// // 		win->vc->posyr = win->vc->y / 100;
// // 		win->vc->py =  (int)win->vc->y % 100;
// // 	}
// // 	if(s == 2 || s == 3)
// // 	{
// // 		win->hc->posxr = win->hc->x / 100;
// // 		win->hc->px =  (int)win->hc->x % 100;
// // 		win->hc->posyr = win->hc->y / 100;
// // 		win->hc->py =  (int)win->hc->y % 100;
// // 	}
// // }

void	ft_red_pixel(w_point *win, int h, int x)
{
	int	i;
	int ret;
	int mid;

	i = 0;
	mid = win->map->ry/2;
	// ft_printf("red pixel : h : '%d' x : '%d'\n", h, x);
	while (i < h)
	{
		ret = mlx_pixel_put(win->mlx,win->win1, x, mid + i,0xFF99FF);
		ret = mlx_pixel_put(win->mlx,win->win1, x, mid - i,0xFF99FF);
		i++;
	}
	ret = ret;
}