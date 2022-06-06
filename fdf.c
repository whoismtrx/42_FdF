/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/06 11:36:40 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_graph *graph, int x, int y, int color)
{
	char	*dst;

	dst = graph->add + (y * graph->ll + x * (graph->bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_graph		graph;
	t_bresen	bresen;

	if (argc != 2)
		exit (1);
	ft_allocate(&data, argv);
	// for(int i = 0; i < data.y; i++){
	// 	for(int j = 0; j < data.x; j++){
	// 		printf("%d ",data.c[i][j]);	
	// 	}
	// 	printf("\n");
	// }
	graph.mlx = mlx_init();
	graph.mlx_win = mlx_new_window(graph.mlx, 500, 500, "FDF");
	graph.img = mlx_new_image(graph.mlx, 500, 500);
	graph.add = mlx_get_data_addr(graph.img, &graph.bpp, &graph.ll, &graph.endian);
	for(int j = 0; j < data.y; j++)
	{
		for(int i = 0; i < data.x; i++)
		{
			bresenham(&data, &bresen, &graph, i * 10, (i + 1) * 10, j * 10, (j + 1) * 10);
			// bresenham(&data, &bresen, &graph, i * 10, i * 10, j * 10, (j + 1)  * 10);
		}
	}
	// bresenham(&data, &bresen, &graph, 100, 100, 300, 100);
	mlx_put_image_to_window(graph.mlx, graph.mlx_win, graph.img, 0, 0);
	// mlx_pixel_put(graph.mlx, graph.mlx_win, 15, 15, 16777215);
	// bresenham(&data, &bresen, &graph, 220, 260, 200, 240);
	// bresenham(&data, &bresen, &graph, 660, 700, 200, 240);
	// bresenham(&data, &bresen, &graph, 220, 120, 200, 660);
	// bresenham(&data, &bresen, &graph, 260, 260, 240, 700);
	mlx_loop(graph.mlx);
	
}
