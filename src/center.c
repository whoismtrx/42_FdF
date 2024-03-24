/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:12:31 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/01 05:49:16 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center(t_draw *draw)
{
	int	cx;
	int	cy;

	cx = WIN_W / 2;
	cy = WIN_H / 2;
	draw->x0 += cx + draw->trans_x;
	draw->y0 += cy + draw->trans_y;
	draw->x1 += cx + draw->trans_x;
	draw->y1 += cy + draw->trans_y;
}
