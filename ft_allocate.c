/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:33:46 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/30 01:22:51 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_allocate(t_data *data, char **argv)
{
	char	*lmap;

	ft_get_map_size(data, argv);
	lmap = (char *)malloc(sizeof(char) * data->y);
	if (!lmap)
		return ;
	lmap = ft_get_lmap(lmap, argv);
	data->map = ft_split(lmap, '\n');
	data->z = (int **)malloc(sizeof(int *) * data->y);
	if (!data->z)
		return ;
	data->c = (int **)malloc(sizeof(int *) * data->y);
	if (!data->c)
		return ;
	free(lmap);
	ft_fill_data(data);
	ft_free_data(data, 'm');
}
