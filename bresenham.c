/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:57:24 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/13 01:26:30 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_data *data, t_draw *draw, t_win *win, int b)
{
	init(draw, data, b);
	while (1)
	{
		if ((draw->x0 > 0 && draw->x0 < 1920)
			&& (draw->y0 > 0 && draw->y0 < 1080))
			my_mlx_pixel_put(win, draw->x0,
				draw->y0, data->c[draw->y][draw->x]);
		if (draw->x0 == draw->x1 && draw->y0 == draw->y1)
			break ;
		draw->dp2 = 2 * draw->dp1;
		if (draw->dp2 >= draw->dy)
		{
			if (draw->x0 == draw->x1)
				break ;
			draw->dp1 += draw->dy;
			draw->x0 += draw->sx;
		}
		if (draw->dp2 <= draw->dx)
		{
			if (draw->y0 == draw->y1)
				break ;
			draw->dp1 += draw->dx;
			draw->y0 += draw->sy;
		}
	}
}
