/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:15:49 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/13 02:20:40 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_bresen *bresen)
{
	int	px0;
	int	py0;
	int	px1;
	int	py1;

	px0 = bresen->x0;
	px1 = bresen->x1;
	py0 = bresen->y0;
	py1 = bresen->y1;
	bresen->x0 = (px0 - py0) * cos(0.523599);
	bresen->y0 = -bresen->z0 + (px0 + py0) * sin(0.523599);
	bresen->x1 = (px1 - py1) * cos(0.523599);
	bresen->y1 = -bresen->z1 + (px1 + py1) * sin(0.523599);
}
