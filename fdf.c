/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/28 04:40:56 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_map_size(t_data *data, char **argv)
{
	int		fd;
	char	*ret;

	ret = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (1);
	ret = get_next_line(fd);
	while(ret)
	{
		data->y++;
		ret = get_next_line(fd);
	}
}

int	ft_get_line_size(char **line)
{
	int	size;
	int	j;

	size = 0;
	j = 0;
	while (line[j] && line[j][0] != '\n')
		j++;
	return(j);
}

char	*ft_get_lmap(t_data *data, char *lmap, char **argv)
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
		ret = get_next_line(fd);
		lmap = ft_strjoin(lmap, ret);
	}
	// printf("%s", lmap);
	return (lmap);
}

void	ft_fill_data(t_data *data)
{
	int		i;
	int		j;
	int		len;
	char	**line;

	j = 0;
	while (j < data->y)
	{
		i = 0;
		line = ft_split(data->map[j], ' ');
		len = ft_get_line_size(line);
		if (j == 0)
			data->x = len;
		if (j > 0 && len < data->x)
			exit (1);
		data->z[j] = (int *)malloc(sizeof(int) * data->x);
		if (!data->z)
			return ;
		data->c[j] = (int *)malloc(sizeof(int) * data->x);
		if (!data->c)
			return ;
		while (i < data->x)
		{
			data->z[j][i] = ft_atoi(line[i]);
			data->c[j][i] = ft_xtoi(line[i]);
			i++;
		}
		j++;
		free(line);
	}
}

void	ft_allocate(t_data *data, char **argv)
{
	char	*lmap;

	ft_get_map_size(data, argv);
	lmap = (char *)malloc(sizeof(char) * data->y);
	if (!lmap)
		return ;
	lmap = ft_get_lmap(data, lmap, argv);
	data->map = (char **)malloc(sizeof(char *) * data->y);
	if (!data->map)
		return ;
	data->z = (int **)malloc(sizeof(int *) * data->y);
	if (!data->z)
		return ;
	data->c = (int **)malloc(sizeof(int *) * data->y);
	if (!data->c)
		return ;
	data->map = ft_split(lmap, '\n');
	free(lmap);
	ft_fill_data(data);
}

int main(int argc, char **argv)
{
	t_data	data;
	
	if (argc != 2)
		exit (1);
	ft_allocate(&data, argv);
	for(int i = 0; i < data.y; i++){
		for(int j = 0; j < data.x; j++){
			printf("%d ",data.c[i][j]);	
		}
		printf("\n");
	}
}