/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:36:47 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/30 15:16:45 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_map_size(t_data *data, char **argv)
{
	int		fd;
	char	*ret;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (1);
	ret = get_next_line(fd);
	while (ret)
	{
		data->y++;
		if (ret[0] == '\n')
			ft_put_error();
		free(ret);
		ret = get_next_line(fd);
	}
	close(fd);
}
