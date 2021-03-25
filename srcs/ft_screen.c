#include "../includes/libft.h"

void	ft_screen(w_point *win)
{
	int r; // a supprimer

	r = 0; // a supprimer
	r = r;
	ft_set_screen(win);
	// ft_red_pixel(win, 50, 160); // test
	// ft_printf("r = '%d'\n");
	// ft_printf("r = '%d'\n", ft_found_range(win, 270)); // test
	// r = ft_found_range(win, 0); // a supprimer
	// ft_printf("r = '%d'\n");
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
	ft_printf("before disp screen\n");
	ft_disp_screen(win);
	ft_printf("after disp screen\n");
	// win->screen_range = ((win->map->rx / 2) / tan);


}

// void	ft_max_map(w_point *win)
// {
// 	double x;
// 	double y;

// 	x = 0;
// 	y = 0;
// 	while (win->map->map[x][y] != '\0')
// 	{
// 		while (win->map->map[x])
// 	}
// }


void	ft_disp_screen(w_point *win)
{
	int x;
	int i;
	int u;
	double ang; // angle entre deux colones en degrés

	x = win->map->rx; // =nombre colones
	i = 0; // compteur colones
	ang = 60 / (double)win->map->rx;
	printf("ang : '%lf'\n", ang);

	u = (x % 2 == 0) ? x / 2 + 1 : x / 2; // zone où se situe les colones
	u = u;
	// ft_thales(win, win->d, u); // test angle droit // A REMETTRE ET MODIFIER LA FONCTION SUREMENT
	//affichage colone milieu
	win->max_y = 0;
	while (win->map->map[win->max_y])
		win->max_y++;
	win->ca->x = (double)win->y - 1;
	win->ca->y = (double)win->x - 1;
	win->ca->xx = (double)win->pos_y;
	win->ca->yy = (double)win->pos_x;
	win->ca->xx = win->ca->xx / 100;
	win->ca->yy = win->ca->yy / 100;
	// printf("max y : '%d'\n", win->max_y);
	while (i < (x / 2)) // supp i < 10 car test
	{
		// printf("thales\n");
		ft_thales(win, (ang * i), u, i);
		// ft_thales(win, );
		// affichage colone droite
		// affichage colone gauche
		i++;
	}
	// affichage colone supplémentaire si rx est pair



}