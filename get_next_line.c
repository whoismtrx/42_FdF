/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:00:58 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/12 15:49:14 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	check_next_ln(char *curr)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (curr && curr[i])
	{
		if (curr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	int		j;
	char	*a;

	i = len(s1) + len(s2);
	j = 0;
	k = 0;
	a = malloc(i + 1);
	if (a == 0)
		return (0);
	while (s1 && s1[j] != '\0')
	{
		a[j] = s1[j];
		j++;
	}
	while (s2 && s2[k] != '\0')
		a[j++] = s2[k++];
	a[j] = '\0';
	if (s1)
		free (s1);
	return (a);
}

int	new_line_index(char	*all)
{
	int	i;

	i = 0;
	while (all && all[i] != '\0' && all[i] != '\n')
		i++;
	if (all && all[i] == '\n')
		i++;
	return (i);
}
int	cpy_next_line(char **all, int fd)
{
	char	*curr;
	int		i;
	int		j;

	i = 0;
	j = 1;
	curr = malloc(BUFFER_SIZE + 1);
	while (i == 0 && j != 0)
	{
		j = read(fd, curr, BUFFER_SIZE);
		if (j == -1)
		{
			free (curr);
			return (0);
		}
		if (j == 0)
			break ;
		curr[j] = '\0';
		*all = ft_strjoin(*all, curr);
		i = check_next_ln(*all);
	}
	free (curr);
	return (1);
}

char	*ft_return(char *all, int i)
{
	int		k;
	char	*ret;

	k = 0;
	ret = malloc (i + 1);
	while (all && all[k] && all[k] != '\n')
	{
		ret[k] = all[k];
		k++;
	}
	if (all[k] == '\n')
		ret[k++] = '\n';
	ret[k] = '\0';
	return (ret);
}

char	*edit_all(char *all, int i, int k)
{
	int		p;
	char	*tmp;

	if (len (all) - i)
	{
		tmp = malloc (len (all) + 1);
		while (all && all[++k])
			tmp[k] = all[k];
		tmp[k] = '\0';
		p = len (all);
		free (all);
		all = malloc (p - i + 1);
		k = 0;
		while (tmp[i])
			all[k++] = tmp[i++];
		all[k] = '\0';
		free (tmp);
	}
	else
	{
		free (all);
		all = NULL;
	}
	return (all);
}

char	*get_next_line(int fd)
{
	static char	*all;
	char		*ret;
	int			i;
	int			k;

	k = 0;
	i = cpy_next_line(&all, fd);
	if (i == 0)
	{
		free (all);
		return (NULL);
	}
	i = new_line_index(all);
	if (i == 0)
	{
		free (all);
		return (NULL);
	}
	ret = ft_return (all, i);
	k = -1;
	all = edit_all(all, i, k);
	return (ret);
}