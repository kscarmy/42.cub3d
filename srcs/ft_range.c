#include "../includes/libft.h"



// void	ft_reset_calc(w_point *win)
// {
// 	win->hc->set = 0;
// 	win->hc->deg = 0;
// 	win->hc->rad = 0;
// 	win->hc->x = 0;
// 	win->hc->y = 0;
// 	win->hc->posxr = win->x;
// 	win->hc->posyr = win->y;
// 	win->hc->px = win->pos_x;
// 	win->hc->py = win->pos_y;
// 	win->hc->ray = 0;
// 	win->hc->oray = 0;
// 	win->hc->xx = 0;
// 	win->hc->yy = 0;

// 	win->vc->set = 0;
// 	win->vc->deg = 0;
// 	win->vc->rad = 0;
// 	win->vc->x = 0;
// 	win->vc->y = 0;
// 	win->vc->posxr = win->x;
// 	win->vc->posyr = win->y;
// 	win->vc->px = win->pos_x;
// 	win->vc->py = win->pos_y;
// 	win->vc->ray = 0;
// 	win->vc->oray = 0;
// 	win->vc->xx = 0;
// 	win->vc->yy = 0;
// }


// FT IS WALL EST DANS FT THALES
// int		ft_is_wall(w_point *win, int x, int y) // return 0 si mur, 1 sinon.
// {
// 	// ft_printf("where2 : '%c'\n", win->map->map[x][y]);
// 	if(win->map->map[x][y] == '1')
// 		return(0);
// 	else
// 		return(1);
	// return (0); // a supprimer
// }

// int		ft_right_angle(w_point *win, double d)
// {
// 	int	x;
// 	int y;

// 	x = win->x; // inversé ...
// 	y = win->y;	// inversé ...
// 	while (ft_is_wall(win, x, y))
// 	{
// 		if(d == 0)
// 			x = x - 1;
// 		if(d == 90)
// 			y = y + 1;
// 		if(d == 180)
// 			x = x + 1;
// 		if(d == 270)
// 			y = y - 1;
// 	}
// 	win->hc->set = 1;
// 	win->hc->posxr = y;
// 	win->hc->posyr = x;
// 	if(d == 0)
// 		return((win->x - x - 1) * 100 + win->pos_x);
// 	if(d == 90)
// 		return((y - win->y - 1) * 100 + win->pos_y);
// 	if(d == 180)
// 		return((x - win->x - 1) * 100 + win->pos_x);
// 	if(d == 270)
// 		return((win->y - y - 1) * 100 + win->pos_y);
// 	return(-1);
// }

// int		ft_found_range(w_point *win, double d)
// {
// 	int r;
	
// 	r = -1;
// 	ft_reset_calc(win);
// 	// printf("range d : '%lf'\n", d);
// 	// ft_printf("DDDD: '%d'\n", (int)d);
// 	// ft_printf("TESTT : \n");
// 	// ft_printf("test : '%c' %d\n", win->map->map[5][5], (int)d);
// 	if (d == 0 || d == 90 || d == 180 || d == 270)
// 	{
// 		win->hc->ray = ft_right_angle(win, d);
// 		r = win->hc->ray; 
// 	}
// 	else
// 	{
// 		// ft_printf("ELSE not angle droit\n");
// 		ft_not_angle_droit(win, d);
		
// 		/* code */
// 	}
// 	// ft_printf("r1 : '%d'\n", r);
// 	return(r);
// }



// // void		ft_found_range(w_point *win)
// // {
// // 	ft_printf("JE PASSE ?\n");
// // 	win->calc->posxr = win->x;
// // 	win->calc->posyr = win->y;
// // 	win->calc->px = win->pos_x;
// // 	win->calc->py = win->pos_y;

// // 	win->calc->deg = win->d; // à supprimer, uniquement pour tester le bon déroulement de la fonction
// // 	ft_first_inter(win); // à supprimer, test 
// // 	// if (win->d_size == 0 || win->d_size == 90 || win->d_size == 180 || win->d_size == 270)
// // 	// 	ft_right_angle(win);
// // }

// // void	ft_calc_angle(w_point *win)
// // {

// // }


// // void	ft_first_inter(w_point *win)
// // {
// // 	win->calc->deg = win->d;
// // 	ft_degrees_to_radian(win);
// // 	win->calc->y = win->calc->py;

// // }




// // void	ft_calc_pytha(w_point *win)
// // {
	
// // }



// // void		ft_right_angle(w_point *win)
// // {
// // 	int coef;

// // 	coef = win->d_size / 90;
// // 	while (ft_is_wall(win))
// // 	{
// // 		if (coef == 0)
// // 			win->calc->posyr = 1;
// // 	}
// // }


