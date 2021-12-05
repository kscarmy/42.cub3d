#include "../includes/libft.h"

void    ft_map_disp_pos(w_point *win)
{
    int a;
    int c;

    a = 0;
    c = 0;
	ft_printf("pos : \n");
    while (win->map->map[a] != NULL)
    {
        while (win->map->map[a][c] != '\0')
        {
            ft_printf("\033[0m%c", win->map->map[a][c]);
            c++;
        }
        ft_printf("\n");
        c = 0;
        a++;
    }
    // map->error = erreur;
}

void	ft_move_in_casa(w_point *win)
{
	if (win->pos_x >= 100)
	{
		win->pos_x = 0;
		win->x = win->x + 1;
	}
	if (win->pos_x < 0)
	{
		win->pos_x = 100 - win->move_size;
		win->x = win->x - 1;
	}
	if (win->pos_y >= 100)
	{
		win->pos_y = 0;
		win->y = win->y + 1;
	}
	if (win->pos_y < 0)
	{
		win->pos_y = 100 - win->move_size;
		win->y = win->y - 1;
	}
	ft_map_disp_pos(win);
}

int		ft_move_zqsd(int key, w_point *win)
{
	if (key == KEY_MOVE_FRONT)
		win->pos_x = win->pos_x + win->move_size;
	if (key == KEY_MOVE_LEFT)
		win->pos_y = win->pos_y - win->move_size;
	if (key == KEY_MOVE_RIGHT)
		win->pos_x = win->pos_x - win->move_size;
	if (key == KEY_MOVE_BACK)
		win->pos_y = win->pos_y + win->move_size;
	if (win->pos_x > 100 || win->pos_x < 0 || win->pos_y > 100 || win->pos_y < 0)
		ft_move_in_casa(win);
	if (key == KEY_ROTATE_LEFT)
		win->d = win->d - win->d_size;
	if (key == KEY_ROTATE_RIGHT)
		win->d = win->d + win->d_size;
	if (win->d < 0)
		win->d = 350;
	if (win->d > 359)
		win->d = 0;
	return(0);
}
