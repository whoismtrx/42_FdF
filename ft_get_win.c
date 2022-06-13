/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:28:16 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/12 23:10:31 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_win(t_win *win)
{
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, WIN_W, WIN_H, "FDF");
	win->img = mlx_new_image(win->mlx, WIN_W, WIN_H);
	win->add = mlx_get_data_addr(win->img, &win->bpp, &win->ll, &win->endian);
}
