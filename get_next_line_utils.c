/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:38:54 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/12 15:48:38 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	len(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str && str[i] != '\0')
// 		i++;
// 	return (i);
// }

// int	check_next_ln(char *curr)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = 0;
// 	while (curr && curr[i])
// 	{
// 		if (curr[i] == '\n')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	int		k;
// 	int		j;
// 	char	*a;

// 	i = len(s1) + len(s2);
// 	j = 0;
// 	k = 0;
// 	a = malloc(i + 1);
// 	if (a == 0)
// 		return (0);
// 	while (s1 && s1[j] != '\0')
// 	{
// 		a[j] = s1[j];
// 		j++;
// 	}
// 	while (s2 && s2[k] != '\0')
// 		a[j++] = s2[k++];
// 	a[j] = '\0';
// 	if (s1)
// 		free (s1);
// 	return (a);
// }

// int	new_line_index(char	*all)
// {
// 	int	i;

// 	i = 0;
// 	while (all && all[i] != '\0' && all[i] != '\n')
// 		i++;
// 	if (all && all[i] == '\n')
// 		i++;
// 	return (i);
// }