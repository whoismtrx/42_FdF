/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:12:44 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/01 04:37:53 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# define BUFFER_SIZE 2147483646
# define WIN_W	1920
# define WIN_H	1080

typedef struct s_data
{
	char	**map;
	char	**line;
	int		**z;
	int		**c;
	int		x;
	int		y;
}				t_data;

typedef struct s_draw
{
	int	x;
	int	y;
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	z0;
	int	z1;
	int	dx;
	int	dy;
	int	dp1;
	int	dp2;
	int	sx;
	int	sy;
	int	pro;
	int	dis;
	int zoom;
	int trans_x;
	int trans_y;
}				t_draw;

typedef struct s_win
{
	t_data	*data;
	t_draw	*draw;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*add;
	int		bpp;
	int		ll;
	int		endian;
}				t_win;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_read(char *str, int fd);
int		ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, size_t len);
char	*ft_strdup(const char *src);
int		ft_find_c(char *str, char c);
int		ft_atoi(const char *str);
long	ft_xtoi(const char *str);
int		ft_isdigit(int c);
int		ft_ishexa(int c);
void	ft_put_error(void);
void	ft_free_data(t_data *data, char c);
void	ft_allocate(t_data *data, char **argv);
void	ft_fill_data(t_data *data);
int		ft_get_line_size(char **line);
void	ft_get_map_size(t_data *data, char **argv);
char	*ft_get_lmap(char *lmap, char **argv);
void	my_mlx_pixel_put(t_win *win, int x, int y, int color);
void	bresenham(t_data *data, t_draw *draw, t_win *win, int b);
void	my_mlx_pixel_put(t_win *win, int x, int y, int color);
void	ft_draw_map(t_win *win, t_data *data, t_draw *draw);
void	ft_get_win(t_win *win);
void	init(t_draw *draw, t_data *data, int b);
void	center(t_draw *draw);
void	iso(t_draw *draw);
void	distance(t_draw *draw, t_data *data);

#endif