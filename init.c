/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:11:30 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/13 02:20:20 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_step(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

void	init(t_bresen *bresen, t_data *data, int b)
{
	if (b == 1)
	{
		bresen->x0 = bresen->x;
		bresen->x1 = bresen->x + 1;
		bresen->y0 = bresen->y;
		bresen->y1 = bresen->y;
	}
	else
	{
		bresen->x0 = bresen->x;
		bresen->x1 = bresen->x;
		bresen->y0 = bresen->y;
		bresen->y1 = bresen->y + 1;
	}
	bresen->z0 = data->z[bresen->y0][bresen->x0];
	bresen->z1 = data->z[bresen->y1][bresen->x1];
	distance(bresen, data);
	iso(bresen);
	center(bresen, data);
	bresen->dx = abs(bresen->x1 - bresen->x0);
	bresen->sx = ft_get_step(bresen->x0, bresen->x1);
	bresen->dy = -abs(bresen->y1 - bresen->y0);
	bresen->sy = ft_get_step(bresen->y0, bresen->y1);
	bresen->dp1 = bresen->dx + bresen->dy;
}
