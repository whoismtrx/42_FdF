/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:28:42 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/13 02:19:05 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_win *win, t_data *data, t_bresen *bresen)
{
	bresen->y = 0;
	while (bresen->y < data->y)
	{
		bresen->x = 0;
		while (bresen->x < data->x)
		{
			if (bresen->x < data->x -1)
				bresenham(data, bresen, win, 1);
			if (bresen->y < data->y -1)
				bresenham(data, bresen, win, 2);
			bresen->x++;
		}
		bresen->y++;
	}
}
