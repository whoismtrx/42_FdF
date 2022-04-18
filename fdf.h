#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_data 
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*add;
	int		bpp;
	int		ll;
	int		endian;
}				t_data;

#endif