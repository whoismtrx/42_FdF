/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/03 04:57:14 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reinit(t_draw *draw)
{
	draw->pro = 1;
	draw->zoom = 0;
	draw->dist = 0;
	draw->trans_x = 0;
	draw->trans_y = 0;
	draw->alt = 0;
	draw->z = 1;
	draw->col = 0;
	draw->rot = 0;
	draw->a = 0;
	draw->b = 0;
	draw->g = 0;
}

void	ft_rotation(int key, t_win *win)
{
	if (key == 121)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->rot = 1;
		win->draw->a += 0.05;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
	else if (key == 116)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->rot = 1;
		win->draw->a -= 0.05;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
	else if (key == 123)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->rot = 1;
		win->draw->rx = 0;
		win->draw->ry = 1;
		win->draw->rz = 0;
		win->draw->b -= 0.05;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
	else if (key == 124)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->rot = 1;
		win->draw->rx = 0;
		win->draw->ry = 1;
		win->draw->rz = 0;
		win->draw->b += 0.05;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
	else if (key == 126)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->rot = 1;
		win->draw->rx = 0;
		win->draw->ry = 0;
		win->draw->rz = 1;
		win->draw->g += 0.05;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
	else if (key == 125)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->rot = 1;
		win->draw->rx = 0;
		win->draw->ry = 0;
		win->draw->rz = 1;
		win->draw->g -= 0.05;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
}

void	ft_reset(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img);
	win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
	win->add = mlx_get_data_addr(win->img, &win->bpp,
		&win->ll, &win->endian);
	ft_reinit(win->draw);
	ft_draw_map(win, win->data, win->draw);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	ft_put_str_to_win(win);
}

void	ft_colors(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img);
	win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
	win->add = mlx_get_data_addr(win->img, &win->bpp,
		&win->ll, &win->endian);
	win->draw->col = 1;
	win->draw->c += 111111111;
	ft_draw_map(win, win->data, win->draw);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
	ft_put_str_to_win(win);
}

void	ft_altitude(int key, t_win *win)
{
	if (key == 69)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->alt = 1;
		if (win->draw->z < 20)
			win->draw->z++;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
	else
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->alt = 1;
		if (win->draw->z > -20)
			win->draw->z--;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
}

void	ft_translate(int key, t_win *win)
{
	if (key == 0)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->trans_x -= 5;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
	else if (key == 2)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->trans_x += 5;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
	else if (key == 1)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->trans_y += 5;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
	else
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->trans_y -= 5;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
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
		ft_put_str_to_win(win);
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
		ft_put_str_to_win(win);
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

int	ft_zoom(int key, int x, int y, t_win *win)
{
	(void)x;
	(void)y;
	if (key == 4)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->zoom = 1;
		if (win->draw->dist < 20)
			win->draw->dist++;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
	else if (key == 5)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
			&win->ll, &win->endian);
		win->draw->zoom = 1;
		if (win->draw->dis + win->draw->dist > 1)
		{
			if (win->draw->dist > -20)
				win->draw->dist--;
		}
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
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
