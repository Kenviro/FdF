/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:52:48 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/12 11:27:54 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map_loop(t_data *data, int fd, char *temp, \
						int lines_allocated)
{
	while (temp != NULL)
	{
		if (data->y >= lines_allocated)
		{
			lines_allocated *= 2;
			data->map = realloc(data->map, lines_allocated * sizeof(char *));
			if (!data->map)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
		}
		data->map[data->y] = ft_strdup(temp);
		if (!data->map[data->y])
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		free(temp);
		data->y++;
		temp = get_next_line(fd);
	}
	data->map[data->y] = NULL;
	close(fd);
}

void	read_map(t_data *data)
{
	char	*temp;
	int		lines_allocated;

	lines_allocated = 5000;
	temp = get_next_line(data->fd);
	data->strlen = ft_strlen(temp);
	if (data->fd == -1)
	{
		perror("Error opening .ber file");
		exit(EXIT_FAILURE);
	}
	data->map = malloc(lines_allocated * sizeof(char *));
	if (!data->map)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	data->y = 0;
	read_map_loop(data, data->fd, temp, lines_allocated);
	validate_map(data);
}
