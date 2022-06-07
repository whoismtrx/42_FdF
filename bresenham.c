/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:57:24 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/07 01:17:35 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_step(int a, int b)
{

	if (a < b)
		return (1);
	return (-1);
}

void	bresenham(t_data *data, t_bresen *bresen, t_graph *graph, int x0, int x1, int y0, int y1)
{
	bresen->x0 = x0;
	bresen->x1 = x1;
	bresen->y0 = y0;
	bresen->y1 = y1;
	bresen->dx = abs(x1 - x0);
	bresen->sx = ft_get_step(bresen->x0, bresen->x1);
	bresen->dy = -abs(y1 - y0);
	bresen->sy = ft_get_step(bresen->y0, bresen->y1);
	bresen->dp1 = bresen->dx + bresen->dy;
	while (1)
	{
		my_mlx_pixel_put(graph, bresen->x0, bresen->y0, 16777215);
		if (bresen->x0 == bresen->x1 && bresen->y0 == bresen->y1)
			break;
		bresen->dp2 = 2 * bresen->dp1;
		if (bresen->dp2 >= bresen->dy)
		{
			if (bresen->x0 == bresen->x1)
				break;
			bresen->dp1 += bresen->dy;
			bresen->x0 += bresen->sx;
		}
		if (bresen->dp2 <= bresen->dx)
		{
			if (bresen->y0 == bresen->y1)
				break;
			bresen->dp1 += bresen->dx;
			bresen->y0 += bresen->sy;
		}
	}
}