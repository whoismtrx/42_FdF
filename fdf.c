/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/30 01:40:25 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_destroy(t_win *win)
{
	ft_free_data(win->data, 'z');
	ft_free_data(win->data, 'c');
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit (0);
}

int	ft_close(int key, t_win *win)
{
	if (key == 53)
	{
		ft_free_data(win->data, 'z');
		ft_free_data(win->data, 'c');
		mlx_destroy_image(win->mlx, win->img);
		mlx_destroy_window(win->mlx, win->mlx_win);
		exit (0);
	}
	return (0);
}

void	ft_hook(t_win *win)
{
	mlx_hook(win->mlx_win, 2, 0, ft_close, win);
	mlx_hook(win->mlx_win, 17, 0, ft_destroy, win);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_win		win;
	t_draw		draw;

	win.data = &data;
	if (argc != 2)
		exit (1);
	ft_allocate(&data, argv);
	ft_get_win(&win);
	ft_draw_map(&win, &data, &draw);
	mlx_put_image_to_window(win.mlx, win.mlx_win, win.img, 0, 0);
	ft_hook(&win);
	mlx_loop(win.mlx);
}
