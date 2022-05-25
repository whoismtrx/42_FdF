#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_graph
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*add;
	int		bpp;
	int		ll;
	int		endian;
}				t_graph;

typedef struct s_data
{
	char	**map;
	int		**z;
	int		**c;
	int		size;
}				t_data;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_read(char *str, int fd);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);

#endif