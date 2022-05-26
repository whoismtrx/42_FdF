void	ft_fill_data(t_data *data)
{
	int		i;
	int		j;
	int		k;
	int		len;

	j = 0;
	while (j < data->size)
	{
		i = 0;
		k = 0;
		len = ft_get_line_size(data->map[j]);
		data->z[j] = (int *)malloc(sizeof(int) * len);
		if (!data->z)
			return ;
		data->c[j] = (int *)malloc(sizeof(int) * len);
		if (!data->c)
			return ;
		while (data->map[j][k])
		{
			if (ft_isdigit(data->map[j][k]) && !ft_isdigit(data->map[j][k - 1]))
			{					
				data->z[j][i] = ft_atoi(&data->map[j][k]);
				i++;
			}
			k++;
		}
		j++;
	}
}