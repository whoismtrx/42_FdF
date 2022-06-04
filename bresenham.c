/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:57:24 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/04 02:38:07 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_data *data, t_bresen *bresen)
{
	int	x;
	int	y;
	int	stepx;
	int	stepy;

	x = 0;
	y = 0;
	bresen->dx = data->x - x;
	bresen->dy = data->y - y;
	if (bresen->dy < 0)
	{
		bresen->dy = -bresen->dy;
		stepy = -1;
	}
	else
		stepy = 1;
	if (bresen->dx < 0)
	{
		bresen->dx = -bresen->dx;
		stepx = -1;
	}
	else
		stepx = 1;
	bresen->dy = 2 * bresen->dy;
	bresen->dx = 2 * bresen->dx;
	if ((0 <= x) && (x < )
	while (y < data->y)
	{
		while (x < data->x)
		{
			
		}
		
	}
	
}