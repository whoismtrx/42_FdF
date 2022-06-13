/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:15:49 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/13 04:08:40 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_draw *draw)
{
	int	px0;
	int	py0;
	int	px1;
	int	py1;

	px0 = draw->x0;
	px1 = draw->x1;
	py0 = draw->y0;
	py1 = draw->y1;
	draw->x0 = (px0 - py0) * cos(0.523599);
	draw->y0 = -draw->z0 + (px0 + py0) * sin(0.523599);
	draw->x1 = (px1 - py1) * cos(0.523599);
	draw->y1 = -draw->z1 + (px1 + py1) * sin(0.523599);
}
