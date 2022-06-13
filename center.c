/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:12:31 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/13 04:08:40 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center(t_draw *draw, t_data *data)
{
	int	cx;
	int	cy;

	cx = WIN_W / 2;
	cy = WIN_H / 2;
	draw->x0 += cx;
	draw->y0 += cy;
	draw->x1 += cx;
	draw->y1 += cy;
}
