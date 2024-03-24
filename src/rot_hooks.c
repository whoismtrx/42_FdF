/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:35:25 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/03 18:56:33 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_z(int key, t_win *win)
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
}

void	rot_y(int key, t_win *win)
{
	if (key == 123)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
				&win->ll, &win->endian);
		win->draw->rot = 1;
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
		win->draw->b += 0.05;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
}

void	rot_x(int key, t_win *win)
{
	if (key == 126)
	{
		mlx_destroy_image(win->mlx, win->img);
		win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
		win->add = mlx_get_data_addr(win->img, &win->bpp,
				&win->ll, &win->endian);
		win->draw->rot = 1;
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
		win->draw->g -= 0.05;
		ft_draw_map(win, win->data, win->draw);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->img, 0, 0);
		ft_put_str_to_win(win);
	}
}

void	ft_rotation(int key, t_win *win)
{
	if (key == 121 || key == 116)
		rot_z(key, win);
	else if (key == 123 || key == 124)
		rot_y(key, win);
	else if (key == 126 || key == 125)
		rot_x(key, win);
}
