/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:12:44 by orekabe           #+#    #+#             */
/*   Updated: 2022/05/30 15:12:45 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	**line;
	int		**z;
	int		**c;
	int		x;
	int		y;
}				t_data;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_read(char *str, int fd);
int		ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
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
char	*ft_get_lmap(t_data *data, char *lmap, char **argv);
#endif