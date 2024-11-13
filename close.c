/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:01:54 by ktintim-          #+#    #+#             */
/*   Updated: 2024/11/08 09:50:36 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_ressources(t_data *data)
{
	data->win = NULL;
	data->mlx = NULL;
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_ressources(data);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}
