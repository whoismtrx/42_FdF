/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/26 04:30:44 by orekabe          ###   ########.fr       */
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
	while(ret)
	{
		data->y++;
		ret = get_next_line(fd);	
	}
}

int	ft_get_line_size(char **line)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	j = 0;
	while (line[j] && line[j][0] != '\n')
		j++;
	return(j);
}

void	ft_fill_map(t_data *data, char **argv)
{
	int		i;
	int		j;
	int		fd;
	int		len;
	char	*ret;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (1);
	ret = get_next_line(fd);
	j = 0;
	while (ret)
	{
		i = 0;
		len = ft_strlen(ret);
		data->map[j] = (char *)malloc(sizeof(char) * len);
		if (!data->map[i])
			return ;
		while (i < len)
		{
			data->map[j][i] = ret[i];
			i++;
		}
		ret = get_next_line(fd);
		j++;
	}	
}


void	ft_fill_data(t_data *data)
{
	int		i;
	int		j;
	int		len;
	int		b;
	char	**line;

	j = 0;
	b = 1;
	while (j < data->y)
	{
		i = 0;
		line = ft_split(data->map[j], ' ');
		// for(int k = 0; line[k]; k++){
		// 	printf("%s", line[k]);
		// }
		len = ft_get_line_size(line);
		// printf("|%d|",len);
		if (i == 0 && b)
		{
			data->x = len;
			b = 0;
		}
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
	}
}

void	ft_allocate_map(t_data *data, char **argv)
{
	ft_get_map_size(data, argv);
	data->map = (char **)malloc(sizeof(char *) * data->y);
	if (!data->map)
		return ;
	data->z = (int **)malloc(sizeof(int *) * data->y);
	if (!data->z)
		return ;
	data->c = (int **)malloc(sizeof(int *) * data->y);
	if (!data->c)
		return ;
	ft_fill_map(data, argv);
	ft_fill_data(data);
}

int main(int argc, char **argv)
{
	t_data	data;
	
	ft_allocate_map(&data, argv);
	for(int i = 0; i < data.y; i++){
			// printf("|%d|", ft_get_line_size(ft_split(data.map[i], ' ')));
		for(int j = 0; j < data.x; j++){
			printf("%d ",data.z[i][j]);	
		}
		printf("\n");
	}
}