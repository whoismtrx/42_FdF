/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:05:06 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/03 18:56:00 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_win *win)
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

void	zoom_out(t_win *win)
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

int	ft_zoom(int key, int x, int y, t_win *win)
{
	(void)x;
	(void)y;
	if (key == 4)
		zoom_in(win);
	else if (key == 5)
		zoom_out(win);
	return (0);
}
