/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:18:48 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/27 01:11:31 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

static int	count_word(char const *str, char c)
{
	int	i;
	int	count;
	int	j;

	j = 0;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && j == 0)
		{
			count++;
			j = 1;
		}
		else if (str[i] == c && j == 1)
			j = 0;
		i++;
	}
	return (count);
}

static int	count_char(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[count] != c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**ptr;
	int		len;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	len = count_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!ptr)
		return (NULL);
	while (++i < len)
	{
		while (*s == c)
			s++;
		j = count_char(s, c);
		ptr[i] = ft_substr(s, 0, j);
		if (!ptr)
			ft_free(ptr, i);
		s += j;
	}
	ptr[i] = NULL;
	return (ptr);
}
