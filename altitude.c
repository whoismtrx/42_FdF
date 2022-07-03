/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:33:20 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/03 18:58:46 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	}
	ft_put_str_to_win(win);
}
