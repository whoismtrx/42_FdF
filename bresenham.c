/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:57:24 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/09 05:42:54 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_step(int a, int b)
{

	if (a < b)
		return (1);
	return (-1);
}

void	zoom(t_bresen *bresen)
{	bresen->x0 *= 20;
	bresen->x1 *= 20;
	bresen->y0 *= 20;
	bresen->y1 *= 20;
	// bresen->z0 *= 20;
	// bresen->z1 *= 20;
}

void	iso(t_bresen *bresen)
{
	int px0;
	int py0;
	int px1;
	int py1;
	
	px0 = bresen->x0;
	px1 = bresen->x1;
	py0 = bresen->y0;
	py1 = bresen->y1;
	bresen->x0 = (px0 - py0) * cos(0.523599);
	bresen->y0 = -bresen->z0 + (px0 + py0) * sin(0.523599);
	bresen->x1 = (px1 - py1) * cos(0.523599);
	bresen->y1 = -bresen->z1 + (px1 + py1) * sin(0.523599);
}

void	bresenham(t_data *data, t_bresen *bresen, t_graph *graph, int x0, int x1, int y0, int y1)
{
	bresen->x0 = x0;
	bresen->x1 = x1;
	bresen->y0 = y0;
	bresen->y1 = y1;
	bresen->z0 = data->z[y0][x0];
	bresen->z1 = data->z[y1][x1];
	zoom(bresen);
	iso(bresen);
	bresen->dx = abs(bresen->x1 - bresen->x0);
	bresen->sx = ft_get_step(bresen->x0, bresen->x1);
	bresen->dy = -abs(bresen->y1 - bresen->y0);
	bresen->sy = ft_get_step(bresen->y0, bresen->y1);
	bresen->dp1 = bresen->dx + bresen->dy;
	while (1)
	{
		if (bresen->x0 >= 0 && bresen->x0 <= 1920 && bresen->y0 >= 0 && bresen->y0 <= 1080)
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