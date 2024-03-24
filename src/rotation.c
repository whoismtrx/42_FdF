/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 04:07:53 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/03 05:41:55 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	roll(t_draw *draw)
{
	int	py0;
	int	py1;
	int	pz0;
	int	pz1;

	py0 = draw->y0;
	py1 = draw->y1;
	pz0 = draw->z0;
	pz1 = draw->z1;
	draw->y0 = (py0 * cos(draw->g)) - (pz0 * sin(draw->g));
	draw->y1 = (py1 * cos(draw->g)) - (pz1 * sin(draw->g));
	draw->z0 = (py0 * sin(draw->g)) + (pz0 * cos(draw->g));
	draw->z1 = (py1 * sin(draw->g)) + (pz1 * cos(draw->g));
}

void	pitch(t_draw *draw)
{
	int	px0;
	int	px1;
	int	pz0;
	int	pz1;

	px0 = draw->x0;
	px1 = draw->x1;
	pz0 = draw->z0;
	pz1 = draw->z1;
	draw->x0 = (px0 * cos(draw->b)) + (pz0 * sin(draw->b));
	draw->x1 = (px1 * cos(draw->b)) + (pz1 * sin(draw->b));
	draw->z0 = -(px0 * sin(draw->b)) + (pz0 * cos(draw->b));
	draw->z1 = -(px1 * sin(draw->b)) + (pz1 * cos(draw->b));
}

void	yaw(t_draw *draw)
{
	int	px0;
	int	px1;
	int	py0;
	int	py1;

	px0 = draw->x0;
	px1 = draw->x1;
	py0 = draw->y0;
	py1 = draw->y1;
	draw->x0 = (px0 * cos(draw->a)) - (py0 * sin(draw->a));
	draw->x1 = (px1 * cos(draw->a)) - (py1 * sin(draw->a));
	draw->y0 = (px0 * sin(draw->a)) + (py0 * cos(draw->a));
	draw->y1 = (px1 * sin(draw->a)) + (py1 * cos(draw->a));
}

void	rotation(t_draw *draw)
{
	roll(draw);
	pitch(draw);
	yaw(draw);
}
