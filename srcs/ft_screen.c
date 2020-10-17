#include "../includes/libft.h"

void	ft_screen(w_point *win)
{
	ft_set_screen(win);
}

void	ft_set_screen(w_point *win)
{
	float	tan;
	float	value;

	tan = 0.57735026919;
	// ft_printf
	value = ((win->map->rx / 2) / tan);
	printf("Value : %f\n", value);
	win->screen_range = (int)value;
	// win->screen_range = (value % 10 < 5) ? (int)value : (int)value + 1;
	printf("screen range : %d\n", win->screen_range);
	// win->screen_range = ((win->map->rx / 2) / tan);


}