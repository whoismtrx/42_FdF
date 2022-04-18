#include "fdf.h"

int main()
{
	void	*mlx;
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FdF");
	img = mlx_new_image(mlx, 1920, 1080);
	add = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	mlx_pixel_put(mlx, mlx_win, 5, 5, 0X00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);

}