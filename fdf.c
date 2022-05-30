/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/30 15:12:33 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		exit (1);
	ft_allocate(&data, argv);
	// for(int i = 0; i < data.y; i++){
	// 	for(int j = 0; j < data.x; j++){
	// 		printf("%d ",data.z[i][j]);	
	// 	}
	// 	printf("\n");
	// }
	ft_free_data(&data, 'z');
	ft_free_data(&data, 'c');
}
