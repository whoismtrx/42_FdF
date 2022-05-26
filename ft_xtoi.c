/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 03:19:16 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/26 04:05:49 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	ft_xtoi(const char *str)
{
	long	i;
	long	number;
	int		b;

	i = 0;
	number = 0;
	while (str[i] && str[i] != 'x')
		i++;
	if (str[i] == 'x')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			number = (number * 16) + (str[i] - 48);
		else if (str[i] >= 'a' && str[i] <= 'f')
			number = (number * 16) + (str[i] - 87);
		else if (str[i] >= 'A' && str[i] <= 'F')
			number = (number * 16) + (str[i] - 55);
		i++;
	}
	return (number);
}