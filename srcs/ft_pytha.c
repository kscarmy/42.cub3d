#include "../includes/libft.h"

void	ft_up_vert(w_point *win, double d)
{
	double x;
	double y;

	x = 0;
	y = 0;
	if (d < 90 || d > 270)
	{
		y = 1;
		if (d < 45)	
		{
			x = y / tan(ft_degrees_to_radian(win->ca->deg));
			win->ca->pvx = win->ca->pvx + x;
			win->ca->pvy = win->ca->pvy + y;
		}
	}
	win->ca->vray = win->ca->vray + ft_pytha(x, y);
}