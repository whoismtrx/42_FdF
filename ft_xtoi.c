/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 03:19:16 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/30 15:17:56 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_minus(char c)
{
	if (c >= '0' && c <= '9')
		return (48);
	else if (c >= 'a' && c <= 'f')
		return (87);
	else if (c >= 'A' && c <= 'F')
		return (55);
	return (0);
}

long	ft_xtoi(const char *str)
{
	long	number;
	int		i;
	int		minus;

	i = 0;
	number = 0;
	while (str[i] && str[i] != ',')
		i++;
	if (str[i + 2] == 'x' || str[i + 2] == 'X')
	{
		if (str[i] == ',')
			i += 3;
		while (str[i])
		{
			minus = ft_get_minus(str[i]);
			number = (number * 16) + (str[i] - minus);
			i++;
		}
	}
	else
		number = ft_atoi(str + i + 1);
	return (number);
}
