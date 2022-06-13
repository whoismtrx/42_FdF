/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:12:31 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/13 02:17:10 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center(t_bresen *bresen, t_data *data)
{
	int	cx;
	int	cy;

	cx = WIN_W / 2;
	cy = WIN_H / 2;
	bresen->x0 += cx;
	bresen->y0 += cy;
	bresen->x1 += cx;
	bresen->y1 += cy;
}
