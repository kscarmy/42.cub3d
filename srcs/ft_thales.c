#include "../includes/libft.h"

void	ft_thales(w_point *win, double a, int c)
{
	double h; // hauteur à disp
	double r;

	r = ft_found_range(win, win->d + a);
	h = (100 / r) * win->screen_range;
	ft_printf("thales : h : '%d' r : '%d' test : '%d'", h, r, (100 / r) * win->screen_range);
	printf("deg : '%lf'\n", win->d + a);
	ft_red_pixel(win, h, c);
}