/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:25:46 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/30 15:15:28 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map(t_data *data, char c)
{
	int		i;
	char	**str;

	i = 0;
	if (c == 'm')
		str = data->map;
	else
		str = data->line;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_zc(t_data *data, char c)
{
	int	i;
	int	**tab;

	i = 0;
	if (c == 'z')
		tab = data->z;
	else
		tab = data->c;
	while (i < data->y)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_data(t_data *data, char c)
{
	int	i;

	i = 0;
	if (c == 'm' || c == 'l')
		ft_free_map(data, c);
	else
		ft_free_zc(data, c);
}
