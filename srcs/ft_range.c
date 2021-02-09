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

// int		ft_is_wall(w_point *win, int x, int y) // return 0 si mur, 1 sinon.
// {
// 	// ft_printf("where2 : '%c'\n", win->map->map[x][y]);
// 	if(win->map->map[x][y] == '1')
// 		return(0);
// 	else
// 		return(1);
// 	// return (0); // a supprimer
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

// // int		ft_is_wall(w_point *win) // renvoie 1 si pas de mur, 0 si un mur
// // {
// // 	if (win->calc->posxr)
	
// // }



void	ft_not_angle_droit(w_point *win, double d)
{
	win->ca->deg = d;
	int x;//sup

	x = 3;//sup
	// printf("not angle droit d : '%lf'\n", d);
	// printf("test calc : '%lf'\n", 100*ft_radian_to_degrees(tan(1.0472)));
	// ft_printf("IN\n");
	// ft_printf("hcx'%d' hcy'%d' vcx'%d' vcy'%d'\n", win->hc->posxr, win->hc->posyr, win->vc->posxr, win->vc->posyr);
	while(ft_is_wall(win, win->hc->posxr, win->hc->posyr) && ft_is_wall(win, win->vc->posxr, win->vc->posyr) && x > 0) //  && x > 0
	{
		if(win->hc->ray > win->vc->ray)
		{
			//augmenter hc
			// ft_up_hc(win);
			// ft_printf("up hc\n");
		}
		else
		{
			//augmenter vc
			// ft_printf("up vc\n");
			// ft_up_vc(win);
		}
		// ft_printf("hcx'%d' hcy'%d' vcx'%d' vcy'%d'\n", win->hc->posxr, win->hc->posyr, win->vc->posxr, win->vc->posyr);
		x--;//sup
	}
	// ft_printf("OUT\n");
}