/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:44:55 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/01 23:43:20 by orekabe          ###   ########.fr       */
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
	// 		printf("%d ",data.c[i][j]);	
	// 	}
	// 	printf("\n");
	// }
}
