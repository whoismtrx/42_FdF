/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:34:34 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/30 17:21:10 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_zc(t_data *data, int j)
{
	int	i;

	i = 0;
	data->z[j] = (int *)malloc(sizeof(int) * data->x);
	if (!data->z)
		return ;
	data->c[j] = (int *)malloc(sizeof(int) * data->x);
	if (!data->c)
		return ;
	while (i < data->x)
	{
		data->z[j][i] = ft_atoi(data->line[i]);
		if (ft_find_c(data->line[i], ','))
			data->c[j][i] = ft_xtoi(data->line[i]);
		else
			data->c[j][i] = 16777215;
		i++;
	}
}

void	ft_fill_data(t_data *data)
{
	int		j;
	int		len;

	j = 0;
	while (j < data->y)
	{
		data->line = ft_split(data->map[j], ' ');
		len = ft_get_line_size(data->line);
		if (j == 0)
			data->x = len;
		if (j > 0 && len < data->x)
			ft_put_error();
		ft_fill_zc(data, j);
		j++;
		ft_free_data(data, 'l');
	}
}
