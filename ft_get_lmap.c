/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:35:21 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/30 01:22:20 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_get_lmap(char *lmap, char **argv)
{
	int		fd;
	char	*ret;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (1);
	ret = get_next_line(fd);
	lmap = ft_strjoin(lmap, ret);
	while (ret)
	{
		free(ret);
		ret = get_next_line(fd);
		lmap = ft_strjoin(lmap, ret);
	}
	close(fd);
	return (lmap);
}
