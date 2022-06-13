/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:18:41 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/13 02:18:06 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	distance(t_bresen *bresen, t_data *data)
{	
	int	z;
	int	dw;
	int	dm;

	dw = sqrt(pow(1920, 2) + pow(1080, 2));
	dm = sqrt(pow(data->x, 2) + pow(data->y, 2));
	z = ((dw * 30) / 100) / dm;
	if (z < 2)
		z = 2;
	bresen->x0 *= z;
	bresen->x1 *= z;
	bresen->y0 *= z;
	bresen->y1 *= z;
	bresen->z0 *= z;
	bresen->z1 *= z;
	bresen->x0 -= (data->x * z) / 2;
	bresen->x1 -= (data->x * z) / 2;
	bresen->y0 -= (data->y * z) / 2;
	bresen->y1 -= (data->y * z) / 2;
}
