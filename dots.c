/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:56:34 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/12 10:08:08 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_iso_coords(t_data *data)
{
	int	total_points;

	total_points = data->num_lines * data->num_columns;
	data->iso_x = (int *)malloc(sizeof(int) * total_points);
	data->iso_y = (int *)malloc(sizeof(int) * total_points);
	data->map_int = (int *)malloc(sizeof(int) * total_points);
	if (!data->iso_x || !data->iso_y || !data->map_int)
	{
		perror("Memory allocation error for iso coordinates");
		exit(EXIT_FAILURE);
	}
}

void	iso_calcul(t_data *data, int x, int y, int z)
{
	int	index;

	index = y * data->num_columns + x;
	if (z > data->max_z)
		data->max_z = z;
	if (z < data->min_z)
		data->min_z = z;
	data->iso_x[index] = x - y;
	data->iso_y[index] = (x + y) / 2 - z;
}

void	iso_transform(t_data *data)
{
	int	i;
	int	j;
	int	col;
	int	index;

	create_iso_coords(data);
	i = 0;
	while (i < data->num_lines)
	{
		j = -1;
		col = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][++j] == ' ')
				continue ;
			index = i * data->num_columns + col;
			data->map_int[index] = ft_atoi(&data->map[i][j]);
			iso_calcul(data, col, i, data->map_int[index]);
			while (data->map[i][++j] && data->map[i][j] != ' ')
				col++;
		}
		i++;
	}
}
