#include "../includes/libft.h"


void	ft_set_ca(w_point *win)
{
	win->ca->hx = 0;
	win->ca->hy = 0;
	win->ca->vx = 0;
	win->ca->vy = 0;
	win->ca->ox = ((win->x * 100) + win->pos_x) / 100;
	win->ca->oy = ((win->x * 100) + win->pos_y) / 100;
	win->ca->phx = win->ca->ox;
	win->ca->phy = win->ca->oy;
	win->ca->pvx = win->ca->ox;
	win->ca->pvy = win->ca->oy;
	win->ca->deg = 0;
	win->ca->rad = 0;
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
	a++;
	b++;
	win->d = win->d;
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
	int	x;
	int y;
	int u; // a supp

	u = 2;
	x = win->x; // inversé ...
	y = win->y;	// inversé ...
	while (ft_is_wall(win, x, y) && u > 0)
	{
		if(d == 0)
			x = x - 1;
		if(d == 90)
			y = y + 1;
		if(d == 180)
			x = x + 1;
		if(d == 270)
			y = y - 1;
		u--;
	}
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


double	ft_found_angle(w_point *win, double d)
{
	double r;
	
	r = -1;
	ft_set_ca(win);
	// printf("range d : '%lf'\n", d);
	// ft_printf("DDDD: '%d'\n", (int)d);
	// ft_printf("TESTT : \n");
	// ft_printf("test : '%c' %d\n", win->map->map[5][5], (int)d);
	if (d == 0 || d == 90 || d == 180 || d == 270)
	{
		r = (double)ft_right_angle(win, d); 
	}
	else
	{
		win->ca->deg = d;
		win->ca->rad = ft_degrees_to_radian(win->ca->deg);
		// ft_printf("ELSE not angle droit\n");
		// printf("ft_found_angle\n");
		r = ft_not_angle_droit(win, d);
		
		/* code */
	}
	// ft_printf("r1 : '%d'\n", r);
	return(r);
}

void	ft_thales(w_point *win, double a, int c)
{
	double h; // hauteur à disp
	double r;

	r = 0;
	h = 0;
	a = a;
	r = ft_found_angle(win, win->d + a);
	printf("r = '%f'\n", r);
	h = (100 / r) * win->screen_range;
	// ft_printf("thales : h : '%d' r : '%d' test : '%d'", (int)h, (int)r, (100 / r) * win->screen_range);
	// printf("deg : '%lf'\n", win->d + a);
	ft_red_pixel(win, h, c);
}