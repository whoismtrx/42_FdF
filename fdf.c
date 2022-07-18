/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/04 01:05:18 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_keys(int key, t_win *win)
{
	if (key == 53)
		ft_close(win);
	if (key == 34 || key == 35)
		ft_projection(key, win);
	if (key == 0 || key == 2 || key == 1 || key == 13)
		ft_translate(key, win);
	if (key == 123 || key == 124 || key == 125 || key == 126
		|| key == 116 || key == 121)
		ft_rotation(key, win);
	if (key == 69 || key == 78)
		ft_altitude(key, win);
	if (key == 8)
		ft_colors(win);
	if (key == 15)
		ft_reset(win);
	return (0);
}

void	ft_hook(t_win *win)
{
	mlx_hook(win->mlx_win, 2, 0, ft_keys, win);
	mlx_hook(win->mlx_win, 17, 0, ft_destroy, win);
	mlx_mouse_hook(win->mlx_win, ft_zoom, win);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_win		win;
	t_draw		draw;

	win.data = &data;
	win.draw = &draw;
	if (argc != 2)
		exit (1);
	ft_reinit(&draw);
	ft_allocate(&data, argv);
	ft_get_win(&win);
	ft_draw_map(&win, &data, &draw);
	mlx_put_image_to_window(win.mlx, win.mlx_win, win.img, 0, 0);
	ft_put_str_to_win(&win);
	ft_hook(&win);
	mlx_loop(win.mlx);
}
