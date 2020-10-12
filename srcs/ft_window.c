#include "../includes/libft.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
void	ft_init_win(w_point *win, m_point *mapi) // mapi = map
{
	win->error = 0;
	if (!(win->mlx = mlx_init()))
	{
		printf("Init mlx fail !\n");
		win->error = 1;
	}
	if (!(win->win1 = mlx_new_window(win->mlx, mapi->rx, mapi->ry,"win1")))
    {
		printf("Init win1 fail !\n");
    	win->error = 1;
    }
	mlx_clear_window(win->mlx, win->win1);
	win->map = mapi;
}

void	ft_exit_free_all(w_point *win, int ret)
{
	ft_printf("All is begin freeing\n");
	// mlx_destroy_image(win->mlx, win->im1); // Pour une image
	mlx_clear_window(win->mlx, win->win1);
	mlx_destroy_window(win->mlx, win->win1);

	exit(ft_exit_free_map(win->map, ret));
}

void	ft_windows(m_point *map)
{
	w_point win; // déclaration strucure "win" pour windows

	ft_init_win(&win, map);
	if (win.error > 0)
		ft_exit_free_all(&win, -1); // Free win et map puis exit(0);
	ft_printf("No errors\n"); // A SUPPRIMER
	mlx_loop(win.mlx);
	ft_exit_free_all(&win, 0);
}
