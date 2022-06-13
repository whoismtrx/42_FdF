/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:18:41 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/13 04:08:40 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	distance(t_draw *draw, t_data *data)
{	
	int	z;
	int	dw;
	int	dm;

	dw = sqrt(pow(1920, 2) + pow(1080, 2));
	dm = sqrt(pow(data->x, 2) + pow(data->y, 2));
	z = ((dw * 30) / 100) / dm;
	if (z < 2)
		z = 2;
	draw->x0 *= z;
	draw->x1 *= z;
	draw->y0 *= z;
	draw->y1 *= z;
	draw->z0 *= z;
	draw->z1 *= z;
	draw->x0 -= (data->x * z) / 2;
	draw->x1 -= (data->x * z) / 2;
	draw->y0 -= (data->y * z) / 2;
	draw->y1 -= (data->y * z) / 2;
}