void	ft_reset_ca(w_point *win)
{
	win->ca->hx = 0;
	win->ca->hy = 0;
	win->ca->vx = 0;
	win->ca->vy = 0;
	win->ca->phx = 0;
	win->ca->phy = 0;
	win->ca->pvx = 0;
	win->ca->pvy = 0;

}




void	ft_first_vc_hc(w_point *win, double d)
{
	double x;
	double y;
	double rad;

	x = 0;
	y = 0;
	rad = ft_degrees_to_radian(90 - win->ca->deg);
	win->ca->vray = 0; // A SUPP
	win->ca->hray = 0;
	if (d < 90) // vc
	{
		x = win->pos_x;
		x = x / 100;
		y = x / tan(win->ca->rad);
		win->ca->pvx = (double)win->x + (x / 100);
		win->ca->pvy = (double)win->y + (y / 100);
		win->ca->vray = ft_pytha(x, y);
		// printf("x '%f' y '%f' pvx '%f' pvy '%f' vray '%f'\n", x, y, win->ca->pvx, win->ca->pvy, win->ca->vray);
	}
	if (d < 90) // hc
	{
		y = win->pos_y;
		y = y / 100;
		x = y / tan(rad);
		win->ca->phx = (double)win->x + (x / 100);
		win->ca->phy = (double)win->y + (y / 100);
		win->ca->hray = ft_pytha(x, y);
		// printf("x '%f' y '%f' phx '%f' phy '%f' hray '%f'\n", x, y, win->ca->phx, win->ca->phy, win->ca->hray);
	}
	// printf("first vc hc : '%f' '%f'\n", win->ca->vray, win->ca->hray);
}

void	ft_up_vc(w_point *win, double d) // A REMETTRE
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (d < 90)
	{
		x = 1;
		y = x / tan(win->ca->rad);
		win->ca->pvx = win->ca->pvx + (x / 100);
		win->ca->pvy = win->ca->pvy + (y / 100);
		win->ca->vray = win->ca->vray + ft_pytha(x, y);
	}
	// ft_printf("else in up hc");
}



void	ft_up_hc(w_point *win, double d)
{
	int x;
	int y;
	double rad;
	
	x = 0;
	y = 0;
	rad = ft_degrees_to_radian(90 - win->ca->deg);
	if (d < 90)
	{
		y = 1;
		x = y / tan(rad);
		win->ca->phx = win->ca->phx + (x / 100);
		win->ca->phy = win->ca->phy + (y / 100);
		win->ca->hray = win->ca->hray + ft_pytha(x, y);
	}
	// ft_printf("else in up hc");
}









double	ft_not_angle_droit(w_point *win, double d)
{
	win->ca->deg = d;
	int x;//sup

	x = 3;//sup protection anti while 1
	// win->ca->hx = 0;
	// win->ca->hy = 0;
	// win->ca->vx = 0;
	// win->ca->vy = 0;
	ft_reset_ca(win);
	// printf("not angle droit d : '%lf'\n", d);
	// printf("test calc : '%lf'\n", 100*ft_radian_to_degrees(tan(1.0472)));

	
	// ft_printf("IN\n");
	// ft_printf("hcx'%d' hcy'%d' vcx'%d' vcy'%d'\n", win->hc->posxr, win->hc->posyr, win->vc->posxr, win->vc->posyr);
	while(ft_is_wall(win, win->ca->hx, win->ca->hy) && ft_is_wall(win, win->ca->vx, win->ca->vy) && x > 0) //  && x > 0
	{
		if (win->ca->hray == 0 && win->ca->vray == 0)
			ft_first_vc_hc(win, d);
		if(win->ca->hray > win->ca->vray)
		{
			//augmenter hc
			ft_printf("up hc\n");
			ft_up_hc(win, d);
			win->ca->hx = win->ca->phx;
			win->ca->hy = win->ca->phy;
			// ft_printf("up hc\n");
		}
		else
		{
			//augmenter vc
			// ft_printf("up vc\n");
			ft_printf("up vc\n");
			ft_up_vc(win, d);
			win->ca->vx = win->ca->pvx;
			win->ca->vy = win->ca->pvy;
		}
		// ft_printf("hcx'%d' hcy'%d' vcx'%d' vcy'%d'\n", win->hc->posxr, win->hc->posyr, win->vc->posxr, win->vc->posyr);
		x--;//sup
		// printf("win : hx '%f' hy '%f' vx '%f' vy '%f'\n", win->ca->hx, win->ca->hy, win->ca->vx, win->ca->vy);

	}
	if (win->ca->vray < win->ca->hray)
		return (win->ca->vray * 100);
	else
		return (win->ca->hray * 100);
	// ft_printf("OUT\n");
}