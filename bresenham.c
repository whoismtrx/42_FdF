/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:57:24 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/13 01:26:30 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_data *data, t_bresen *bresen, t_win *win, int b)
{
	init(bresen, data, b);
	while (1)
	{
		if ((bresen->x0 > 0 && bresen->x0 < 1920)
			&& (bresen->y0 > 0 && bresen->y0 < 1080))
			my_mlx_pixel_put(win, bresen->x0,
				bresen->y0, data->c[bresen->y][bresen->x]);
		if (bresen->x0 == bresen->x1 && bresen->y0 == bresen->y1)
			break ;
		bresen->dp2 = 2 * bresen->dp1;
		if (bresen->dp2 >= bresen->dy)
		{
			if (bresen->x0 == bresen->x1)
				break ;
			bresen->dp1 += bresen->dy;
			bresen->x0 += bresen->sx;
		}
		if (bresen->dp2 <= bresen->dx)
		{
			if (bresen->y0 == bresen->y1)
				break ;
			bresen->dp1 += bresen->dx;
			bresen->y0 += bresen->sy;
		}
	}
}
