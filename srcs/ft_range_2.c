#include "../includes/libft.h"

void	ft_not_angle_droit(w_point *win)
{

	while(ft_is_wall(win, win->hc->posxr, win->hc->posyr) && ft_is_wall(win, win->vc->posxr, win->vc->posyr))
	{
		if(win->hc->ray > win->vc->ray)
			//augmenter hc
		else
			//augmenter vc
	}
}

void	ft_up_hc(w_point *win)
{
	if(win->hc->ray == 0)
		ft_first_angle_hc(win);
	else
	{
		win->hc->oray = win->hc->ray;

	}
}

void	ft_first_angle_hc(w_point *win)
{
	if (0 < win->d && win->d < 90)
	{
		win->hc->rad = ft_degrees_to_radian(win->hc->deg);

	}
}

void	ft_up_vc(w_point *win)
{
	if(win->vc->ray == 0)
		ft_first_angle_vcwin);
	else
	{
		win->vc->oray = win->vc->ray;

	}
}

void	ft_first_angle_vc(w_point *win)
{
	if((0 < win->d && win->d < 90))
	{
		win->vc->rad = ft_degrees_to_radian(win->vc->deg - 90);
		win->vc->x = 100 - win->pos_x;
		win->vc->y = win->vc->x / ft_radian_to_degrees(tan(win->vc->rad));
		win->vc->ray = ft_pytha(win->vc->x, win->vc->y);
		win->vc->posxr = (int)(win->vc->x / 100);
	}
	win->vc->ray = ft_pytha(win->vc->x, win->vc->y);

}

double		ft_pytha(double x, double y)
{
	double ray;

	ray = sqrt( pow(x, 2) + pow(y, 2));
}