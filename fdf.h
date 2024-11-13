/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:32:05 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/12 11:27:27 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFFER_SIZE 1234

# include "minilibx_opengl/mlx.h"
# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		fd;
	int		strlen;
	int		y;
	int		max_z;
	int		min_z;
	int		num_lines;
	int		num_columns;
	int		*iso_x;
	int		*iso_y;
	int		**map_int;
	char	**map;
}	t_data;

void	read_map(t_data *data);
int		close_window(t_data *data);
int		key_hook(int keycode, t_data *data);
int		validate_map(t_data *data);
char	*get_next_line(int fd);

#endif
