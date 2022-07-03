/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:11:30 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/03 05:44:52 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_step(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

void	get_val(t_draw *draw, t_data *data, int b)
{
	if (b == 1)
	{
		draw->x0 = draw->x;
		draw->x1 = draw->x + 1;
		draw->y0 = draw->y;
		draw->y1 = draw->y;
	}
	else
	{
		draw->x0 = draw->x;
		draw->x1 = draw->x;
		draw->y0 = draw->y;
		draw->y1 = draw->y + 1;
	}
	draw->z0 = data->z[draw->y0][draw->x0];
	draw->z1 = data->z[draw->y1][draw->x1];
}

void	init(t_draw *draw, t_data *data, int b)
{
	get_val(draw, data, b);
	if (draw->alt)
	{
		draw->z0 *= draw->z;
		draw->z1 *= draw->z;
	}
	distance(draw, data);
	if (draw->rot)
		rotation(draw);
	if (draw->pro)
		iso(draw);
	center(draw);
	draw->dx = abs(draw->x1 - draw->x0);
	draw->sx = ft_get_step(draw->x0, draw->x1);
	draw->dy = -abs(draw->y1 - draw->y0);
	draw->sy = ft_get_step(draw->y0, draw->y1);
	draw->dp1 = draw->dx + draw->dy;
}
