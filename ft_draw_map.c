/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:28:42 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/01 05:15:47 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_win *win, t_data *data, t_draw *draw)
{
	draw->y = 0;
	while (draw->y < data->y)
	{
		draw->x = 0;
		while (draw->x < data->x)
		{
			if (draw->x < data->x - 1)
				bresenham(data, draw, win, 1);
			if (draw->y < data->y - 1)
				bresenham(data, draw, win, 2);
			draw->x++;
		}
		draw->y++;
	}
}
