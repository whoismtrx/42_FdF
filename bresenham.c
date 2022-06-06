/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:57:24 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/05 21:13:07 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_data *data, t_bresen *bresen, t_graph *graph, int x0, int x1, int y0, int y1)
{
	int x;
	int y;
	int	p;

	x = x0;
	y = y0;
	bresen->dx = x1 - x0;
	bresen->dy = y1 - y0;
	p = 2*bresen->dy-bresen->dx;
	while (x <= x1)
	{
		if (p >= 0)
		{
			my_mlx_pixel_put(graph, x, y, 16777215);
			y = y + 1;
			p = p + 2 * bresen->dy - 2 * bresen->dx;
		}
		else
		{
			my_mlx_pixel_put(graph, x, y, 16777215);
			p = p + 2 * bresen->dy;
		}
		x++;
	}
}