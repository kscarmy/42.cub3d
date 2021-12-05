#include "../includes/libft.h"
#include "../mlx/mlx.h"

void	ft_init_win(w_point *win, m_point *mapi, c_point *cal) // mapi = map
{
	win->error = 0;
	if (!(win->mlx = mlx_init()))
	{
		ft_printf("Init mlx fail !\n");
		win->error = 1;
	}
	if (!(win->win1 = mlx_new_window(win->mlx, mapi->rx, mapi->ry,"win1")))
    {
		ft_printf("Init win1 fail !\n");
    	win->error = 1;
    }

	mlx_clear_window(win->mlx, win->win1);
	win->pos_x = 50;
	win->pos_y = 50;
	win->x = 0;
	win->y = 0;
	// win->casa = &(win->map->map);
	win->map = mapi;
	// win->calc = calcu; // init les deux struct hc et vc
	win->ca = cal;
	// win->vc = vca;
	win->move_size = 10;
	win->d_size = 10;
	ft_found_worldspawn(win);
}

int		ft_is_worldspawn(char c)
{
	if (c == 'N')
		return(1);
	if (c == 'S')
		return(1);
	if (c == 'E')
		return(1);
	if (c == 'O')
		return(1);
	return(0);
}

void	ft_found_worldspawn(w_point *win)
{
	ft_map_disp_pos(win);

    while (win->map->map[win->x] != NULL && ft_is_worldspawn(win->map->map[win->x][win->y]) == 0)
    {
        while (win->map->map[win->x][win->y] != '\0' && ft_is_worldspawn(win->map->map[win->x][win->y]) == 0)
        {
            win->y = win->y + 1;
        }
        
        if (ft_is_worldspawn(win->map->map[win->x][win->y]) == 0)
		{
			win->y = 0;
			win->x = win->x + 1;
		}
    }
	ft_printf("\nworldspawn : %c\n", win->map->map[win->x][win->y]);
	if (win->map->map[win->x][win->y] == 'N')
		win->d = 0;
	if (win->map->map[win->x][win->y] == 'E')
		win->d = 90;
	if (win->map->map[win->x][win->y] == 'S')
		win->d = 180;
	if (win->map->map[win->x][win->y] == 'O')
		win->d = 270;
	ft_printf("\ninit d : %d\n", (int) win->d);
	ft_printf("Pos_X : %d\nPos_Y : %d\nX : %d\nY : %d\n", win->pos_x, win->pos_y, win->x, win->y);
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
	// c_point calc; // déclaration strucure "calc" pour stocker les variables // OLD
	c_point ca; // déclaration structure de calcul
	// c_point vc; // déclaration structure de calcul vertical

	ft_init_win(&win, map, &ca);
	if (win.error > 0)
		ft_exit_free_all(&win, -1); // Free win et map puis exit(0);
	ft_printf("No errors\n"); // A SUPPRIMER
	ft_screen(&win);
	mlx_key_hook(win.win1,ft_entry_keyboard,&win);

	mlx_loop(win.mlx);
	ft_exit_free_all(&win, 0);
}
