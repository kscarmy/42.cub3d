// #include "mlx/mlx.h"
// #include <stdio.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	printf("TEST\n");

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// }


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx/mlx.h"

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 data_t;

int main(void)
{
    data_t        data;

    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
        return (EXIT_FAILURE);
	mlx_pixel_put(data.mlx_ptr, data.mlx_win, 10, 20, 0x00FF0000);
	mlx_clear_window(data.mlx_ptr, data.mlx_win);
	// if ((data.mlx_win = mlx_pixel_put(data.mlx_ptr, data.mlx_win, 10, 20, 0x00FF0000)) == NULL)
    //     return (EXIT_FAILURE);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}