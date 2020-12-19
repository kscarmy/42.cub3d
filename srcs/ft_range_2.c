#include "../includes/libft.h"

void	ft_not_angle_droit(w_point *win, double d)
{
	win->vc->deg = d;
	int x;//sup

	x = 1;//sup
	// printf("not angle droit d : '%lf'\n", d);
	// printf("test calc : '%lf'\n", 100*ft_radian_to_degrees(tan(1.0472)));
	while(ft_is_wall(win, win->hc->posxr, win->hc->posyr) && ft_is_wall(win, win->vc->posxr, win->vc->posyr) && x > 0)
	{
		if(win->hc->ray > win->vc->ray)
		{
			//augmenter hc
			// ft_printf("up hc\n");
		}
		else
		{
			//augmenter vc
			// ft_printf("up vc\n");
			ft_up_vc(win);
		}
		x--;//sup
	}
}

// void	ft_up_hc(w_point *win)
// {
// 	if(win->hc->ray == 0)
// 		ft_first_angle_hc(win);
// 	else
// 	{
// 		win->hc->oray = win->hc->ray;

// 	}
// }

// void	ft_first_angle_hc(w_point *win)
// {
// 	if (0 < win->d && win->d < 90)
// 	{
// 		win->hc->rad = ft_degrees_to_radian(win->hc->deg);

// 	}
// }

void	ft_up_vc(w_point *win)
{
	if(win->vc->ray == 0)
	{
		// printf("first vc\n");
		ft_first_angle_vc(win);
	}
	else
	{
		// ft_printf("else up vc\n");
		// win->vc->oray = win->vc->ray; // a remettre

	}
}

void	ft_first_angle_vc(w_point *win)
{
	if(0 < win->vc->deg && win->vc->deg < 90)
	{
		win->vc->rad = ft_degrees_to_radian(win->vc->deg - 90);
		win->vc->x = 100 - win->pos_x;
		win->vc->y = win->vc->x * ft_radian_to_degrees(tan(win->vc->rad));
		win->vc->ray = ft_pytha(win->vc->x, win->vc->y);
		// win->vc->posxr = (int)(win->vc->x / 100); // ??????
	}
	win->vc->ray = ft_pytha(win->vc->x, win->vc->y);
	// printf("first angle\n");
	ft_second_angle_vc(win);
}

// void	ft_found_xy_vc(w_point *win)
// {
// 	win->vc->x = 100;
// 	win->vc->y = win->vc->x / ft_radian_to_degrees(tan(win->vc->rad));
// }


void	ft_second_angle_vc(w_point *win)
{
	if(40 < win->vc->deg && win->vc->deg < 90)
	{
		win->vc->posxr = win->vc->posxr + 1;
		win->vc->posyr = win->vc->posyr + (win->vc->y / 100);

		win->vc->x = 100;
		win->vc->y = win->vc->x * ft_radian_to_degrees(tan(win->vc->rad)); // ?
		
	}
	else
	{
		win->vc->x = 100;
		win->vc->y = -1;
	}
	
	printf("xx '%lf' yy '%lf' x '%lf' y '%lf' \n", win->vc->xx, win->vc->yy, win->vc->x, win->vc->y);
}

void	ft_first_angle_hc(w_point *win)
{
	if(0 < win->hc->deg && win->hc->deg < 90)
	{
		win->hc->rad = ft_degrees_to_radian(win->hc->deg - 90);
		win->hc->x = 100 - win->pos_x;
		win->hc->y = win->hc->x * ft_radian_to_degrees(tan(win->hc->rad));
		win->hc->ray = ft_pytha(win->hc->x, win->hc->y);
	}
	win->hc->ray = ft_pytha(win->hc->x, win->hc->y);
	ft_second_angle_hc(win);
}

void	ft_second_angle_hc(w_point *win)
{
	if(40 < win->hc->deg && win->hc->deg < 90)
	{
		win->hc->posxr = win->hc->posxr + 1;
		win->hc->posyr = win->hc->posyr + (win->hc->y / 100);

		win->hc->x = 100;
		win->hc->y = win->hc->x * ft_radian_to_degrees(tan(win->hc->rad)); // ?
		
	}
	else
	{
		win->hc->x = 100;
		win->hc->y = -1;
	}
	
	printf("xx '%lf' yy '%lf' x '%lf' y '%lf' \n", win->hc->xx, win->hc->yy, win->hc->x, win->hc->y);
}

double		ft_pytha(double x, double y) // rend la distance
{
	double ray;

	ray = sqrt( pow(x, 2) + pow(y, 2));
	return(ray);
}