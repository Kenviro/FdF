/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:23:09 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/12 11:27:06 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_columns(const char *line)
{
	int	columns;
	int	i;

	columns = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i])
		{
			columns++;
			while (line[i] && line[i] != ' ')
				i++;
		}
	}
	return (columns);
}

int	validate_map(t_data *data)
{
	int	current_columns;
	int	i;

	if (!data->map || !data->map[0])
		return (0);
	data->num_columns = count_columns(data->map[0]);
	data->num_lines = 0;
	i = 0;
	while (data->map[i])
	{
		current_columns = count_columns(data->map[i]);
		if (current_columns != data->num_columns)
		{
			perror("Invalid map");
			exit (EXIT_FAILURE);
		}
		data->num_lines++;
		i++;
	}
	return (1);
}
