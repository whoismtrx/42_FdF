/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:10:25 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/03 18:56:43 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
