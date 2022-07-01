/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:18:41 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/01 04:22:29 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	distance(t_draw *draw, t_data *data)
{	
	int	dw;
	int	dm;

	dw = sqrt(pow(1920, 2) + pow(1080, 2));
	dm = sqrt(pow(data->x, 2) + pow(data->y, 2));
	if (!draw->zoom)
		draw->dis = ((dw * 30) / 100) / dm;
	if (draw->dis < 2 && !draw->zoom)
		draw->dis = 2;
	draw->x0 *= draw->dis;
	draw->x1 *= draw->dis;
	draw->y0 *= draw->dis;
	draw->y1 *= draw->dis;
	draw->z0 *= draw->dis;
	draw->z1 *= draw->dis;
	draw->x0 -= (data->x * draw->dis) / 2;
	draw->x1 -= (data->x * draw->dis) / 2;
	draw->y0 -= (data->y * draw->dis) / 2;
	draw->y1 -= (data->y * draw->dis) / 2;
}
