/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/09 04:49:51 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_graph *graph, int x, int y, int color)
{
	char	*dst;

	dst = graph->add + (y * graph->ll + x * (graph->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_center(t_data *data, t_bresen *bresen)
{
	bresen->w = 1920;
	bresen->h = 1080;
	bresen->si = (1920 - 200) / data->x;
	int badr = 1720 % data->x;
	bresen->sj = (1080 - 200) / data->y;
}



int	main(int argc, char **argv)
{
	t_data		data;
	t_graph		graph;
	t_bresen	bresen;
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc != 2)
		exit (1);
	ft_allocate(&data, argv);
	graph.mlx = mlx_init();
	graph.mlx_win = mlx_new_window(graph.mlx, 1920, 1080, "FDF");
	graph.img = mlx_new_image(graph.mlx, 1920, 1080);
	graph.add = mlx_get_data_addr(graph.img, &graph.bpp, &graph.ll, &graph.endian);
	while(j < data.y)
	{
		i = 0;
		while (i < data.x)
		{
			if (i < data.x -1)
				bresenham(&data, &bresen, &graph, i, i + 1, j, j);
			if (j < data.y -1)
				bresenham(&data, &bresen, &graph, i, i, j, j + 1);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(graph.mlx, graph.mlx_win, graph.img, 0, 0);
	mlx_loop(graph.mlx);
}