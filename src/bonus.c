/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:52:07 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/03 18:57:03 by orekabe          ###   ########.fr       */
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
