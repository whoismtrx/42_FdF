/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/25 01:10:58 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_map_size(t_data *data, char **argv)
{
	int		fd;
	char	*ret;

	fd = open(argv[1], O_RDONLY);
	ret = get_next_line(fd);
	while(ret)
	{
		data->size++;
		ret = get_next_line(fd);	
	}
}

int	ft_get_line_size(char *line)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' && (line[i + 1] >= '0' && line[i + 1] <= '9'))
			size++;
		i++;
	}
	return(size + 1);
}

int	ft_get_z(t_data *data)
{
	static int	i;
	static int	j;
	static int	lj;
	static int	b;
	int			val;

	j = 0;
	lj = 0;
	b = 1;
	while (j < data->size)
	{
		if (j != lj)
		{
			lj = j;
			i = 0;
		}
		while (data->map[j][i])
		{
			if (data->map[j][i] == ' ')
			{
				b = 1;
				i++;
			}
			if ((data->map[j][i] >= '0' && data->map[j][i] <= '9') && b)
			{
				b = 0;
				val = ft_atoi(&data->map[j][i]);
				return (val);
			}
			i++;
		}
		j++;
	}
	return (0);	
}

void	ft_fill_map(t_data *data, char **argv)
{
	int		i;
	int		j;
	int		fd;
	int		len;
	char	*ret;
	
	fd = open(argv[1], O_RDONLY);
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

	j = 0;
	while (j < data->size)
	{
		i = 0;
		len = ft_get_line_size(data->map[j]);
		data->z[j] = (int *)malloc(sizeof(int) * len);
		if (!data->z)
			return ;
		data->c[j] = (int *)malloc(sizeof(int) * len);
		if (!data->c)
			return ;
		while (i < len)
		{
			data->c[j][i] = ft_get_z(data);
			i++;
		}
		j++;
	}
}

void	ft_allocate_map(t_data *data, char **argv)
{
	ft_get_map_size(data, argv);
	data->map = (char **)malloc(sizeof(char *) * data->size);
	if (!data->map)
		return ;
	data->z = (int **)malloc(sizeof(int *) * data->size);
	if (!data->z)
		return ;
	data->c = (int **)malloc(sizeof(int *) * data->size);
	if (!data->c)
		return ;
	ft_fill_map(data, argv);
	ft_fill_data(data);
}

int main(int argc, char **argv)
{
	t_data	data;
	
	ft_allocate_map(&data, argv);
	for(int i = 0; i < data.size; i++){
		for(int j = 0; j < ft_get_line_size(data.map[i]); j++){
			printf("%d",data.z[i][j]);	
		}
		printf("\n");
	}
}