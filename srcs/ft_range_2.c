// #include "../includes/libft.h"

// void	ft_not_angle_droit(w_point *win, double d)
// {
// 	win->vc->deg = d;
// 	int x;//sup

// 	x = 10;//sup
// 	// printf("not angle droit d : '%lf'\n", d);
// 	// printf("test calc : '%lf'\n", 100*ft_radian_to_degrees(tan(1.0472)));
// 	// ft_printf("IN\n");
// 	// ft_printf("hcx'%d' hcy'%d' vcx'%d' vcy'%d'\n", win->hc->posxr, win->hc->posyr, win->vc->posxr, win->vc->posyr);
// 	while(ft_is_wall(win, win->hc->posxr, win->hc->posyr) && ft_is_wall(win, win->vc->posxr, win->vc->posyr) && x > 0) //  && x > 0
// 	{
// 		if(win->hc->ray > win->vc->ray)
// 		{
// 			//augmenter hc
// 			ft_up_hc(win);
// 			// ft_printf("up hc\n");
// 		}
// 		else
// 		{
// 			//augmenter vc
// 			// ft_printf("up vc\n");
// 			ft_up_vc(win);
// 		}
// 		ft_printf("hcx'%d' hcy'%d' vcx'%d' vcy'%d'\n", win->hc->posxr, win->hc->posyr, win->vc->posxr, win->vc->posyr);
// 		x--;//sup
// 	}
// 	// ft_printf("OUT\n");
// }

// void	ft_up_hc(w_point *win)
// {
// 	if(win->hc->ray == 0)
// 		ft_first_angle_hc(win);
// 	else
// 	{
// 		win->hc->y = win->hc->y + 100;
// 		win->hc->x = win->hc->x + (100 / ft_radian_to_degrees(tan(win->hc->rad)));
// 		ft_dec_to_ent_2(win, 2);
// 		// win->hc->oray = win->hc->ray;
// 		win->hc->oray = win->hc->ray; // a remettre
// 		win->hc->ray = ft_pytha(win->hc->x, win->hc->y);
// 		ft_printf("ray : '%d'\n", win->hc->ray);

// 	}
// }

// // void	ft_first_angle_hc(w_point *win)
// // {
// // 	if (0 < win->d && win->d < 90)
// // 	{
// // 		win->hc->rad = ft_degrees_to_radian(win->hc->deg);

// // 	}
// // }

// void	ft_up_vc(w_point *win)
// {
// 	// ft_printf("in up vc\n");
// 	if(win->vc->ray == 0)
// 	{
// 		// printf("first vc\n");
// 		ft_first_angle_vc(win);
// 	}
// 	else
// 	{
// 		// ft_printf("in up vc else\n");
// 		win->vc->x = win->vc->x + 100;
// 		win->vc->y = win->vc->y + (100 / ft_radian_to_degrees(tan(win->vc->rad)));
// 		ft_dec_to_ent_2(win, 1);
		
// 		// ft_printf("else up vc\n");
// 		win->vc->oray = win->vc->ray; // a remettre
// 		win->vc->ray = ft_pytha(win->vc->x, win->vc->y);
// 		ft_printf("ray : '%d'\n", win->vc->ray);

// 	}
// 	// ft_printf("out up vc\n");
// }

// void	ft_first_angle_vc(w_point *win)
// {
// 	if(0 < win->vc->deg && win->vc->deg < 90)
// 	{
// 		win->vc->rad = ft_degrees_to_radian(win->vc->deg - 90);
// 		win->vc->x = 100 - win->pos_x;
// 		win->vc->y = win->vc->x * ft_radian_to_degrees(tan(win->vc->rad));
// 		win->vc->ray = ft_pytha(win->vc->x, win->vc->y);
// 		// win->vc->posxr = (int)(win->vc->x / 100); // ??????
// 	}
// 	win->vc->ray = ft_pytha(win->vc->x, win->vc->y);
// 	// printf("first angle\n");
// 	ft_second_angle_vc(win);
// }

// // void	ft_found_xy_vc(w_point *win)
// // {
// // 	win->vc->x = 100;
// // 	win->vc->y = win->vc->x / ft_radian_to_degrees(tan(win->vc->rad));
// // }


// void	ft_second_angle_vc(w_point *win)
// {
// 	if(40 < win->vc->deg && win->vc->deg < 90)
// 	{
// 		win->vc->posxr = win->vc->posxr + 1;
// 		win->vc->posyr = win->vc->posyr + (win->vc->y / 100);

// 		win->vc->x = 100;
// 		win->vc->y = win->vc->x * ft_radian_to_degrees(tan(win->vc->rad)); // ?
		
// 	}
// 	else
// 	{
// 		win->vc->x = 100;
// 		win->vc->y = -1;
// 	}
	
// 	// printf("xx '%lf' yy '%lf' x '%lf' y '%lf' \n", win->vc->xx, win->vc->yy, win->vc->x, win->vc->y);
// }

// void	ft_first_angle_hc(w_point *win)
// {
// 	if(0 < win->hc->deg && win->hc->deg < 90)
// 	{
// 		win->hc->rad = ft_degrees_to_radian(win->hc->deg - 90);
// 		win->hc->y = 100 - win->pos_y;
// 		win->hc->x = win->hc->y * ft_radian_to_degrees(tan(win->hc->rad));
// 		win->hc->ray = ft_pytha(win->hc->x, win->hc->y);
// 	}
// 	win->hc->ray = ft_pytha(win->hc->x, win->hc->y);
// 	ft_second_angle_hc(win); //test launch
// }

// void	ft_second_angle_hc(w_point *win) // test launch
// {
// 	if(40 < win->hc->deg && win->hc->deg < 90)
// 	{
// 		win->hc->posyr = win->hc->posyr + 1;
// 		win->hc->posxr = win->hc->posxr + (win->hc->x / 100);

// 		win->hc->y = 100;
// 		win->hc->x = win->hc->y * ft_radian_to_degrees(tan(win->hc->rad)); // ?
		
// 	}
// 	else
// 	{
// 		win->hc->y = 100;
// 		win->hc->x = -1;
// 	}
	
// 	// printf("xx '%lf' yy '%lf' x '%lf' y '%lf' \n", win->hc->xx, win->hc->yy, win->hc->x, win->hc->y);
// }

// double		ft_pytha(double x, double y) // rend la distance
// {
// 	double ray;

// 	ray = sqrt( pow(x, 2) + pow(y, 2));
// 	return(ray);
// }