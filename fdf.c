/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/13 05:20:30 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_win		win;
	t_draw		draw;

	if (argc != 2)
		exit (1);
	ft_allocate(&data, argv);
	ft_get_win(&win);
	ft_draw_map(&win, &data, &draw);
	mlx_put_image_to_window(win.mlx, win.mlx_win, win.img, 0, 0);
	mlx_loop(win.mlx);
}
