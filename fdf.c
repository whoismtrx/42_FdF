/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/01 20:00:06 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_altitude(int key, t_win *win)
{
	if (key == 116)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->alt++;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	}
	else
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->alt--;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	}
}

void	ft_translate(int key, t_win *win)
{
	if (key == 123)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->trans_x -= 10;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	}
	else if (key == 124)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->trans_x += 10;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	}
	else if (key == 125)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->trans_y += 10;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	}
	else
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->trans_y -= 10;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	}
}

void	ft_zoom(int key, t_win *win)
{
	if (key == 69)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->zoom = 1;
		win->draw->dis++;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	}
	else
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->zoom = 1;
		if (win->draw->dis > 1)
			win->draw->dis--;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	}
}

void	ft_projection(int key, t_win *win)
{
	if (key == 35)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->pro = 0;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	}
	else
	{
		if (win->draw->pro == 1)
			return ;
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->pro = 1;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	}
}

void	ft_close(t_win *win)
{
	ft_free_data(win->data, 'z');
	ft_free_data(win->data, 'c');
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit (0);
}

int	ft_destroy(t_win *win)
{
	ft_free_data(win->data, 'z');
	ft_free_data(win->data, 'c');
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit (0);
}

int	ft_keys(int key, t_win *win)
{
	if (key == 53)
		ft_close(win);
	if (key == 34 || key == 35)
		ft_projection(key, win);
	if (key == 69 || key == 78)
		ft_zoom(key, win);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_translate(key, win);
	if (key == 116 || key == 121)
		ft_altitude(key, win);
	return (0);
}

void	ft_hook(t_win *win)
{
	mlx_hook(win->mlx_win, 2, 0, ft_keys, win);
	mlx_hook(win->mlx_win, 17, 0, ft_destroy, win);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_win		win;
	t_draw		draw;

	win.data = &data;
	win.draw = &draw;
	draw.pro = 1;
	draw.zoom = 0;
	draw.trans_x = 0;
	draw.trans_y = 0;
	draw.alt = 0;
	if (argc != 2)
		exit (1);
	ft_allocate(&data, argv);
	ft_get_win(&win);
	ft_draw_map(&win, &data, &draw);
	mlx_put_image_to_window(win.mlx, win.mlx_win, win.img, 0, 0);
	ft_hook(&win);
	mlx_loop(win.mlx);
}
