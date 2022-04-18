#include "fdf.h"

int main()
{
	t_data	data;


	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "FdF");
	data.img = mlx_new_image(data.mlx, 1920, 1080);
	data.add = mlx_get_data_addr(data.img, &data.bpp, &data.ll, &data.endian);
	mlx_pixel_put(data.mlx, data.mlx_win, 5, 5, 0X00FF0000);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);
}