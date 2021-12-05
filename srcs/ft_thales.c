#include "../includes/libft.h"


void	ft_set_ca(w_point *win)
{
	win->ca->hx = 0;
	win->ca->hy = 0;
	win->ca->vx = 0;
	win->ca->vy = 0;
	// win->ca->ox = ((win->x * 100) + win->pos_x) / 100;
	// win->ca->oy = ((win->x * 100) + win->pos_y) / 100;
	// win->ca->phx = win->ca->ox;
	// win->ca->phy = win->ca->oy;
	// win->ca->pvx = win->ca->ox;
	// win->ca->pvy = win->ca->oy;
	// win->ca->deg = 0;
	// win->ca->rad = 0;
	win->ca->hray = 0;
	win->ca->ohray = 0;
	win->ca->vray = 0;
	win->ca->ovray = 0;
}


double		ft_is_wall(w_point *win, double x, double y) // return 0 si mur, 1 sinon.
{
	int a;
	int b;


	a = (int)x;
	b = (int)y;
	// a++;
	// b++;
	win->d = win->d;
	win->max_x = 0;
	// printf("a '%d' b '%d'\n", a, b);

	if (a < 0 || b < 0 || a >= win->max_y) // ici x correspond au y ...
		{
		// printf("ERROR1\n");
		return (0);
		}
	// printf("ERROR2\n");
	// printf("map : '%c'\n", win->map->map[a][b]);
	while (win->map->map[a][win->max_x])
		win->max_x++;
	if (b > win->max_x)
		return (0);
	// printf("jean : %f\n", win->d);
	// printf("a : '%d' b : '%d'", a, b);

	if (win->map->map[a][b] != '\0' && win->map->map[a][b] == '1')
		return(0);
	else
		return(1);
	// return (1); // TEST A SUPP
}

int		ft_right_angle(w_point *win, double d)
{
	double	x;
	double y;
	// double u; // a supp

	// u = 2;
	x = win->x; // inversé ...
	y = win->y;	// inversé ...
	while (ft_is_wall(win, x, y)) // u secu
	{
		if(d == 0)
			x = x - 1;
		if(d == 90)
			y = y + 1;
		if(d == 180)
			x = x + 1;
		if(d == 270)
			y = y - 1;
		// u--;
	}
	// printf("x : '%f'\n", x);

	if(d == 0)
		return((win->x - x - 1) * 100 + win->pos_x);
	if(d == 90)
		return((y - win->y - 1) * 100 + win->pos_y);
	if(d == 180)
		return((x - win->x - 1) * 100 + win->pos_x);
	if(d == 270)
		return((win->y - y - 1) * 100 + win->pos_y);
	return(-1);
}

double	ft_converte_angle(double d, double a, int sig) // sig = addition 1 ou soustraction 0
{
	double deg;
	
	deg = d;
	// printf("\n\nfirst inter :\n");
	// printf("sig '%d' d '%f' a '%f' d + a '%f'\n\n", sig, d, a, (d + a));
	if ((deg - a) < 0 && sig == 0)
	{
		// printf("NEGATIF  d '%f' a '%f' d - a '%f'\n", d, a, (d - a));
		return (360 + (deg - a));
	}
	if ((d + a) >= 360 && sig == 1)
	{
		return (360 - (d + a));
		// printf("POSITIF  d '%f' a '%f' d + a '%f'\n", d, a, (d + a));
	}
	// printf("d '%f' a '%f' d + a '%f'\n", d, a, (d + a));
	return (d + a);

}

double	ft_found_angle(w_point *win, double d)
{
	double r;
	
	r = -1;
	ft_set_ca(win);
	
	// ft_printf("DDDD: '%d'\n", (int)d);
	// ft_printf("TESTT : \n");
	// ft_printf("test : '%c' %d\n", win->map->map[5][5], (int)d);
	if (d == 0 || d == 90 || d == 180 || d == 270)
	{
		r = (double)ft_right_angle(win, d);
		printf("\nangle droit d : '%lf' r : '%lf'\n", d, r);
	}
	else
	{
		win->ca->deg = d;
		win->ca->rad = ft_degrees_to_radian(win->ca->deg);
		// ft_printf("ELSE not angle droit\n");
		// printf("ft_found_angle\n");
		r = ft_not_angle_droit(win, d);
		printf("\nd : '%lf' r : '%lf'\n", d, r);
		
		/* code */
	}
	// ft_printf("r1 : '%d'\n", r);
	
	return(r);
}

void	ft_thales(w_point *win, double a, int c, int i)
{
	double h; // hauteur à disp
	double r;
	double u;

	r = 0;
	h = 0;
	u = c - i;
	// printf("PRE d '%f' a '%f' d + a '%f'\n", win->d, a, (win->d + a));
		// printf("pos r = '%f'\n", r);
	// printf ("TEST\n");
	r = ft_found_angle(win, ft_converte_angle(win->d, a, 1)); // droite de l ecran
	h = (100 / r) * win->screen_range;
	ft_red_pixel(win, h, c + i);

	// printf("NEG : '%f'\n", ft_converte_angle(win->d, a, 0));


	// r = ft_found_angle(win, ft_converte_angle(win->d, a, 0)); // gauche de l ecran
	// h = (100 / r) * win->screen_range;
	// ft_red_pixel(win, h, u);


	// printf("neg r = '%f'\n", r);
	// printf("c '%d' i '%d' u '%f'\n", c, i, u);
	
	// ft_printf("thales : h : '%d' r : '%d' test : '%d'", (int)h, (int)r, (100 / r) * win->screen_range);
	// printf("deg : '%lf'\n", win->d + a);
	// ft_red_pixel(win, h, u);
}